<?php
/**
 * @file
 * cmtls.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function cmtls_default_rules_configuration() {
  $items = array();
  $items['rules_cmtls_application_views_cache'] = entity_import('rules_config', '{ "rules_cmtls_application_views_cache" : {
      "LABEL" : "CT Application views cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "cache_actions" ],
      "ON" : [ "node_insert", "node_update", "node_delete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_app" : "cmtls_app" } }
          }
        }
      ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : { "cmtls_applications" : "cmtls_applications" } } } }
      ]
    }
  }');
  $items['rules_cmtls_comment_views_cache'] = entity_import('rules_config', '{ "rules_cmtls_comment_views_cache" : {
      "LABEL" : "CT Comment views cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "cache_actions", "comment" ],
      "ON" : [ "comment_insert", "comment_delete", "comment_update" ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : {
                "cmtls_comments" : "cmtls_comments",
                "cmtls_member_comments" : "cmtls_member_comments"
              }
            }
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_common_elements_views_cache'] = entity_import('rules_config', '{ "rules_cmtls_common_elements_views_cache" : {
      "LABEL" : "CT common elements views cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "cache_actions", "rules" ],
      "ON" : [ "node_insert", "node_update", "node_delete" ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : {
                "cmtls_map" : "cmtls_map",
                "cmtls_group_content" : "cmtls_group_content",
                "cmtls_common_elements" : "cmtls_common_elements"
              }
            }
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_groups_views_cache'] = entity_import('rules_config', '{ "rules_cmtls_groups_views_cache" : {
      "LABEL" : "CT Groups views cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "cache_actions" ],
      "ON" : [ "node_insert", "node_update", "node_delete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_group" : "cmtls_group" } }
          }
        }
      ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : { "cmtls_group" : "cmtls_group" } } } }
      ]
    }
  }');
  $items['rules_cmtls_location_views_cache'] = entity_import('rules_config', '{ "rules_cmtls_location_views_cache" : {
      "LABEL" : "CT Location views cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "cache_actions" ],
      "ON" : [ "node_insert", "node_update", "node_delete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_location" : "cmtls_location" } }
          }
        }
      ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : {
                "cmtls_group_content" : "cmtls_group_content",
                "cmtls_locations" : "cmtls_locations"
              }
            }
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_member_views_cache'] = entity_import('rules_config', '{ "rules_cmtls_member_views_cache" : {
      "LABEL" : "CT Member views cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "cache_actions", "og" ],
      "ON" : [ "og_user_insert", "og_user_delete" ],
      "IF" : [
        { "data_is" : {
            "data" : [ "og-membership:state" ],
            "op" : "IN",
            "value" : { "value" : { "1" : "1", "2" : "2", "3" : "3" } }
          }
        }
      ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : { "cmtls_members" : "cmtls_members" } } } }
      ]
    }
  }');
  return $items;
}
