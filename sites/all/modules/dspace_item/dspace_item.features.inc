<?php
/**
 * @file
 * dspace_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dspace_item_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dspace_item_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dspace_item_node_info() {
  $items = array(
    'dspace_item' => array(
      'name' => t('DSpace Item'),
      'base' => 'node_content',
      'description' => t('An item imported from DSpace'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
