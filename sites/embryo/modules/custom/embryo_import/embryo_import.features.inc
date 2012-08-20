<?php
/**
 * @file
 * embryo_import.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function embryo_import_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function embryo_import_node_info() {
  $items = array(
    'dspace_community_feed_source' => array(
      'name' => t('DSpace Community Feed Source'),
      'base' => 'node_content',
      'description' => t('A Feed Source holding a URL and a community ID to a DSpace Repository'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
