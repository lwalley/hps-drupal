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
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "localhost_database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
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
              "field_dc_subject:parents_all" : "field_dc_subject:parents_all",
              "field_dc_subject_embryo:parents_all" : "field_dc_subject_embryo:parents_all",
              "field_dc_type:parents_all" : "field_dc_type:parents_all",
              "field_dc_relation_ispartof:parents_all" : "field_dc_relation_ispartof:parents_all",
              "field_dc_description_tags:parents_all" : "field_dc_description_tags:parents_all",
              "field_dc_description_type:parents_all" : "field_dc_description_type:parents_all"
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
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      },
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "comment_count" : { "type" : "integer" },
        "views" : { "type" : "integer" },
        "day_views" : { "type" : "integer" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_subject" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dspace_creator" : { "type" : "text" },
        "field_dspace_publisher" : { "type" : "text" },
        "field_dspace_rights" : { "type" : "text" },
        "field_dspace_last_modified" : { "type" : "date" },
        "field_dc_subject_embryo" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_relation_ispartof" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_description_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_description_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dc_date_created" : { "type" : "date" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "field_dc_subject:name" : { "type" : "list\\u003Ctext\\u003E" }
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
  $items['search_api_page'] = entity_import('search_api_page', '{
    "index_id" : "default_node_index",
    "path" : "search",
    "name" : "Search",
    "machine_name" : "search_api_page",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "per_page" : "10",
      "get_per_page" : 1,
      "view_mode" : "search_api_page_result"
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
  $items['localhost_database'] = entity_import('search_api_server', '{
    "name" : "localhost_database",
    "machine_name" : "localhost_database",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "2",
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_title",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index_promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index_sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_default_node_index_comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "views" : {
            "table" : "search_api_db_default_node_index_views",
            "type" : "integer",
            "boost" : "1.0"
          },
          "day_views" : {
            "table" : "search_api_db_default_node_index_day_views",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_tags" : {
            "table" : "search_api_db_default_node_index_field_tags",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_dc_subject" : {
            "table" : "search_api_db_default_node_index_field_dc_subject",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_dspace_creator" : {
            "table" : "search_api_db_default_node_index_field_dspace_creator",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_dspace_publisher" : {
            "table" : "search_api_db_default_node_index_field_dspace_publisher",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_dspace_rights" : {
            "table" : "search_api_db_default_node_index_field_dspace_rights",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_dspace_last_modified" : {
            "table" : "search_api_db_default_node_index_field_dspace_last_modified",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_dc_subject_embryo" : {
            "table" : "search_api_db_default_node_index_field_dc_subject_embryo",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_dc_type" : {
            "table" : "search_api_db_default_node_index_field_dc_type",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_dc_relation_ispartof" : {
            "table" : "search_api_db_default_node_index_field_dc_relation_ispartof",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_dc_description_tags" : {
            "table" : "search_api_db_default_node_index_field_dc_description_tags",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_dc_description_type" : {
            "table" : "search_api_db_default_node_index_field_dc_description_type",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_dc_date_created" : {
            "table" : "search_api_db_default_node_index_field_dc_date_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_dc_subject:name" : {
            "table" : "search_api_db_default_node_index_field_dc_subject_name",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
