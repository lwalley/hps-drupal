<?php
/**
 * @file
 * embryo_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function embryo_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: access search_api_page.
  $permissions['access search_api_page'] = array(
    'name' => 'access search_api_page',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: administer facets.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: administer search_api.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search_api',
  );

  return $permissions;
}
