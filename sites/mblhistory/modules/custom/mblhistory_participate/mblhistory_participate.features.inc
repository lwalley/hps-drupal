<?php
/**
 * @file
 * mblhistory_participate.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mblhistory_participate_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mblhistory_participate_views_api() {
  return array("version" => "3.0");
}
