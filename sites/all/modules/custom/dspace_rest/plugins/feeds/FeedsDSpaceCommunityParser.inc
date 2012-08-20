<?php

/**
 * @file
 * Feeds DSpace parser
 */

/**
 * Class definition for DSpace Community Parser.
 *
 * @todo Abstract a FeedsDSpaceRestParser for use by this class and by a
 * hypothetical FeedsDSpaceCollectionParser class
 *
 * @todo Deal with simplexml_load_string warnings caused by characters it
 * doesn't like, i.e. â, é, et. al. Is there a different library to use?
 *
 * @todo Replace embryo:<number> links in the X(HT)ML bitstreams with links to
 * the proper Drupal node. This might be impossible, since it's possible these
 * links point to nodes that haven't been created yet. Alternately, they can
 * almost definitely be turned into links to the item in DSpace, since we
 * already know that.
 *
 * @todo Add a function for DC metadata processing.
 */
class FeedsDSpaceCommunityParser extends FeedsParser {

  // An array of the Feed source URL as returned from parse_url()
  protected $community_url;

  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = new FeedsParserResult();

    // @todo Can this be pushed to a __construct function?
    $this->community_url = parse_url($source->config['FeedsDSpaceCommunityFetcher']['source']);

    // Rough estimates from importing 1471 items from 2012-07-25 suggest
    // it takes ca 512MB to get to this point, and obscene amounts of memory
    // past this point. 2GB will not import the entire 1471 items, for
    // example, but around 150 if the items are mostly images, and around 200
    // if the items are a mixture of images and text.
    ini_set('memory_limit', '2G');
    $json = json_decode($fetcher_result->getRaw());

    if ((json_last_error() == JSON_ERROR_NONE) && ($json instanceof stdClass)) {
      if (property_exists($json, 'harvest_collection')) {
        foreach ($json->harvest_collection as $index => $item) {
          // The harvest collection item with an index of zero appears to be
          // an informational/status item with the number of results, for
          // example.
          if ($index == 0) {
            // @todo Does the resultsCount include itself? i.e. is there a
            // possible off-by-one issue here?
            $dspace_result_count = $item->resultsCount;
          }
          else {
            // @todo Since the import process consumes so much memory, it
            // would be nice to check if a node has already been created from
            // this $item, and if the node has been updated in Drupal since
            // the last modified date on the $item, to skip parsing it,
            // assuming that a previous import has crashed after processing
            // this particular $item
            // Get rid of $item contents that won't be needed for the import
            unset($item->bundles);
            unset($item->canEdit);
            unset($item->collections);
            unset($item->communities);
            unset($item->owningCollection);
            $result->items[] = $this->parseDSpaceItem($item);
          }
          unset($json->harvest_collection[$index]);
        }
      }
      // @todo Handle json_last_error() != JSON_ERROR_NONE
    }
    unset($json);

    if ($dspace_result_count) {
      if ($dspace_result_count > count($result->items)) {
        $message = 'DSpace returned @results items, but only @parsed were parsed out.';
        $variables = array(
          '@results' => $dspace_result_count,
          '@parsed' => count($result->items),
        );
        watchdog('dspace_rest', $message, $variables);
      }
    }
    return $result;
  }

  protected function parseDSpaceItem(stdClass $item) {
    $publication['guid'] = (string) $item->handle;
    $publication['id'] = $item->id;
    // Timestamp includes milliseconds
    $publication['changed'] = substr($item->lastModified, 0, -3);

    $publication['title'] = $item->name;
    $publication['dspace.link'] = $this->community_url['scheme'] . '://' . $this->community_url['host'] . '/handle/' . $item->handle;

    // Dublin Core Metadata.
    foreach ($item->metadata as $metadata) {
      if ($metadata->qualifier) {
        $publication[$metadata->schema . '.' . $metadata->element . '.' . $metadata->qualifier][] =  $metadata->value;
      }
      else {
        $publication[$metadata->schema . '.' . $metadata->element][] =  $metadata->value;
      }
      // The DC spec suggests that qualified element values should be usable
      // as the unqualified element value in the absence of an
      // explicitly unqualified element. We rely on this principle for certain
      // metadata elements.
      // @see "The Dumb-Down Principle for Qualifiers"
      // @note This implementation uses the first qualified element
      // value found as the unqualified element value. This may not be
      // appropriate behavior.
      if (empty($publication[$metadata->schema . '.' . $metadata->element])) {
        switch ($metadata->element) {
          case 'rights':
            $publication[$metadata->schema . '.' . $metadata->element][] =  $metadata->value;
            break;
        }
      }
    }
    unset($item->metadata);

    // Embryo qualified DC Subjects should not also appear in the unqualified
    // DC Subjects
    if (isset($publication['dc.subject.embryo']) && isset($publication['dc.subject'])) {
      foreach ($publication['dc.subject.embryo'] as $index => $subject_embryo) {
        $subject_index = array_search($subject_embryo, $publication['dc.subject']);
        // $subject_index can be 0, a valid array index, and therefore
        // incorrectly return FALSE when used in "if ($subject_index)"
        if (isset($subject_index)) {
          unset($publication['dc.subject'][$subject_index]);
          unset($subject_index);
        }
      }
    }

    foreach ($item->bitstreams as $bitstream) {
      $bitstream_url = $this->getBitstreamHandle($bitstream, $item->handle);
      $path = parse_url($bitstream_url, PHP_URL_PATH);
      $extension = pathinfo($path, PATHINFO_EXTENSION);
      // For certain DSpace item types, we want to get the associated X(HT)ML
      // bitstream for use as the node body.
      if (isset($publication['dc.format.medium']) && (in_array('text/xhtml', $publication['dc.format.medium']) && $extension == 'xhtml')) {
        $publication['body'] = $this->getDSpaceXMLBitstream($bitstream_url);
      }
      // We can't rely on $publication['dc.format'] to tell us if an bitstream
      // is an image derivate since it describes the main artifact, not each
      // bitstream.
      // @todo DSpace appears to set metadata on each bitstream that indicates
      // if that bitstream is a derivate
      else if (in_array('StillImage', $publication['dc.type']) && preg_match('/\.web\.jpg/', $bitstream_url)) {
        $publication['image'] = new FeedsEnclosure($bitstream_url, 'image/jpeg');
      }

      // Provide the bitstream URLs themselves to the Processor
      $publication['bitstreams'][] = $bitstream_url;
    }
    unset($item->bitstreams);

    return $publication;
  }

  /*
   * Get a Bitstream handle
   *
   * DSpace bitstream URLs appear to be:
   * <repository base scheme and hostname>/bitstream/handle/<handle of item>/<filename>?sequence=<#>
   * where <#> is indeterminate
   */
  protected function getBitstreamHandle($bitstream, $item_handle) {
    $bitstream_handle = $this->community_url['scheme'] . '://' . $this->community_url['host'];
    $bitstream_handle .= '/bitstream/handle/' . $item_handle . '/' . $bitstream->name;

    return $bitstream_handle;
  }

  /**
   * Get the contents of a DSpace X(HT)ML bitstream
   *
   * @todo Use simplexml_load_file(<some url>) instead of making our own HTTP
   * request? Or use some of Feeds' http functions from
   * feeds/libraries/http_request.inc?
   */
  protected function getDSpaceXMLBitstream($bitstream) {
    $request = drupal_http_request($bitstream);
    if (!property_exists($request, 'error')) {
      $xhtml = simplexml_load_string(html_entity_decode($request->data));
      if ($xhtml) {
        return check_markup((string) $xhtml->body->asXML(), 'full_html');
      }
    }
  }

  /**
   * Implements FeedsParser::getMappingSources().
   */
  public function getMappingSources() {
    return parent::getMappingSources() + array(
      'guid' => array(
        'name' => t('GUID'),
        'description' => t('Global Unique Identifier of the item in DSpace.'),
      ),
      'id' => array(
        'name' => t('ID'),
        'description' => t('DSpace artifact numeric ID'),
      ),
      'title' => array(
        'name' => t('Title'),
        'description' => t('Title of a DSpace artifact'),
      ),
      'changed' => array(
        'name' => t('Last Modified'),
        'description' => t('Last Modified time of a DSpace artifact'),
      ),
      'dspace.link' => array(
        'name' => t('DSpace Link'),
        'description' => t('URL of a DSpace artifact'),
      ),

      // DSpace Bitstreams
      'bitstreams' => array(
        'name' => t('DSpace Bitstreams'),
        'description' => t('The URLs of bitstreams associated with a DSpace artifact'),
      ),
      'body' => array(
        'name' => t('DSpace Body'),
        'description' => t('The body of an DSpace text item'),
      ),
      'image' => array(
        'name' => t('DSpace Image'),
        'description' => t('The image from a DSpace StillImage item'),
      ),

      // Dublin Core Metadata
      'dc.contributor' => array(
        'name' => t('DC Contributor'),
      ),
      'dc.contributor.editor' => array(
        'name' => t('DC Contributor Editor'),
      ),
      'dc.contributor.illustrator' => array(
        'name' => t('DC Contributor Illustrator'),
      ),
      'dc.contributor.interviewee' => array(
        'name' => t('DC Contributor Interviewee'),
      ),
      'dc.contributor.interviewer' => array(
        'name' => t('DC Contributor Interviewer'),
      ),
      'dc.contributor.narrator' => array(
        'name' => t('DC Contributor Narrator'),
      ),
      'dc.contributor.photographer' => array(
        'name' => t('DC Contributor Photographer'),
      ),
      'dc.contributor.correspondent' => array(
        'name' => t('DC Contributor Correspondent'),
      ),
      'dc.contributor.speaker' => array(
        'name' => t('DC Contributor Speaker'),
      ),
      'dc.contributor.translator' => array(
        'name' => t('DC Contributor Translator'),
      ),
      'dc.contributor.videographer' => array(
        'name' => t('DC Contributor Videographer'),
      ),
      'dc.coverage' => array(
        'name' => t('DC Coverage'),
      ),
      'dc.coverage.spatial' => array(
        'name' => t('DC Coverage Spacial'),
      ),
      'dc.coverage.temporal' => array(
        'name' => t('DC Coverage Temporal'),
      ),
      'dc.creator' => array(
        'name' => t('DC Creator'),
      ),
      'dc.date' => array(
        'name' => t('DC Date'),
      ),
      'dc.date.created' => array(
        'name' => t('DC Date Created'),
      ),
      'dc.description' => array(
        'name' => t('DC Description'),
      ),
      'dc.description.abstract' => array(
        'name' => t('DC Description Abstract'),
      ),
      'dc.description.tableofcontents' => array(
        'name' => t('DC Description Table of Contents'),
      ),
      'dc.description.type' => array(
        'name' => t('DC Description Type'),
      ),
      'dc.format' => array(
        'name' => t('DC Format'),
      ),
      'dc.format.extent' => array(
        'name' => t('DC Format Extent'),
      ),
      'dc.format.medium' => array(
        'name' => t('DC Format Medium'),
      ),
      'dc.identifier' => array(
        'name' => t('DC Identifier'),
      ),
      'dc.identifier.citation' => array(
        'name' => t('DC Identifier Citation'),
      ),
      'dc.identifier.issn' => array(
        'name' => t('DC Identifier ISSN'),
      ),
      'dc.identifier.uri' => array(
        'name' => t('DC Identifier URI'),
      ),
      'dc.language' => array(
        'name' => t('DC Language'),
      ),
      'dc.publisher' => array(
        'name' => t('DC Publisher'),
      ),
      'dc.publisher.digital' => array(
        'name' => t('DC Publisher Digital'),
      ),
      'dc.publisher.original' => array(
        'name' => t('DC Publisher Original'),
      ),
      'dc.relation.hasformat' => array(
        'name' => t('DC Relation Has Format'),
      ),
      'dc.relation.haspart' => array(
        'name' => t('DC Relation Has Part'),
      ),
      'dc.relation.hasversion' => array(
        'name' => t('DC Relation Has Version'),
      ),
      'dc.relation.isformatof' => array(
        'name' => t('DC Relation Is Format Of'),
      ),
      'dc.relation.ispartof' => array(
        'name' => t('DC Relation Is Part Of'),
      ),
      'dc.relation.isversionof' => array(
        'name' => t('DC Relation Is Version Of'),
      ),
      'dc.rights' => array(
        'name' => t('DC Rights'),
      ),
      'dc.rights.copyright' => array(
        'name' => t('DC Rights Copyright'),
      ),
      'dc.rights.holder' => array(
        'name' => t('DC Rights Holder'),
      ),
      'dc.rights.license' => array(
        'name' => t('DC Rights License'),
      ),
      'dc.rights.uri' => array(
        'name' => t('DC Rights URI'),
      ),
      'dc.source' => array(
        'name' => t('DC Source'),
      ),
      'dc.subject' => array(
        'name' => t('DC Subject'),
      ),
      'dc.subject.embryo' => array(
        'name' => t('DC Embryo Subject'),
      ),
      'dc.subject.lcsh' => array(
        'name' => t('DC Subject LCSH'),
      ),
      'dc.subject.mblhistory' => array(
        'name' => t('DC Subject MBL History'),
      ),
      'dc.subject.mesh' => array(
        'name' => t('DC Subject Mesh'),
      ),
      'dc.subject.tag' => array(
        'name' => t('DC Subject Tag'),
      ),
      'dc.type' => array(
        'name' => t('DC Type'),
      ),
      'dc.title' => array(
        'name' => t('DC Title'),
      ),
      'dc.title.alternative' => array(
        'name' => t('DC Title Alternative'),
      ),
    );
  }
}
