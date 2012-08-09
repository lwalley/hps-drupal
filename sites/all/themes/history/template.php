<?php
// embryo by Adaptivethemes.com

/**
 * Override or insert variables into the html template.
 */
function embryo_preprocess_html(&$vars) {
  global $theme_key;

  $theme_name = 'embryo';

  // Load the media queries styles
  $media_queries_css = array(
    $theme_name . '.responsive.style.css',
    $theme_name . '.responsive.gpanels.css'
  );
  load_subtheme_media_queries($media_queries_css, $theme_name);

  // Add a class for the active color scheme
  if (module_exists('color')) {
    $class = check_plain(get_color_scheme_name($theme_key));
    $vars['classes_array'][] = 'color-scheme-' . drupal_html_class($class);
  }

  // Add class for the active theme
  $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser sniff and add a class, unreliable but quite useful
  $vars['classes_array'][] = css_browser_selector();

  // Add theme settings classes
  $settings_array = array(
    'font_size',
    'box_shadows',
    'body_background',
    'menu_bullets',
    'content_corner_radius',
    'tabs_corner_radius',
    'image_alignment',
  );
  foreach ($settings_array as $setting) {
    $vars['classes_array'][] = theme_get_setting($setting);
  }

  // Fonts
  $fonts = array(
    'bf'  => 'base_font',
    'snf' => 'site_name_font',
    'ssf' => 'site_slogan_font',
    'ptf' => 'page_title_font',
    'ntf' => 'node_title_font',
    'ctf' => 'comment_title_font',
    'btf' => 'block_title_font'
  );
  $families = get_font_families($fonts, $theme_key);
  if (!empty($families)) {
    foreach ($families as $family) {
      $vars['classes_array'][] = $family;
    }
  }

  // Headings styles
  if (theme_get_setting('headings_styles_caps') == 1) {
    $vars['classes_array'][] = 'hs-caps';
  }
  if (theme_get_setting('headings_styles_weight') == 1) {
    $vars['classes_array'][] = 'hs-fwn';
  }
  if (theme_get_setting('headings_styles_shadow') == 1) {
    $vars['classes_array'][] = 'hs-ts';
  }
}

/**
 * Hook into the color module.
 */
function embryo_process_html(&$vars) {
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}
function embryo_process_page(&$vars) {
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
}

/**
 * Override or insert variables into the block template.
 */
function embryo_preprocess_block(&$vars) {
  if ($vars['block']->module == 'superfish' || $vars['block']->module == 'nice_menu') {
    $vars['content_attributes_array']['class'][] = 'clearfix';
  }
  if (!$vars['block']->subject) {
    $vars['content_attributes_array']['class'][] = 'no-title';
  }
  if ($vars['block']->region == 'menu_bar' || $vars['block']->region == 'top_menu') {
    $vars['title_attributes_array']['class'][] = 'element-invisible';
  }
}

/**
 * Override or insert variables into the field template.
 */
function embryo_preprocess_field(&$vars) {
  $element = $vars['element'];
  $vars['classes_array'][] = 'view-mode-' . $element['#view_mode'];
  $vars['image_caption_teaser'] = FALSE;
  $vars['image_caption_full'] = FALSE;
  if (theme_get_setting('image_caption_teaser') == 1) {
    $vars['image_caption_teaser'] = TRUE;
  }
  if (theme_get_setting('image_caption_full') == 1) {
    $vars['image_caption_full'] = TRUE;
  }
  $vars['field_view_mode'] = '';
  $vars['field_view_mode'] = $element['#view_mode'];
}

function embryo_preprocess_node(&$vars) {
  // Add a template suggestion to dspace_item nodes that have a dc.type
  // term reference field set
  if ($vars['type'] == 'dspace_item' && is_object($vars['field_dc_type'][0]['taxonomy_term'])) {
    $vars['theme_hook_suggestions'][] = 'node__dspace_item__' . strtolower($vars['field_dc_type'][0]['taxonomy_term']->name);
  }
}

function embryo_search_api_page_results($variables) {

  drupal_add_css(drupal_get_path('module', 'search_api_page') . '/search_api_page.css');

  $index = $variables['index'];
  $results = $variables['results'];
  $items = $variables['items'];
  $keys = $variables['keys'];

  $top_output = '<p class="search-performance">' . format_plural($results['result count'],
      'The search found 1 result in @sec seconds.',
      'The search found @count results in @sec seconds.',
      array('@sec' => round($results['performance']['complete'], 3))) . '</p>';

  if (!$results['result count']) {
    $top_output .= "\n<h2>" . t('Your search yielded no results') . "</h2>\n";
    return $top_output;
  }

  $top_output .= "\n<h2>" . t('Search results') . "</h2>\n";
  $output = '';
  $lexicon_result = '';

  if ($variables['view_mode'] == 'search_api_page_result') {
    $output .= '<ol class="search-results">';
    foreach ($results['results'] as $item) {
      if (isset($_GET['lexicon']) && $_GET['lexicon'] == 'true') {
        $match_node = node_load($item['id']);
        if (strtolower($match_node->title) == strtolower($keys)) {
          $lexicon_result .= '<li class="search-result">' . theme('search_api_page_result', array('index' => $index, 'result' => $item, 'item' => isset($items[$item['id']]) ? $items[$item['id']] : NULL, 'keys' => $keys)) . '</li>';
        } else {
          $output .= '<li class="search-result">' . theme('search_api_page_result', array('index' => $index, 'result' => $item, 'item' => isset($items[$item['id']]) ? $items[$item['id']] : NULL, 'keys' => $keys)) . '</li>';
        }
      } else {
        $output .= '<li class="search-result">' . theme('search_api_page_result', array('index' => $index, 'result' => $item, 'item' => isset($items[$item['id']]) ? $items[$item['id']] : NULL, 'keys' => $keys)) . '</li>';
      }
    }
    $output .= '</ol>';
  }
  else {
    // This option can only be set when the items are entities.
    $output .= '<div class="search-results">';
    $render = entity_view($index->item_type, $items, $variables['view_mode']);
    $output .= render($render);
    $output .= '</div>';
  }

  return $top_output.$lexicon_result.$output;


}

