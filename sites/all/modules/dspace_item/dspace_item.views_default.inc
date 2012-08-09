<?php
/**
 * @file
 * dspace_item.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dspace_item_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'dspace_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'DSpace Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'DSpace Items';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_dc_subject_embryo' => 'field_dc_subject_embryo',
    'field_dc_description_type' => 'field_dc_description_type',
    'field_dc_type' => 'field_dc_type',
    'field_dc_date_created' => 'field_dc_date_created',
    'created' => 'created',
    'field_dspace_last_modified' => 'field_dspace_last_modified',
    'field_dspace_link' => 'field_dspace_link',
  );
  $handler->display->display_options['style_options']['default'] = 'field_dspace_last_modified';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dc_subject_embryo' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dc_description_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dc_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dc_date_created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dspace_last_modified' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dspace_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: DC Embryo Subject */
  $handler->display->display_options['fields']['field_dc_subject_embryo']['id'] = 'field_dc_subject_embryo';
  $handler->display->display_options['fields']['field_dc_subject_embryo']['table'] = 'field_data_field_dc_subject_embryo';
  $handler->display->display_options['fields']['field_dc_subject_embryo']['field'] = 'field_dc_subject_embryo';
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dc_subject_embryo']['field_api_classes'] = 0;
  /* Field: Content: DC Description Type */
  $handler->display->display_options['fields']['field_dc_description_type']['id'] = 'field_dc_description_type';
  $handler->display->display_options['fields']['field_dc_description_type']['table'] = 'field_data_field_dc_description_type';
  $handler->display->display_options['fields']['field_dc_description_type']['field'] = 'field_dc_description_type';
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dc_description_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dc_description_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dc_description_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dc_description_type']['field_api_classes'] = 0;
  /* Field: Content: DC Type */
  $handler->display->display_options['fields']['field_dc_type']['id'] = 'field_dc_type';
  $handler->display->display_options['fields']['field_dc_type']['table'] = 'field_data_field_dc_type';
  $handler->display->display_options['fields']['field_dc_type']['field'] = 'field_dc_type';
  $handler->display->display_options['fields']['field_dc_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dc_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dc_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dc_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dc_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dc_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dc_type']['field_api_classes'] = 0;
  /* Field: Content: DC Date Created */
  $handler->display->display_options['fields']['field_dc_date_created']['id'] = 'field_dc_date_created';
  $handler->display->display_options['fields']['field_dc_date_created']['table'] = 'field_data_field_dc_date_created';
  $handler->display->display_options['fields']['field_dc_date_created']['field'] = 'field_dc_date_created';
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dc_date_created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dc_date_created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dc_date_created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dc_date_created']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Content: Last Modified */
  $handler->display->display_options['fields']['field_dspace_last_modified']['id'] = 'field_dspace_last_modified';
  $handler->display->display_options['fields']['field_dspace_last_modified']['table'] = 'field_data_field_dspace_last_modified';
  $handler->display->display_options['fields']['field_dspace_last_modified']['field'] = 'field_dspace_last_modified';
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dspace_last_modified']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dspace_last_modified']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dspace_last_modified']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dspace_last_modified']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_dspace_last_modified']['field_api_classes'] = 0;
  /* Field: Content: DSpace Link */
  $handler->display->display_options['fields']['field_dspace_link']['id'] = 'field_dspace_link';
  $handler->display->display_options['fields']['field_dspace_link']['table'] = 'field_data_field_dspace_link';
  $handler->display->display_options['fields']['field_dspace_link']['field'] = 'field_dspace_link';
  $handler->display->display_options['fields']['field_dspace_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dspace_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dspace_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dspace_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dspace_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_dspace_link']['field_api_classes'] = 0;
  /* Sort criterion: Content: Last Modified (field_dspace_last_modified) */
  $handler->display->display_options['sorts']['field_dspace_last_modified_value']['id'] = 'field_dspace_last_modified_value';
  $handler->display->display_options['sorts']['field_dspace_last_modified_value']['table'] = 'field_data_field_dspace_last_modified';
  $handler->display->display_options['sorts']['field_dspace_last_modified_value']['field'] = 'field_dspace_last_modified_value';
  $handler->display->display_options['sorts']['field_dspace_last_modified_value']['order'] = 'DESC';
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
    'dspace_item' => 'dspace_item',
  );
  /* Filter criterion: Content: DC Type (field_dc_type) */
  $handler->display->display_options['filters']['field_dc_type_tid']['id'] = 'field_dc_type_tid';
  $handler->display->display_options['filters']['field_dc_type_tid']['table'] = 'field_data_field_dc_type';
  $handler->display->display_options['filters']['field_dc_type_tid']['field'] = 'field_dc_type_tid';
  $handler->display->display_options['filters']['field_dc_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dc_type_tid']['expose']['operator_id'] = 'field_dc_type_tid_op';
  $handler->display->display_options['filters']['field_dc_type_tid']['expose']['label'] = 'Filter by DC Type';
  $handler->display->display_options['filters']['field_dc_type_tid']['expose']['operator'] = 'field_dc_type_tid_op';
  $handler->display->display_options['filters']['field_dc_type_tid']['expose']['identifier'] = 'field_dc_type_tid';
  $handler->display->display_options['filters']['field_dc_type_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_dc_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_dc_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_dc_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_dc_type_tid']['vocabulary'] = 'dc_type';
  $handler->display->display_options['filters']['field_dc_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_dc_type_tid']['error_message'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dspace';
  $export['dspace_items'] = $view;

  return $export;
}
