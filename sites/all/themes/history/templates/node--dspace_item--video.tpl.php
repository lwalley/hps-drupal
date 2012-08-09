<!-- Since majority of DSpace items are of type article, this default template assumes type article. -->
<!-- We'll be making specific templates for the other types. -->

<article id="article-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $unpublished; ?>

  <?php print render($title_prefix); ?>
  <?php if(!empty($user_picture) || $title || (!empty($submitted) && $display_submitted)): ?>
    <header class="clearfix<?php $user_picture ? print ' with-picture' : ''; ?>">

      <?php print $user_picture; ?>

      <?php if ($title): ?>
        <h1<?php print $title_attributes; ?>>
          <?php if ($page): ?>
            <?php print $title; ?>
          <?php elseif (!$page): ?>
            <a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a>
          <?php endif; ?>
        </h1>
      <?php endif; ?>

      <?php if ($display_submitted): ?>
        <div class="submitted"><?php print $submitted; ?></div>
      <?php endif; ?>

    </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div<?php print $content_attributes; ?>>
  <?php
    hide($content['comments']);
    hide($content['links']);
    /* print render($content); */

    print '<div class="subhead">';
    if (isset($node->field_dspace_creator['und'][0]['value']) && $node->field_dspace_creator['und'][0]['value'] != '') { 
      print '<div class="byline">';
      $names = explode(", ", $node->field_dspace_creator['und'][0]['value']);
      print 'by '.$names[1] . ' ' . $names[0];
      print '</div>';
    }

    if (count($node->field_dc_description_tags) + count($node->field_dc_subject_tag) > 0) {
      print '<div class="keywords">Keywords: '.render(field_view_field('node', $node, 'field_dc_description_tags', array('label' => 'hidden')));
      print render(field_view_field('node', $node, 'field_dc_subject_tag', array('label' => 'hidden')));
      print '</div>';
    }
    print '</div>';

    // render video
    drupal_add_js('http://ajax.googleapis.com/ajax/libs/swfobject/2.2/swfobject.js', 'external');
    drupal_add_js($base_url.'/sites/all/libraries/jwplayer/jwplayer.js');

    $video_path = '';
    foreach ($node->field_dspace_bitstreams['und'] as $bitstream) {
      if (substr($bitstream['url'], -8) == '.web.mp4') {
        $video_path = $bitstream['url'];
      }
    }
    if ($video_path == '') {
      $video_path = $node->field_dspace_bitstreams['und'][0]['url'];
    }
    ?>
    <p id="container1">Please install the Flash Plugin</p>
    <script type="text/javascript">
      var flashvars = { file:'<?php print $video_path; ?>',autostart:'true' };
      var params = { allowfullscreen:'true', allowscriptaccess:'always' };
      var attributes = { id:'player1', name:'player1' };

      swfobject.embedSWF('<?php print $base_url ?>/sites/all/libraries/jwplayer/player.swf','container1','480','270','9.0.115','false',flashvars, params, attributes);
    </script>

    <?php
    
    print render($content['body']);

    print '<div class="desc field"><h2 class="field-label">Description:</h2>';
    print render(field_view_field('node', $node, 'field_dspace_description', array('label' => 'hidden')));
    print render(field_view_field('node', $node, 'field_dc_description_abstract', array('label' => 'hidden')));
    print '</div>';

    print '<div class="subject field"><h2 class="field-label">Subject:</h2>';
    print render(field_view_field('node', $node, 'field_dc_subject_lcsh', array('label' => 'hidden')));
    print render(field_view_field('node', $node, 'field_dc_subject_mesh', array('label' => 'hidden')));
    print '</div>';

    print '<div class="category field"><h2 class="field-label">Category:</h2>';
    print render(field_view_field('node', $node, 'field_dc_subject_embryo', array('label' => 'hidden')));
    print '</div>';

    print '<div class="field cite">';
    print '<h2 class="field-label">How to Cite: </h2><div class="field-items"><div class="field-item even">';
    if (isset($node->field_dspace_creator['und'][0]['value']) && $node->field_dspace_creator['und'][0]['value'] != '') {
      print $node->field_dspace_creator['und'][0]['value'].', ';
    }
    print '"'.$node->title.'". ';
    print 'Embryo Project Encyclopedia. ';
    print $node->field_dspace_link[$node->language][0]['url'].'. ';
    print $node->field_dc_date_created['und'][0]['value'];
    print '</div></div></div>';

    print render($content['field_dspace_last_modified']);

    print '<div class="publisher field"><h2 class="field-label">Publisher:</h2>';
    if (isset($node->field_dspace_publisher['und'][0]['value']) && $node->field_dspace_publisher['und'][0]['value'] != '') {
      print $node->field_dspace_publisher['und'][0]['value'].'. ';
    }
    if (isset($node->field_dc_publisher_original['und'][0]['value']) && $node->field_dc_publisher_original['und'][0]['value'] != '') {
      print $node->field_dc_publisher_original['und'][0]['value'].'. ';
    }
    if (isset($node->field_dc_publisher_digital['und'][0]['value']) && $node->field_dc_publisher_digital['und'][0]['value'] != '') {
      print $node->field_dc_publisher_digital['und'][0]['value'].'. ';
    }
    print '</div>';

    print '<div class="rights field"><h2 class="field-label">Rights:</h2> ';
    if (isset($node->field_dspace_rights['und'][0]['value']) && $node->field_dspace_rights['und'][0]['value'] != ''
      && (!isset($node->field_dc_rights_license['und'][0]['value']) || $node->field_dc_rights_license['und'][0]['value'] == '') ) {
      print $node->field_dspace_rights['und'][0]['value'].'. ';
    }
    if (isset($node->field_dc_rights_copyright['und'][0]['value']) && $node->field_dc_rights_copyright['und'][0]['value'] != '') {
      print $node->field_dc_rights_copyright['und'][0]['value'].'. ';
    }
    if (isset($node->field_dc_rights_holder['und'][0]['value']) && $node->field_dc_rights_holder['und'][0]['value'] != '') {
      print $node->field_dc_rights_holder['und'][0]['value'].'. ';
    }
    if (isset($node->field_dc_rights_license['und'][0]['value']) && $node->field_dc_rights_license['und'][0]['value'] != '') {
      print $node->field_dc_rights_license['und'][0]['value'].'. ';
    }
    if (isset($node->field_dc_rights_uri['und'][0]['value']) && $node->field_dc_rights_uri['und'][0]['value'] != '') {
      print $node->field_dc_rights_uri['und'][0]['value'].'. ';
    } 
    print '</div>';

    print '<a href="'.$node->field_dspace_link[$node->language][0]['url'].'?show=full" target="_new">Show full item record</a><br /><br />';
  ?>
    
  </div>

  <?php if ($links = render($content['links'])): ?>
    <nav class="clearfix"><?php print $links; ?></nav>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article>
