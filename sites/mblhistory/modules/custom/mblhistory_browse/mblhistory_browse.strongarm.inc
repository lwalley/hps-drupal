<?php
/**
 * @file
 * mblhistory_browse.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mblhistory_browse_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_display_descendants_dc_subject_mblhistory';
  $strongarm->value = 1;
  $export['taxonomy_menu_display_descendants_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_display_num_dc_subject_mblhistory';
  $strongarm->value = 0;
  $export['taxonomy_menu_display_num_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_end_all_dc_subject_mblhistory';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_end_all_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_expanded_dc_subject_mblhistory';
  $strongarm->value = 1;
  $export['taxonomy_menu_expanded_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_flat_dc_subject_mblhistory';
  $strongarm->value = 1;
  $export['taxonomy_menu_flat_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_hide_empty_terms_dc_subject_mblhistory';
  $strongarm->value = 1;
  $export['taxonomy_menu_hide_empty_terms_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_path_dc_subject_mblhistory';
  $strongarm->value = 'taxonomy_menu_path_default';
  $export['taxonomy_menu_path_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_rebuild_dc_subject_mblhistory';
  $strongarm->value = 0;
  $export['taxonomy_menu_rebuild_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_sync_dc_subject_mblhistory';
  $strongarm->value = 1;
  $export['taxonomy_menu_sync_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_term_item_description_dc_subject_mblhistory';
  $strongarm->value = 0;
  $export['taxonomy_menu_term_item_description_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_vocab_menu_dc_subject_mblhistory';
  $strongarm->value = 'main-menu';
  $export['taxonomy_menu_vocab_menu_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_vocab_parent_dc_subject_mblhistory';
  $strongarm->value = '952';
  $export['taxonomy_menu_vocab_parent_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_item_dc_subject_mblhistory';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_voc_item_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_item_description_dc_subject_mblhistory';
  $strongarm->value = 0;
  $export['taxonomy_menu_voc_item_description_dc_subject_mblhistory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_name_dc_subject_mblhistory';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_voc_name_dc_subject_mblhistory'] = $strongarm;

  return $export;
}

/**
 * Implements hook_strongarm_alter().
 */
function mblhistory_browse_strongarm_alter(&$strongarms) {
  if (isset($strongarms['taxonomy_menu_vocab_parent_dc_description_type'])
    && ($mlid = hps_helpers_find_mlid_by_menu_path('archives/formats'))
  ) {
    $strongarms['taxonomy_menu_vocab_parent_dc_description_type']->value = $mlid;
  }
}
