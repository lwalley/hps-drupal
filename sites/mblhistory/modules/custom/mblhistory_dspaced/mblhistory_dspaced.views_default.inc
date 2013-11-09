<?php

/**
 * Implements hook_views_default_views_alter().
 */
function mblhistory_dspaced_views_default_views_alter(&$views) {

  if (isset($views['hps_encyclopedia_items'])) {

    /* Display: Master */
    $handler =& $views['hps_encyclopedia_items']->display['default']->handler;
    /* Filter criterion: Content: DC Type MBL History (dc_type_mblhistory) */
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['id'] = 'dc_type_mblhistory_tid';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['table'] = 'field_data_dc_type_mblhistory';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['field'] = 'dc_type_mblhistory_tid';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['operator'] = 'empty';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['type'] = 'select';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['vocabulary'] = 'dc_type_mblhistory';

    unset($handler);

    /* Display: Item */
    $handler =& $views['hps_encyclopedia_items']->display['ctools_context_encyclopedia_item']->handler;
    /* Field: Content: Topic */
    $handler->display->display_options['fields']['dc_subject_mblhistory']['id'] = 'dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['table'] = 'field_data_dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['field'] = 'dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['label'] = 'Topics';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_type'] = 'p';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_label_type'] = 'h4';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_wrapper_type'] = 'div';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['dc_subject_mblhistory']['hide_empty'] = TRUE;
    $handler->display->display_options['fields']['dc_subject_mblhistory']['delta_offset'] = '0';
    // Move Topic field to correct position in field order
    _mblhistory_dspaced_move_field($handler->display->display_options['fields'], 'dc_subject_mblhistory', 'dc_description_type');
    /* Field: Content: Handle as URL */
    $handler->display->display_options['fields']['dspace_handle']['alter']['text'] = 'http://hpsrepository.mbl.edu/handle/[dspace_handle]';
    /* Field: Global: Custom text */
    $handler->display->display_options['fields']['nothing']['alter']['text'] = '[dc_creator_1] "[title]". History of the Marine Biological Laboratory. [dspace_handle]. [dc_date_created]';

    unset($handler);

    /* Display: Recent Items */
    $handler =& $views['hps_encyclopedia_items']->display['panel_pane_encyclopedia_recent_items']->handler;
    /* Footer: More Link To Custom Page */
    $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="more-link"><a href="/explore/items">See more items</a></div>';

    unset($handler);

    /* Display: Feed */
    $handler =& $views['hps_encyclopedia_items']->display['feed_encyclopedia_items']->handler;
    $handler->display->display_options['title'] = 'Latest additions to the History of the Marine Biological Laboratory.';
    $handler->display->display_options['style_options']['channel']['core']['views_rss_core']['description'] = 'Items recently added to the History of the Marine Biological Laboratory repository.';
    $handler->display->display_options['style_options']['channel']['core']['views_rss_core']['copyright'] = 'Copyright 2013 Marine Biological Laboratory and Arizona Board of Regents';
    /* Field: Content: Topic */
    $handler->display->display_options['fields']['dc_subject_mblhistory']['id'] = 'dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['table'] = 'field_data_dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['field'] = 'dc_subject_mblhistory';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['label'] = '';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_type'] = '0';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_label_type'] = '0';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['dc_subject_mblhistory']['hide_empty'] = TRUE;
    $handler->display->display_options['fields']['dc_subject_mblhistory']['type'] = 'taxonomy_term_reference_plain';
    $handler->display->display_options['fields']['dc_subject_mblhistory']['delta_offset'] = '0';
    // Move Topic field to correct position in field order
    _mblhistory_dspaced_move_field($handler->display->display_options['fields'], 'dc_subject_mblhistory', 'dc_description_type');
    /* Field: Content: Format */
    $handler->display->display_options['fields']['dc_description_type']['alter']['text'] = '[dc_description_type]/[dc_subject_mblhistory]';
    $handler->display->display_options['path'] = 'explore/items/feed';

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
function _mblhistory_dspaced_move_field(&$fields, $move_field, $put_before) {
  if (isset($fields[$put_before])) {
    $field = array_slice($fields, array_search($move_field, array_keys($fields)), 1, TRUE);
    unset($fields[$move_field]);
    $fields = array_slice($fields, 0, array_search($put_before, array_keys($fields))) +
      $field +
      array_slice($fields, array_search($put_before, array_keys($fields)));
  }
}

