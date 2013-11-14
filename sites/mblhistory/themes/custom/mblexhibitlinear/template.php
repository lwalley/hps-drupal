<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */

/**
 * Implements preprocess_panels_pane().
 */
function mblexhibitlinear_preprocess_panels_pane(&$variables) {
  switch ($variables['pane']->subtype) {
    case 'node_book_nav':
    case 'node_book_menu':
      $variables['attributes_array']['data-sticky-breakpoint'] = '850';
      break;
  }

}

