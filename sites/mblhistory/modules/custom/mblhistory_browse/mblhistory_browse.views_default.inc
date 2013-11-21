<?php

/**
 * Implements hook_views_default_views_alter().
 */
function mblhistory_browse_views_default_views_alter(&$views) {

  if (isset($views['hps_browse'])) {

    /* Display: Master */
    $handler =& $views['hps_browse']->display['default']->handler;
    /* Contextual filter: Content: Has taxonomy term ID */
    $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies']['dc_subject_mblhistory'] = 'dc_subject_mblhistory';
    /* Filter criterion: Content: DC Type MBL History (dc_type_mblhistory) */
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['id'] = 'dc_type_mblhistory_tid';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['table'] = 'field_data_dc_type_mblhistory';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['field'] = 'dc_type_mblhistory_tid';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['operator'] = 'empty';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['type'] = 'select';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['vocabulary'] = 'dc_type_mblhistory';

    unset($handler);

    /* Display: List */
    $handler =& $views['hps_browse']->display['panel_pane_list']->handler;
    /* Field: Content: Topic */
    $handler->display->display_options['fields']['dc_subject_mblhistory']['id'] = 'dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['table'] = 'field_data_dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['field'] = 'dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_type'] = '0';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_label_type'] = '0';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_wrapper_type'] = 'p';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['dc_subject_mblhistory']['delta_offset'] = '0';
    // Move Topic field to correct position in field order
    _mblhistory_dspaced_move_field($handler->display->display_options['fields'], 'dc_subject_mblhistory', 'dc_description_type');
    unset($handler);

  }
}

/**
 * Helper function to move field to new position in array.
 *
 * @param array $fields
 *   Array of fields from $handler->display->display_options['fields'] passed by
 *   reference.
 * @param string $move_field
 *   Name of field to be moved i.e. array key.
 * @param string $put_before
 *   Name of field that the moved field should be put before i.e. array key.
 */
function _mblhistory_browse_move_field(&$fields, $move_field, $put_before) {
  if (isset($fields[$put_before])) {
    $field = array_slice($fields, array_search($move_field, array_keys($fields)), 1, TRUE);
    unset($fields[$move_field]);
    $fields = array_slice($fields, 0, array_search($put_before, array_keys($fields))) +
      $field +
      array_slice($fields, array_search($put_before, array_keys($fields)));
  }
}

