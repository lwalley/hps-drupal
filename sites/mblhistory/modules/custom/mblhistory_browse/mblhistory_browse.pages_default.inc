<?php
/**
 * @file
 * mblhistory_browse.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function mblhistory_browse_default_page_manager_handlers_alter(&$export) {

  if ($vocabulary = hps_helpers_find_vocabulary_by('dc_subject_mblhistory')) {

    if (isset($export['term_view_panel_context_root'])
      && $export['term_view_panel_context_root']->task = 'term_view'
    ) {
      $handler =& $export['term_view_panel_context_root'];
      hps_helpers_add_vocabulary_to_access_plugins($vocabulary, $handler);
      $handler->conf['access']['plugins'][] = array(
        'name' => 'term_parent',
        'settings' => array(
          'vid' => (string) $vocabulary->vid,
        ),
        'context' => 'argument_term_1',
        'not' => TRUE,
      );

      unset($handler);
    }

    if (isset($export['term_view_panel_context_list'])
      && $export['term_view_panel_context_root']->task = 'term_view'
    ) {
      $handler =& $export['term_view_panel_context_list'];
      hps_helpers_add_vocabulary_to_access_plugins($vocabulary, $handler);
      unset($handler);
    }

  }
}

/**
 * Implements hook_default_page_manager_pages_alter().
 *
 */
function mblhistory_browse_default_page_manager_pages_alter(&$pages) {

  if ($vocabulary = hps_helpers_find_vocabulary_by('dc_subject_mblhistory')) {

    if (isset($pages['hps_browse_by_modes'])) {
      $page =& $pages['hps_browse_by_modes'];
      $page->arguments['taxonomy_term']['settings']['vids'][(int) $vocabulary->vid] = (string) $vocabulary->vid;

      if (isset($page->default_handlers['page_hps_browse_by_modes_panel_context_gallery'])) {
        $handler =& $page->default_handlers['page_hps_browse_by_modes_panel_context_gallery'];
        hps_helpers_add_vocabulary_to_access_plugins($vocabulary, $handler);
        unset($handler);
      }

      if (isset($page->default_handlers['page_hps_browse_by_modes_panel_context_index'])) {
        $handler =& $page->default_handlers['page_hps_browse_by_modes_panel_context_index'];
        hps_helpers_add_vocabulary_to_access_plugins($vocabulary, $handler);
        unset($handler);
      }
    }

  }
}

