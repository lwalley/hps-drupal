<?php
/**
 * @file
 * mblhistory_participate.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function mblhistory_participate_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'mblhistory_participate';
  $page->task = 'page';
  $page->admin_title = 'MBL History Participate';
  $page->admin_description = 'Participate landing page.';
  $page->path = 'participate';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Participate',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_mblhistory_participate_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'mblhistory_participate';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_landing';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'primary-box' => NULL,
      'aside-box' => NULL,
      'downside-box' => NULL,
      'introduction' => NULL,
      'featured' => NULL,
      'content' => NULL,
    ),
    'introduction' => array(
      'style' => 'naked',
    ),
    'featured' => array(
      'style' => 'naked',
    ),
    'content' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = 'Participate in the Marine Biological Laboratory (MBL) history and community archive project';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'content';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_participate-panel_pane_participate_stories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['content'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'content';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_participate-panel_pane_participate_contribute';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['content'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'featured';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_participate-panel_pane_participate_featured';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['featured'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'introduction';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_participate-panel_pane_participate_introduction';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['introduction'][0] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['mblhistory_participate'] = $page;

  return $pages;

}
