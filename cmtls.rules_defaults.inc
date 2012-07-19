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
  $items['rules_cmtls_application_views_cache_resort'] = entity_import('rules_config', '{ "rules_cmtls_application_views_cache_resort" : {
      "LABEL" : "CT Application views cache resort",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "cache_actions", "draggableviews" ],
      "ON" : [ "draggableviews_rules_event_sorted" ],
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
  $items['rules_cmtls_group_follow_own_group'] = entity_import('rules_config', '{ "rules_cmtls_group_follow_own_group" : {
      "LABEL" : "CT Group follow own group",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og", "flag" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_group" : "cmtls_group" } }
          }
        },
        { "og_entity_is_group" : { "entity" : [ "node" ] } }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "cmtls_group_follow",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 1
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_group_notifications'] = entity_import('rules_config', '{ "rules_cmtls_group_notifications" : {
      "LABEL" : "CT Group notifications",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og", "flag" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_app" : "cmtls_app" } }
          }
        },
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:og-membership:0:group:etid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "flag_fetch_users_node" : {
            "USING" : { "flag" : "cmtls_group_follow", "node" : [ "entity-fetched" ] },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "\\u0022[list-item:field-cmtls-firstname] [list-item:field-cmtls-lastname]\\u0022 \\u003C[list-item:mail]\\u003E",
                  "subject" : "[site:name] has new content",
                  "message" : "Hello [list-item:field-cmtls-firstname],\\u000D\\u000A\\u000D\\u000A[site:name] has new section \\u0022[node:title]\\u0022:\\u000D\\u000A\\u000D\\u000A[node:body]\\u000D\\u000A\\u000D\\u000A[node:url]\\u000D\\u000A---\\u000D\\u000AYou can change notification settings for \\u0022[entity-fetched:title]\\u0022 at [entity-fetched:url].",
                  "language" : [ "" ]
                }
              },
              { "flag_flagnode" : {
                  "flag" : "cmtls_app_follow",
                  "node" : [ "node" ],
                  "flagging_user" : [ "list-item" ],
                  "permission_check" : 1
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_group_thread_notifications'] = entity_import('rules_config', '{ "rules_cmtls_group_thread_notifications" : {
      "LABEL" : "CT Group thread notifications",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og", "flag", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "cmtls_group" : "cmtls_group" } }
          }
        },
        { "og_entity_is_group_content" : { "entity" : [ "comment:node" ] } }
      ],
      "DO" : [
        { "flag_fetch_users_node" : {
            "USING" : { "flag" : "cmtls_post_follow", "node" : [ "comment:node" ] },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "\\u0022[list-item:field-cmtls-firstname] [list-item:field-cmtls-lastname]\\u0022 \\u003C[list-item:mail]\\u003E",
                  "subject" : "[site:name] - [comment:author:field-cmtls-firstname] [comment:author:field-cmtls-lastname] has commented on: [comment:node]",
                  "message" : "[comment:author:field-cmtls-firstname] [comment:author:field-cmtls-lastname] commented on \\u0022[comment:node]\\u0022\\u000D\\u000A\\u000D\\u000A[comment:body]\\u000D\\u000A\\u000D\\u000A[comment:url]\\u000D\\u000A---\\u000D\\u000AYou can change notification settings for \\u0022[comment:node]\\u0022 at [comment:node:url].",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "flag_flagnode" : {
            "flag" : "cmtls_post_follow",
            "node" : [ "comment:node" ],
            "flagging_user" : [ "comment:author" ],
            "permission_check" : 1
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
  $items['rules_cmtls_location_app_notifications'] = entity_import('rules_config', '{ "rules_cmtls_location_app_notifications" : {
      "LABEL" : "CT Location app notifications",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_location" : "cmtls_location" } }
          }
        }
      ],
      "DO" : [
        { "flag_fetch_users_node" : {
            "USING" : {
              "flag" : "cmtls_app_follow",
              "node" : [ "node:field-cmtls-application:0" ]
            },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:field-cmtls-application:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "\\u0022[list-item:field-cmtls-firstname] [list-item:field-cmtls-lastname]\\u0022 \\u003C[list-item:mail]\\u003E",
                  "subject" : "[site:name] has new content",
                  "message" : "Hello [list-item:field-cmtls-firstname],\\u000D\\u000A\\u000D\\u000A[site:name] has new location \\u0022[node:title]\\u0022:\\u000D\\u000A\\u000D\\u000A[node:body]\\u000D\\u000A\\u000D\\u000A[node:url]\\u000D\\u000A---\\u000D\\u000AYou can change notification settings for \\u0022[entity-fetched:title]\\u0022 at [entity-fetched:url].",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_location_follow_own_thread'] = entity_import('rules_config', '{ "rules_cmtls_location_follow_own_thread" : {
      "LABEL" : "CT Location follow own thread",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_location" : "cmtls_location" } }
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "cmtls_location_follow",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 1
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_location_thread_notifications'] = entity_import('rules_config', '{ "rules_cmtls_location_thread_notifications" : {
      "LABEL" : "CT Location thread notifications",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "flag", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "cmtls_location" : "cmtls_location" } }
          }
        }
      ],
      "DO" : [
        { "flag_fetch_users_node" : {
            "USING" : { "flag" : "cmtls_location_follow", "node" : [ "comment:node" ] },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "\\u0022[list-item:field-cmtls-firstname] [list-item:field-cmtls-lastname]\\u0022 \\u003C[list-item:mail]\\u003E",
                  "subject" : "[site:name] - [comment:author:field-cmtls-firstname] [comment:author:field-cmtls-lastname] has commented on: [comment:node]",
                  "message" : "[comment:author:field-cmtls-firstname] [comment:author:field-cmtls-lastname] commented on \\u0022[comment:node]\\u0022\\u000D\\u000A\\u000D\\u000A[comment:body]\\u000D\\u000A\\u000D\\u000A[comment:url]\\u000D\\u000A---\\u000D\\u000AYou can change notification settings for \\u0022[comment:node]\\u0022 at [comment:node:url].",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "flag_flagnode" : {
            "flag" : "cmtls_location_follow",
            "node" : [ "comment:node" ],
            "flagging_user" : [ "comment:author" ],
            "permission_check" : 1
          }
        }
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
  $items['rules_cmtls_member_subscribe_unsubscribe_cache'] = entity_import('rules_config', '{ "rules_cmtls_member_subscribe_unsubscribe_cache" : {
      "LABEL" : "CT member subscribe\\u002Funsubscribe cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "cache_actions", "og" ],
      "ON" : [
        "og_user_insert",
        "og_user_delete",
        "og_membership_delete",
        "og_membership_update",
        "og_user_approved",
        "og_user_blocked"
      ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : { "cmtls_group" : "cmtls_group" } } } }
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
