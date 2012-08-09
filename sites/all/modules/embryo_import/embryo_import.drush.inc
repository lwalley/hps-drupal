<?php

function embryo_import_drush_command() {
  $commands = array();

  $commands['prepare-feeds-import'] = array(
    'description' => 'Prepare for a full import from DSpace',
    'aliases' => array('eip'),
  );

  return $commands;
}

function drush_embryo_import_prepare_feeds_import() {
  drush_confirm(t('Do you want to prepare for a full import?'));

  // Delete all existing DSpace Items
  embryo_import_node_kill('dspace_item');

  // Remove all terms from vocabularies that should be rebuilt during the
  // import.
  $vocabularies_to_clean = array('dc_type');
  foreach ($vocabularies_to_clean as $machine_name) {
    embryo_import_taxonomy_clean($machine_name);
  }

  // Set the last update time on feeds to 0
  embryo_import_reset_feeds();
}

// Copied from devel_generate_content_kill
function embryo_import_node_kill($node_type) {
  $query = new EntityFieldQuery;
  $nodes = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', $node_type)
    ->execute();
  if (isset($nodes['node'])) {
    node_delete_multiple(array_keys($nodes['node']));
    drupal_set_message(t('Deleted %count nodes.', array('%count' => count($nodes['node']))));
  }
}

function embryo_import_taxonomy_clean($machine_name) {
  $vocabularies = taxonomy_vocabulary_get_names();
  if (in_array($machine_name, array_keys($vocabularies))) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($machine_name);
    foreach (taxonomy_get_tree($vocabulary->vid) as $term) {
      taxonomy_term_delete($term->tid);
    }
  }
}

function embryo_import_reset_feeds($timestamp = 0) {
  $updated = db_update('feeds_source')
    ->fields(array(
        'imported' => 0,
      ))
    ->condition('id', 'embryo_dspace', '=')
    ->execute();
}