<?php

/**
 * Result of FeedsDSpaceCommunityFetcher::fetch().
 */
class FeedsDSpaceCommunityFetcherResult extends FeedsFetcherResult {
  protected $url;

  public function __construct(array $config) {

    // The results returned by the DSpace REST interface appear to be
    // from 0:00 on startdate to 0:00 on enddate. Using the same date for the
    // startdate and enddate appears to never return results. To get only the
    // DSpace artifacts from a given date, use a startdate of the desired date
    // and an enddate of the next day.

    // Import a maximum of one day's changes from DSpace
    $last_import = new DateTime($config['last_import_date']);
    $startdate = $last_import->format('Y-m-d');
    $enddate = $last_import->add(new DateInterval('P1D'))->format('Y-m-d');

    // Never use an $enddate greater than today.
    $today = new DateTime();
    if ($last_import > $today) {
      $enddate = $today->format('Y-m-d');
    }

    $options = array(
      'query' => array(
        'community' => $config['dspace_community'],
        'startdate' => $startdate,
        'enddate' => $enddate,
        // @fixme The DSpace REST interface doesn't appear to sort by
        // lastModified date properly.
        // '_sort' => 'lastmodified'
      ),
    );
    $this->url = url($config['source'] . 'harvest.json', $options);
    parent::__construct('');
  }

  /**
   * Overrides FeedsFetcherResult::getRaw();
   */
  public function getRaw() {
    feeds_dbg($this->url);
    feeds_include_library('http_request.inc', 'http_request');
    $result = http_request_get($this->url);
    if (!in_array($result->code, array(200, 201, 202, 203, 204, 205, 206))) {
      throw new Exception(t('Download of @url failed with code !code.', array('@url' => $this->url, '!code' => $result->code)));
    }
    return $this->sanitizeRaw($result->data);
  }
}

/**
 * Fetches data via HTTP.
 */
class FeedsDSpaceCommunityFetcher extends FeedsFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    return new FeedsDSpaceCommunityFetcherResult($source->getConfigFor($this));
  }

  /**
   * Implements FeedsFetcher::configDefaults().
   */
  public function configDefaults() {
    return array();
  }

  /**
   * Implements FeedsFetcher::configForm().
   */
  public function configForm(&$form_state) {
    $form = array();
    return $form;
  }

  /**
   * Expose source form.
   */
  public function sourceForm($source_config) {
    $form = array();
    $form['source'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('The root URL of the DSpace site.'),
      '#default_value' => isset($source_config['source']) ? $source_config['source'] : '',
      '#maxlength' => NULL,
      '#required' => TRUE,
    );
    $form['dspace_community'] = array(
      '#type' => 'textfield',
      '#title' => t('Community ID'),
      '#description' => t('A DSpace Community ID'),
      '#default_value' => isset($source_config['dspace_community']) ? $source_config['dspace_community'] : '',
      '#maxlength' => NULL,
      '#required' => TRUE,
    );
    $form['last_import_date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date of Latest Imported Item'),
      '#description' => t('The Last Modified date of the last DSpace artifact to be imported, in YYYY-MM-DD format.'),
      '#default_value' => isset($source_config['last_import_date']) ? $source_config['last_import_date'] : 0,
      '#maxlength' => 10,
      '#required' => TRUE,
      // @todo This field should be disabled once everything's working.
      // '#disabled' => TRUE,
    );
    return $form;
  }

  /**
   * Override parent::sourceFormValidate().
   */
  public function sourceFormValidate(&$values) {
    if (!feeds_valid_url($values['source'], TRUE)) {
      $form_key = 'feeds][' . get_class($this) . '][source';
      form_set_error($form_key, t('The URL %source is invalid.', array('%source' => $values['source'])));
    }
  }
}
