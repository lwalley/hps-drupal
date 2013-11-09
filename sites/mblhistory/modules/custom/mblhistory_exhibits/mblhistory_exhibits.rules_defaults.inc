<?php
/**
 * @file
 * mblhistory_exhibits.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration_alter().
 */
function mblhistory_exhibits_default_rules_configuration_alter(&$configs) {
  if (isset($configs['rules_hps_exhibit_after_create'])) {
    foreach ($configs['rules_hps_exhibit_after_create']->actions() as $action) {
      if (method_exists($action, 'getElementName') && $action->getElementName() == 'data_set') {
        if (isset($action->settings['data:select']) && $action->settings['data:select'] == 'node:group-theme') {
          $themes = list_themes();
          if (isset($themes['mblexhibitlinear']) && $themes['mblexhibitlinear']->status == 1) {
            $action->settings['value'] = 'mblexhibitlinear';
          }
        }
      }
    }
  }
}
