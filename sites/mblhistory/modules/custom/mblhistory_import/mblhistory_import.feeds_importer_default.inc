<?php
/**
 * @file
 * mblhistory_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mblhistory_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'mblhistory_dspace';
  $feeds_importer->config = array(
    'name' => 'MBL History DSpace',
    'description' => 'MBL DSpace Community Import',
    'fetcher' => array(
      'plugin_key' => 'FeedsDSpaceCommunityFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsDSpaceCollectionParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'dspace_item',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'bitstreams',
            'target' => 'field_dspace_bitstreams:url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'dc.description',
            'target' => 'field_dspace_description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'dc.publisher',
            'target' => 'field_dspace_publisher',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'dc.format',
            'target' => 'field_dspace_format',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'dc.identifier',
            'target' => 'field_dspace_identifier',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'dc.rights',
            'target' => 'field_dspace_rights',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          8 => array(
            'source' => 'dc.creator',
            'target' => 'field_dspace_creator',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'dspace.link',
            'target' => 'field_dspace_link:url',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'id',
            'target' => 'field_dspace_id',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'dc.date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'changed',
            'target' => 'field_dspace_last_modified:start',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'dc.type',
            'target' => 'field_dc_type',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'dc.subject.embryo',
            'target' => 'field_dc_subject_embryo',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'dc.relation.ispartof',
            'target' => 'field_dc_relation_ispartof',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'dc.description.type',
            'target' => 'field_dc_description_type',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'image',
            'target' => 'field_dspace_image',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'dc.date.created',
            'target' => 'field_dc_date_created',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'dc.contributor',
            'target' => 'field_dc_contributor',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'dc.contributor.correspondent',
            'target' => 'field_dc_contributor_corresponde',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'dc.contributor.editor',
            'target' => 'field_dc_contributor_editor',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'dc.contributor.illustrator',
            'target' => 'field_dc_contributor_illustrator',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'dc.contributor.interviewer',
            'target' => 'field_dc_contributor_interviewer',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'dc.contributor.narrator',
            'target' => 'field_dc_contributor_narrator',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'dc.contributor.photographer',
            'target' => 'field_dc_contributor_photographe',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'dc.contributor.speaker',
            'target' => 'field_dc_contributor_speaker',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'dc.contributor.translator',
            'target' => 'field_dc_contributor_translator',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'dc.contributor.videographer',
            'target' => 'field_dc_contributor_videographe',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'dc.coverage',
            'target' => 'field_dc_coverage',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'dc.coverage.spatial',
            'target' => 'field_dc_coverage_spacial',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'dc.date',
            'target' => 'field_dc_date',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'dc.description.abstract',
            'target' => 'field_dc_description_abstract',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'dc.format.extent',
            'target' => 'field_dc_format_extent',
            'unique' => FALSE,
          ),
          35 => array(
            'source' => 'dc.format.medium',
            'target' => 'field_dc_format_medium',
            'unique' => FALSE,
          ),
          36 => array(
            'source' => 'dc.identifier.citation',
            'target' => 'field_dc_identifier_citation',
            'unique' => FALSE,
          ),
          37 => array(
            'source' => 'dc.identifier.issn',
            'target' => 'field_dc_identifier_issn',
            'unique' => FALSE,
          ),
          38 => array(
            'source' => 'dc.identifier.uri',
            'target' => 'field_dc_identifier_uri:url',
            'unique' => FALSE,
          ),
          39 => array(
            'source' => 'dc.language',
            'target' => 'field_dspace_language',
            'unique' => FALSE,
          ),
          40 => array(
            'source' => 'dc.publisher.digital',
            'target' => 'field_dc_publisher_digital',
            'unique' => FALSE,
          ),
          41 => array(
            'source' => 'dc.publisher.original',
            'target' => 'field_dc_publisher_original',
            'unique' => FALSE,
          ),
          42 => array(
            'source' => 'dc.relation.hasformat',
            'target' => 'field_dc_relation_hasformat',
            'unique' => FALSE,
          ),
          43 => array(
            'source' => 'dc.relation.haspart',
            'target' => 'field_dc_relation_haspart',
            'unique' => FALSE,
          ),
          44 => array(
            'source' => 'dc.relation.hasversion',
            'target' => 'field_dc_relation_hasversion',
            'unique' => FALSE,
          ),
          45 => array(
            'source' => 'dc.relation.isformatof',
            'target' => 'field_dc_relation_isformatof',
            'unique' => FALSE,
          ),
          46 => array(
            'source' => 'dc.relation.ispartof',
            'target' => 'field_dc_relation_ispartof',
            'unique' => FALSE,
          ),
          47 => array(
            'source' => 'dc.relation.isversionof',
            'target' => 'field_dc_relation_isversionof',
            'unique' => FALSE,
          ),
          48 => array(
            'source' => 'dc.rights.copyright',
            'target' => 'field_dc_rights_copyright',
            'unique' => FALSE,
          ),
          49 => array(
            'source' => 'dc.rights.holder',
            'target' => 'field_dc_rights_holder',
            'unique' => FALSE,
          ),
          50 => array(
            'source' => 'dc.rights.license',
            'target' => 'field_dc_rights_license',
            'unique' => FALSE,
          ),
          51 => array(
            'source' => 'dc.rights.uri',
            'target' => 'field_dc_rights_uri:url',
            'unique' => FALSE,
          ),
          52 => array(
            'source' => 'dc.source',
            'target' => 'field_dc_source',
            'unique' => FALSE,
          ),
          53 => array(
            'source' => 'dc.subject',
            'target' => 'field_dc_subject',
            'unique' => FALSE,
          ),
          54 => array(
            'source' => 'dc.subject.lcsh',
            'target' => 'field_dc_subject_lcsh',
            'unique' => FALSE,
          ),
          55 => array(
            'source' => 'dc.subject.mesh',
            'target' => 'field_dc_subject_mesh',
            'unique' => FALSE,
          ),
          56 => array(
            'source' => 'dc.subject.mblhistory',
            'target' => 'field_dc_subject_mblhistory',
            'unique' => FALSE,
          ),
          57 => array(
            'source' => 'dc.subject.tag',
            'target' => 'field_dc_subject_tag',
            'unique' => FALSE,
          ),
          58 => array(
            'source' => 'dc.title.alternative',
            'target' => 'field_dc_title_alternative',
            'unique' => FALSE,
          ),
          59 => array(
            'source' => 'dc.description.tableofcontents',
            'target' => 'field_dc_description_tableofcont',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'full_html',
      ),
    ),
    'content_type' => 'dspace_community_feed_source',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => '0',
    'import_on_create' => 0,
    'process_in_background' => 0,
  );
  $export['mblhistory_dspace'] = $feeds_importer;

  return $export;
}
