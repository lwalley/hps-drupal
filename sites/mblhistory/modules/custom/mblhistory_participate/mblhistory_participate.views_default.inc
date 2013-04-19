<?php
/**
 * @file
 * mblhistory_participate.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mblhistory_participate_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mblhistory_participate';
  $view->description = 'Views panes for participate section.';
  $view->tag = 'MBL History';
  $view->base_table = 'node';
  $view->human_name = 'MBL History Participate';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Introduction */
  $handler = $view->new_display('panel_pane', 'Introduction', 'panel_pane_participate_introduction');
  $handler->display->display_options['display_description'] = 'Grabs the basic page node that contains the introduction section for participate.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '6052';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );

  /* Display: Featured items */
  $handler = $view->new_display('panel_pane', 'Featured items', 'panel_pane_participate_featured');
  $handler->display->display_options['display_description'] = 'Featured community archive items.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['dspace_image']['id'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['fields']['dspace_image']['field'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['label'] = '';
  $handler->display->display_options['fields']['dspace_image']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['dspace_image']['settings'] = array(
    'image_style' => 'hps_uniform',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  /* Filter criterion: Content: Image (dspace_image:fid) */
  $handler->display->display_options['filters']['dspace_image_fid']['id'] = 'dspace_image_fid';
  $handler->display->display_options['filters']['dspace_image_fid']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['filters']['dspace_image_fid']['field'] = 'dspace_image_fid';
  $handler->display->display_options['filters']['dspace_image_fid']['operator'] = 'not empty';

  /* Display: Contribute */
  $handler = $view->new_display('panel_pane', 'Contribute', 'panel_pane_participate_contribute');
  $handler->display->display_options['display_description'] = 'Grabs the basic page that contains instructions for contributing to the archive.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '6055';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );

  /* Display: Featured stories */
  $handler = $view->new_display('panel_pane', 'Featured stories', 'panel_pane_participate_stories');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'First person stories';
  $handler->display->display_options['display_description'] = 'Featured first person stories from community archive items.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris vitae nisl ut felis auctor placerat.</p>';
  $handler->display->display_options['header']['area']['format'] = 'hps_standard_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['dspace_image']['id'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['fields']['dspace_image']['field'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['label'] = '';
  $handler->display->display_options['fields']['dspace_image']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['dspace_image']['settings'] = array(
    'image_style' => 'hps_minor',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['label'] = '';
  $handler->display->display_options['fields']['dc_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['alter']['text'] = '<h3>[title]</h3>[dc_description]';
  $handler->display->display_options['fields']['dc_description']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description']['separator'] = ' ';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  /* Filter criterion: Content: Image (dspace_image:fid) */
  $handler->display->display_options['filters']['dspace_image_fid']['id'] = 'dspace_image_fid';
  $handler->display->display_options['filters']['dspace_image_fid']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['filters']['dspace_image_fid']['field'] = 'dspace_image_fid';
  $handler->display->display_options['filters']['dspace_image_fid']['operator'] = 'not empty';
  $export['mblhistory_participate'] = $view;

  return $export;
}
