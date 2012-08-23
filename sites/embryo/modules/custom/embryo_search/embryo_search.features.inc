<?php
/**
 * @file
 * embryo_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function embryo_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function embryo_search_default_search_api_index() {
  $items = array();
  $items['embryo_search_index'] = entity_import('search_api_index', '{
    "name" : "Embryo Search Index",
    "machine_name" : "embryo_search_index",
    "description" : null,
    "server" : "hps_solr_embryo",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text", "boost" : "5.0" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_subject" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dspace_creator" : { "type" : "text" },
        "field_dspace_identifier" : { "type" : "text" },
        "field_dspace_publisher" : { "type" : "text" },
        "field_dspace_rights" : { "type" : "text" },
        "field_dspace_last_modified" : { "type" : "date" },
        "field_dc_subject_embryo" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_dc_relation_ispartof" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_description_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_description_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_dc_date_created" : { "type" : "date" },
        "field_dc_contributor" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_corresponde" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_editor" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_illustrator" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_interviewee" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_interviewer" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_narrator" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_photographe" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_speaker" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_translator" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_contributor_videographe" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_coverage" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_coverage_spacial" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_coverage_temporal" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_date" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_description_abstract" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_description_tableofcont" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_format_extent" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_format_medium" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_identifier_issn" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_publisher_digital" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_publisher_original" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_relation_hasformat" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_relation_haspart" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_relation_hasversion" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_relation_isformatof" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_relation_isversionof" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_rights_copyright" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_rights_holder" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_rights_license" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_source" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dc_subject_lcsh" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_subject_mesh" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_subject_tag" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_title_alternative" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_language" : { "type" : "string" },
        "field_dc_subject_embryo:name" : { "type" : "list\\u003Ctext\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "dspace_item" : "dspace_item" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_dc_subject_embryo:parents_all" : "field_dc_subject_embryo:parents_all",
              "field_dc_subject_lcsh:parents_all" : "field_dc_subject_lcsh:parents_all",
              "field_dc_subject_mblhistory:parents_all" : "field_dc_subject_mblhistory:parents_all"
            }
          }
        },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_dc_subject_embryo:name" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_dc_subject_embryo:name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_dc_subject_embryo:name" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_dc_subject_embryo:name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function embryo_search_default_search_api_page() {
  $items = array();
  $items['embryo_search_page'] = entity_import('search_api_page', '{
    "index_id" : "embryo_search_index",
    "path" : "search",
    "name" : "Search",
    "machine_name" : "embryo_search_page",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "per_page" : "10",
      "get_per_page" : 1,
      "view_mode" : "teaser"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function embryo_search_default_search_api_server() {
  $items = array();
  $items['hps_solr_embryo'] = entity_import('search_api_server', '{
    "name" : "HPS Solr Embryo",
    "machine_name" : "hps_solr_embryo",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/embryo",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
