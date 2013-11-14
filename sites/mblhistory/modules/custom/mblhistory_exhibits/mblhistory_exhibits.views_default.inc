<?php

/**
 * Implements hook_views_default_views_alter().
 */
function mblhistory_exhibits_views_default_views_alter(&$views) {

  if (isset($views['hps_exhibits'])) {

    /* Display: Related items lookup */
    $handler =& $views['hps_exhibits']->display['entityreference_exhibits_related_items']->handler;
    /* Filter criterion: Content: DC Type MBL History (dc_type_mblhistory) */
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['id'] = 'dc_type_mblhistory_tid';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['table'] = 'field_data_dc_type_mblhistory';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['field'] = 'dc_type_mblhistory_tid';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['operator'] = 'empty';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['type'] = 'select';
    $handler->display->display_options['filters']['dc_type_mblhistory_tid']['vocabulary'] = 'dc_type_mblhistory';

    unset($handler);
  }

}
