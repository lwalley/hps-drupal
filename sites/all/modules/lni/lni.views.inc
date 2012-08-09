<?php

function lni_views_data() {

  $data = array();
  $data['lni']['table'] = array(
    'group' => t('DSpace LNI'),
    'title' => t('DSpace LNI'),
    'help' => t('Shows the items from the Dspace Repo via LNI interface'),
  );
  $data['lni']['table']['base'] = array(
    'field' => 'id',
    'title' => 'Dspace Items',
    'help' => t('Dspace Items come from the DSpace Repo via the LNI interface'),
    'weight' => 10,
  );

  $data['lni']['handle'] = array(
    'title' => t('Handle'),
    'help' => t('The handle identifier for the item in DSpace'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['lni']['title'] = array(
    'title' => t('Title'),
    'help' => t('Title'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['lni']['subject'] = array(
    'title' => t('Subject'),
    'help' => t('Subject'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['lni']['keywords'] = array(
    'title' => t('Keywords'),
    'help' => t('Keywords'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['lni']['subject_embryo'] = array(
    'title' => t('Subject Embryo'),
    'help' => t('Special Embryo Subject'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

