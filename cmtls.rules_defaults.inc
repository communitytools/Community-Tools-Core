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
  $items['rules_cmtls_check_string_and_prefix_it'] = entity_import('rules_config', '{ "rules_cmtls_check_string_and_prefix_it" : {
      "LABEL" : "CT check string and prefix it",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "varible" : { "label" : "Variable to check", "type" : "text" },
        "prefix" : { "label" : "Prefix", "type" : "text" },
        "result" : { "label" : "result", "type" : "text", "parameter" : false }
      },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "varible" ] } } ],
      "DO" : [
        { "data_set" : { "data" : [ "result" ], "value" : "[prefix][varible]" } }
      ],
      "PROVIDES VARIABLES" : [ "result" ]
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
  $items['rules_cmtls_daily_newsletter'] = entity_import('rules_config', '{ "rules_cmtls_daily_newsletter" : {
      "LABEL" : "CT daily newsletter",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "views_bulk_operations", "rules", "rules_scheduler" ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "cmtls_members_vbo_all|default" },
            "PROVIDE" : { "entity_list" : { "group_members" : "Group members" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members" ] },
            "ITEM" : { "group_member" : "Group member" },
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "text" },
                  "PROVIDE" : { "variable_added" : { "mail_content" : "Mail content" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "cmtls_groups_vbo_by_member|default",
                    "args" : "[group-member:uid]"
                  },
                  "PROVIDE" : { "entity_list" : { "member_groups" : "Member groups" } }
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "member-groups" ] },
                  "ITEM" : { "member_group" : "Member group" },
                  "DO" : [
                    { "views_bulk_operations_action_load_list" : {
                        "USING" : {
                          "view" : "cmtls_group_vbo_subscribed|default",
                          "args" : "[group-member:uid]\\r\\n[member-group:group:gid]"
                        },
                        "PROVIDE" : { "entity_list" : { "subscribed_groups" : "Subscribed groups" } }
                      }
                    },
                    { "LOOP" : {
                        "USING" : { "list" : [ "subscribed_groups" ] },
                        "ITEM" : { "subscribed_group" : "Subscribed group" },
                        "DO" : [
                          { "variable_add" : {
                              "USING" : { "type" : "text" },
                              "PROVIDE" : { "variable_added" : { "new_apps" : "New applications" } }
                            }
                          },
                          { "views_bulk_operations_action_load_list" : {
                              "USING" : {
                                "view" : "cmtls_application_vbo_all_new|default",
                                "args" : [ "subscribed-group:gid" ]
                              },
                              "PROVIDE" : { "entity_list" : { "applications" : "Applications" } }
                            }
                          },
                          { "LOOP" : {
                              "USING" : { "list" : [ "applications" ] },
                              "ITEM" : { "application" : "Application" },
                              "DO" : [
                                { "data_set" : {
                                    "data" : [ "new-apps" ],
                                    "value" : "[new-apps]\\r\\n\\t\\u0022[application:title]\\u0022 [application:url]\\r\\n\\r\\n"
                                  }
                                }
                              ]
                            }
                          },
                          { "component_rules_cmtls_check_string_and_prefix_it" : {
                              "USING" : {
                                "varible" : "[new-apps]",
                                "prefix" : "New applications in \\u0022[member-group:title]\\u0022:\\r\\n"
                              },
                              "PROVIDE" : { "result" : { "applications_list" : "Applications list" } }
                            }
                          },
                          { "data_set" : {
                              "data" : [ "mail-content" ],
                              "value" : "[mail-content][applications-list]"
                            }
                          }
                        ]
                      }
                    },
                    { "views_bulk_operations_action_load_list" : {
                        "USING" : {
                          "view" : "cmtls_applications_vbo_subscribed|default",
                          "args" : "[member-group:group:gid]\\r\\n[group-member:uid]"
                        },
                        "PROVIDE" : { "entity_list" : { "subscribed_apps" : "Subscribed applications" } }
                      }
                    },
                    { "LOOP" : {
                        "USING" : { "list" : [ "subscribed-apps" ] },
                        "ITEM" : { "subscribed_app" : "Subscribed application" },
                        "DO" : [
                          { "variable_add" : {
                              "USING" : { "type" : "text" },
                              "PROVIDE" : { "variable_added" : { "new_content" : "New content in application" } }
                            }
                          },
                          { "views_bulk_operations_action_load_list" : {
                              "USING" : {
                                "view" : "cmtls_application_contents_vbo|default",
                                "args" : [ "subscribed-app:nid" ]
                              },
                              "PROVIDE" : { "entity_list" : { "app_content_list" : "Application content" } }
                            }
                          },
                          { "LOOP" : {
                              "USING" : { "list" : [ "app-content-list" ] },
                              "ITEM" : { "app_content" : "Content" },
                              "DO" : [
                                { "data_set" : {
                                    "data" : [ "new-content" ],
                                    "value" : "[new-content]\\r\\n\\t\\u0022[app-content:title] ([app-content:comment-count])\\u0022\\r\\n\\t[app-content:body]\\r\\n\\tRead more and manage subscription: [app-content:url]\\r\\n\\r\\n"
                                  }
                                }
                              ]
                            }
                          },
                          { "component_rules_cmtls_check_string_and_prefix_it" : {
                              "USING" : {
                                "varible" : "[new-content]",
                                "prefix" : "New content in \\u0022[subscribed-app:title]\\u0022:\\r\\n"
                              },
                              "PROVIDE" : { "result" : { "application_content" : "Application content" } }
                            }
                          },
                          { "data_set" : {
                              "data" : [ "mail-content" ],
                              "value" : "[mail-content][application-content]"
                            }
                          }
                        ]
                      }
                    },
                    { "component_rules_cmtls_post_comments_newsletter" : {
                        "USING" : { "gid" : [ "member-group:group:gid" ], "uid" : [ "group-member:uid" ] },
                        "PROVIDE" : { "result" : { "post_comments" : "Post comments" } }
                      }
                    },
                    { "data_set" : { "data" : [ "mail-content" ], "value" : "[mail-content][post-comments]" } },
                    { "component_rules_cmtls_event_comments_for_newsletter" : {
                        "USING" : { "gid" : [ "member-group:group:gid" ], "uid" : [ "group-member:uid" ] },
                        "PROVIDE" : { "result" : { "event_comments" : "Event comments" } }
                      }
                    },
                    { "data_set" : {
                        "data" : [ "mail-content" ],
                        "value" : "[mail-content][event-comments]"
                      }
                    },
                    { "component_rules_cmtls_location_comments_for_newsletter" : {
                        "USING" : { "gid" : [ "member-group:group:gid" ], "uid" : [ "group-member:uid" ] },
                        "PROVIDE" : { "result" : { "location_comments" : "Location comments" } }
                      }
                    },
                    { "data_set" : {
                        "data" : [ "mail-content" ],
                        "value" : "[mail-content][location-comments]"
                      }
                    },
                    { "component_rules_cmtls_media_comments_for_newsletter" : {
                        "USING" : { "gid" : [ "member-group:group:gid" ], "uid" : [ "group-member:uid" ] },
                        "PROVIDE" : { "result" : { "media_comments" : "Media comments" } }
                      }
                    },
                    { "data_set" : {
                        "data" : [ "mail-content" ],
                        "value" : "[mail-content][media-comments]"
                      }
                    }
                  ]
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : { "view" : "cmtls_group_vbo_new|default" },
                  "PROVIDE" : { "entity_list" : { "new_groups" : "New groups" } }
                }
              },
              { "variable_add" : {
                  "USING" : { "type" : "text" },
                  "PROVIDE" : { "variable_added" : { "new_groups_content" : "New groups content" } }
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "new-groups" ] },
                  "ITEM" : { "new_group" : "New group" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "new-groups-content" ],
                        "value" : "[new-groups-content]\\r\\n\\t\\u0022[new-group:title]\\u0022 [new-group:url]\\r\\n\\r\\n"
                      }
                    }
                  ]
                }
              },
              { "component_rules_cmtls_check_string_and_prefix_it" : {
                  "USING" : { "varible" : "[new-groups-content]", "prefix" : "New groups:\\r\\n" },
                  "PROVIDE" : { "result" : { "new_groups_content_full" : "New groups content full" } }
                }
              },
              { "data_set" : {
                  "data" : [ "mail-content" ],
                  "value" : "[mail-content][new-groups-content-full]"
                }
              },
              { "component_rules_cmtls_send_newsletter" : { "user" : [ "group-member" ], "content" : "[mail-content]" } }
            ]
          }
        },
        { "schedule" : {
            "component" : "rules_cmtls_daily_newsletter",
            "date" : "+1 day 14:00",
            "identifier" : "CT daily newsletter"
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_event_comments_for_newsletter'] = entity_import('rules_config', '{ "rules_cmtls_event_comments_for_newsletter" : {
      "LABEL" : "CT Event comments for newsletter",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "USES VARIABLES" : {
        "gid" : { "label" : "Group ID", "type" : "integer" },
        "uid" : { "label" : "User ID", "type" : "integer" },
        "result" : { "label" : "Result", "type" : "text", "parameter" : false }
      },
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "cmtls_events_vbo_subscribed|default",
              "args" : "[gid]\\r\\n[uid]"
            },
            "PROVIDE" : { "entity_list" : { "subscribed_entities" : "Subscribed entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "subscribed-entities" ] },
            "ITEM" : { "subscribed_entity" : "Subscribed entity" },
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "text" },
                  "PROVIDE" : { "variable_added" : { "content" : "Content" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "cmtls_comments_vbo|default",
                    "args" : [ "subscribed-entity:nid" ]
                  },
                  "PROVIDE" : { "entity_list" : { "comments" : "Comments" } }
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "comments" ] },
                  "ITEM" : { "comment" : "Comment" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "content" ],
                        "value" : "[content]\\r\\n\\t[comment:body]\\r\\n\\tby [comment:author:name]\\r\\n\\t[comment:url]\\r\\n\\r\\n"
                      }
                    }
                  ]
                }
              },
              { "component_rules_cmtls_check_string_and_prefix_it" : {
                  "USING" : {
                    "varible" : [ "content" ],
                    "prefix" : "New comments in \\u0022[subscribed-entity:title] ([subscribed-entity:comment-count])\\u0022\\r\\n"
                  },
                  "PROVIDE" : { "result" : { "full_content" : "Full content" } }
                }
              },
              { "data_set" : { "data" : [ "result" ], "value" : [ "full-content" ] } }
            ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "result" ]
    }
  }');
  $items['rules_cmtls_flag_user_for_notifications_and_newsletter'] = entity_import('rules_config', '{ "rules_cmtls_flag_user_for_notifications_and_newsletter" : {
      "LABEL" : "CT flag user for notifications and newsletter",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : [ "user_insert" ],
      "DO" : [
        { "flag_flaguser" : {
            "flag" : "cmtls_instant_notifications",
            "user" : [ "account" ],
            "flagging_user" : [ "account" ],
            "permission_check" : 1
          }
        },
        { "flag_flaguser" : {
            "flag" : "cmtls_daily_newsletter",
            "user" : [ "account" ],
            "flagging_user" : [ "account" ],
            "permission_check" : 1
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
                  "subject" : "[site:name] has new content \\u0022[node:title]\\u0022",
                  "message" : "Hello [list-item:field-cmtls-firstname],\\r\\n\\r\\n[site:name] has new section \\u0022[node:title]\\u0022:\\r\\n\\r\\n[node:body]\\r\\n\\r\\n[node:url]\\r\\n---\\r\\nYou can change notification settings for \\u0022[entity-fetched:title]\\u0022 at [entity-fetched:url].",
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
                  "message" : "[comment:author:field-cmtls-firstname] [comment:author:field-cmtls-lastname] commented on \\u0022[comment:node]\\u0022\\r\\n\\r\\n[comment:body]\\r\\n\\r\\n[comment:url]\\r\\n---\\r\\nYou can change notification settings for \\u0022[comment:node]\\u0022 at [comment:node:url].",
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
                  "subject" : "[site:name] has new content: \\u0022[node:title]\\u0022",
                  "message" : "Hello [list-item:field-cmtls-firstname],\\r\\n\\r\\n[site:name] has new location \\u0022[node:title]\\u0022:\\r\\n\\r\\n[node:body]\\r\\n\\r\\n[node:url]\\r\\n---\\r\\nYou can change notification settings for \\u0022[entity-fetched:title]\\u0022 at [entity-fetched:url].",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_location_comments_for_newsletter'] = entity_import('rules_config', '{ "rules_cmtls_location_comments_for_newsletter" : {
      "LABEL" : "CT Location comments for newsletter",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "USES VARIABLES" : {
        "gid" : { "label" : "Group ID", "type" : "integer" },
        "uid" : { "label" : "User ID", "type" : "integer" },
        "result" : { "label" : "Result", "type" : "text", "parameter" : false }
      },
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "cmtls_locations_vbo_subscribed|default",
              "args" : "[gid]\\r\\n[uid]"
            },
            "PROVIDE" : { "entity_list" : { "subscribed_entities" : "Subscribed entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "subscribed-entities" ] },
            "ITEM" : { "subscribed_entity" : "Subscribed entity" },
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "text" },
                  "PROVIDE" : { "variable_added" : { "content" : "Content" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "cmtls_comments_vbo|default",
                    "args" : [ "subscribed-entity:nid" ]
                  },
                  "PROVIDE" : { "entity_list" : { "comments" : "Comments" } }
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "comments" ] },
                  "ITEM" : { "comment" : "Comment" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "content" ],
                        "value" : "[content]\\r\\n\\t[comment:body]\\r\\n\\tby [comment:author:name]\\r\\n\\t[comment:url]\\r\\n\\r\\n"
                      }
                    }
                  ]
                }
              },
              { "component_rules_cmtls_check_string_and_prefix_it" : {
                  "USING" : {
                    "varible" : [ "content" ],
                    "prefix" : "New comments in \\u0022[subscribed-entity:title] ([subscribed-entity:comment-count])\\u0022\\r\\n"
                  },
                  "PROVIDE" : { "result" : { "full_content" : "Full content" } }
                }
              },
              { "data_set" : { "data" : [ "result" ], "value" : [ "full-content" ] } }
            ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "result" ]
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
                  "message" : "[comment:author:field-cmtls-firstname] [comment:author:field-cmtls-lastname] commented on \\u0022[comment:node]\\u0022\\r\\n\\r\\n[comment:body]\\r\\n\\r\\n[comment:url]\\r\\n---\\r\\nYou can change notification settings for \\u0022[comment:node]\\u0022 at [comment:node:url].",
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
  $items['rules_cmtls_media_comments_for_newsletter'] = entity_import('rules_config', '{ "rules_cmtls_media_comments_for_newsletter" : {
      "LABEL" : "CT Media comments for newsletter",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "USES VARIABLES" : {
        "gid" : { "label" : "Group ID", "type" : "integer" },
        "uid" : { "label" : "User ID", "type" : "integer" },
        "result" : { "label" : "Result", "type" : "text", "parameter" : false }
      },
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "cmtls_media_vbo_subscribed|default",
              "args" : "[gid]\\r\\n[uid]"
            },
            "PROVIDE" : { "entity_list" : { "subscribed_entities" : "Subscribed entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "subscribed-entities" ] },
            "ITEM" : { "subscribed_entity" : "Subscribed entity" },
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "text" },
                  "PROVIDE" : { "variable_added" : { "content" : "Content" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "cmtls_comments_vbo|default",
                    "args" : [ "subscribed-entity:nid" ]
                  },
                  "PROVIDE" : { "entity_list" : { "comments" : "Comments" } }
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "comments" ] },
                  "ITEM" : { "comment" : "Comment" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "content" ],
                        "value" : "[content]\\r\\n\\t[comment:body]\\r\\n\\tby [comment:author:name]\\r\\n\\t[comment:url]\\r\\n\\r\\n"
                      }
                    }
                  ]
                }
              },
              { "component_rules_cmtls_check_string_and_prefix_it" : {
                  "USING" : {
                    "varible" : [ "content" ],
                    "prefix" : "New comments in \\u0022[subscribed-entity:title] ([subscribed-entity:comment-count])\\u0022\\r\\n"
                  },
                  "PROVIDE" : { "result" : { "full_content" : "Full content" } }
                }
              },
              { "data_set" : { "data" : [ "result" ], "value" : [ "full-content" ] } }
            ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "result" ]
    }
  }');
  $items['rules_cmtls_member_approved'] = entity_import('rules_config', '{ "rules_cmtls_member_approved" : {
      "LABEL" : "CT member approved",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "og_user_approved" ],
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership request for \\u0022[og_membership:group:label]\\u0022 has been approved",
            "message" : "[account:name],\\r\\n\\r\\nYour membership request for group \\u0022[og_membership:group:label]\\u0022 located at [og_membership:group:url] has been approved, you are now a member.\\r\\n---\\r\\n[site:name]",
            "language" : [ "account:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_member_remove_from_group_active_blocked'] = entity_import('rules_config', '{ "rules_cmtls_member_remove_from_group_active_blocked" : {
      "LABEL" : "CT member remove from group (Active, Blocked)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "og_user_delete" ],
      "IF" : [
        { "data_is" : {
            "data" : [ "og-membership:state" ],
            "op" : "IN",
            "value" : { "value" : { "1" : "1", "3" : "3" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership in \\u0022[og_membership:group:label]\\u0022 has been removed",
            "message" : "[account:name],\\r\\n\\r\\nYour membership in group \\u0022[og_membership:group:label]\\u0022 located at [og_membership:group:url] is removed, you are no longer a member.\\r\\n---\\r\\n[site:name]",
            "language" : [ "account:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_member_remove_from_group_pending'] = entity_import('rules_config', '{ "rules_cmtls_member_remove_from_group_pending" : {
      "LABEL" : "CT member remove from group (Pending)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "og_user_delete" ],
      "IF" : [ { "data_is" : { "data" : [ "og-membership:state" ], "value" : "2" } } ],
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership request for \\u0022[og_membership:group:label]\\u0022 has been denied",
            "message" : "[account:name],\\r\\n\\r\\nYour membership request for group \\u0022[og_membership:group:label]\\u0022 located at [og_membership:group:url] has been denied.\\r\\n---\\r\\n[site:name]",
            "language" : [ "account:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_member_subscribe_active'] = entity_import('rules_config', '{ "rules_cmtls_member_subscribe_active" : {
      "LABEL" : "CT member subscribe (Active)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "og_user_insert" ],
      "IF" : [ { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } } ],
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership request was approved for \\u0027[og_membership:group:label]\\u0027\\r\\n",
            "message" : "[account:name],\\r\\n\\r\\nYou are now a member in the group \\u0027[og_membership:group:label]\\u0027 located at [og_membership:group:url]\\r\\n---\\r\\n[site:name]",
            "language" : [ "account:language" ]
          }
        },
        { "mail" : {
            "to" : [ "og-membership:group:manager:mail" ],
            "subject" : "[account:name] joined [og_membership:group:label]",
            "message" : "[og-membership:group:manager:name],\\r\\n\\r\\n[account:name] joined [og_membership:group:label] in [og_membership:group:url]\\r\\n---\\r\\n[site:name]",
            "language" : [ "account:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_member_subscribe_pending'] = entity_import('rules_config', '{ "rules_cmtls_member_subscribe_pending" : {
      "LABEL" : "CT member subscribe (Pending)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "og_user_insert" ],
      "IF" : [ { "data_is" : { "data" : [ "og-membership:state" ], "value" : "2" } } ],
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership request for \\u0027[og_membership:group:label]\\u0027",
            "message" : "[account:name],\\r\\n\\r\\nYour membership to group \\u0027[og_membership:group:label]\\u0027 located at [og_membership:group:url] is pending approval.\\r\\n---\\r\\n[site:name]",
            "language" : [ "account:language" ]
          }
        },
        { "mail" : {
            "to" : [ "og-membership:group:manager:mail" ],
            "subject" : "[account:name] membership request [og_membership:group:label]",
            "message" : "[og-membership:group:manager:name],\\r\\n\\r\\n[account:name] requests membership for group \\u0027[og_membership:group:label]\\u0027 in [og_membership:group:url].\\r\\n\\r\\n[og_membership:og-membership-request]\\r\\n---\\r\\n[site:name]",
            "language" : [ "account:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_member_subscribe_unsubscribe_cache'] = entity_import('rules_config', '{ "rules_cmtls_member_subscribe_unsubscribe_cache" : {
      "LABEL" : "CT member subscribe\\/unsubscribe cache",
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
  $items['rules_cmtls_notify_about_spam_inappropriate_comment'] = entity_import('rules_config', '{ "rules_cmtls_notify_about_spam_inappropriate_comment" : {
      "LABEL" : "CT notify about spam inappropriate comment",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og", "flag" ],
      "ON" : [ "flag_flagged_cmtls_inappropriate_comment" ],
      "DO" : [
        { "component_rules_cmtls_unpublish_comment_that_has_been_flagged_as_spam" : {
            "count" : "[flagged-comment:flag-cmtls-inappropriate-comment-count]",
            "flagged_comment" : [ "flagged-comment" ]
          }
        },
        { "og_get_managers" : {
            "USING" : { "group_content" : [ "flagged-comment:node" ] },
            "PROVIDE" : { "group_managers" : { "group_managers" : "List of group managers" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-managers" ] },
            "ITEM" : { "group_manager" : "Group manager" },
            "DO" : [
              { "mail" : {
                  "to" : "\\u0022[group-manager:name]\\u0022 \\u003C[group-manager:mail]\\u003E",
                  "subject" : "[site:name] - Comment \\u0022[flagged-comment:title]\\u0022 is marked as spam or inappropriate",
                  "message" : "Comment \\u0022[flagged-comment:title]\\u0022 for \\u0022[flagged-comment:node:title]\\u0022 is marked as spam or inappropriate by [flagging-user:name] ([flagging-user:url]).\\r\\nThis has been marked by [flagged-comment:node:flag-cmtls-inappropriate-comment-count] users, when this reaches 3 the comment is automatically unpublished.\\r\\n\\r\\nReview here: [flagged-comment:edit-url].\\r\\n---\\r\\n[site:name]",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_notify_about_spam_inappropriate_content'] = entity_import('rules_config', '{ "rules_cmtls_notify_about_spam_inappropriate_content" : {
      "LABEL" : "CT notify about spam inappropriate content",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og", "flag" ],
      "ON" : [ "flag_flagged_cmtls_inappropriate_content" ],
      "DO" : [
        { "component_rules_cmtls_unpublish_content_that_has_been_flagged_as_spam" : {
            "count" : "[flagged-node:flag-cmtls-inappropriate-content-count]",
            "flagged_node" : [ "flagged-node" ]
          }
        },
        { "og_get_managers" : {
            "USING" : { "group_content" : [ "flagged-node" ] },
            "PROVIDE" : { "group_managers" : { "group_managers" : "List of group managers" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-managers" ] },
            "ITEM" : { "group_manager" : "Group manager" },
            "DO" : [
              { "mail" : {
                  "to" : "\\u0022[group-manager:name]\\u0022 \\u003C[group-manager:mail]\\u003E",
                  "subject" : "[site:name] - \\u0022[flagged-node:title]\\u0022 is marked as spam or inappropriate",
                  "message" : "\\u0022[flagged-node:title]\\u0022 is marked as spam or inappropriate by [flagging-user:name] ([flagging-user:url]).\\r\\nThis has been marked by [flagged-node:flag-cmtls-inappropriate-content-count] users, when this reaches 3 the content is automatically unpublished.\\r\\n\\r\\nReview here: [flagged-node:edit-url].\\r\\n---\\r\\n[site:name]",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_post_comments_newsletter'] = entity_import('rules_config', '{ "rules_cmtls_post_comments_newsletter" : {
      "LABEL" : "CT Post comments for newsletter",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "USES VARIABLES" : {
        "gid" : { "label" : "Group ID", "type" : "integer" },
        "uid" : { "label" : "User ID", "type" : "integer" },
        "result" : { "label" : "Result", "type" : "text", "parameter" : false }
      },
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "cmtls_posts_vbo_subscribed|default",
              "args" : "[gid]\\r\\n[uid]"
            },
            "PROVIDE" : { "entity_list" : { "subscribed_entities" : "Subscribed entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "subscribed-entities" ] },
            "ITEM" : { "subscribed_entity" : "Subscribed entity" },
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "text" },
                  "PROVIDE" : { "variable_added" : { "content" : "Content" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "cmtls_comments_vbo|default",
                    "args" : [ "subscribed-entity:nid" ]
                  },
                  "PROVIDE" : { "entity_list" : { "comments" : "Comments" } }
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "comments" ] },
                  "ITEM" : { "comment" : "Comment" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "content" ],
                        "value" : "[content]\\r\\n\\t[comment:body]\\r\\n\\tby [comment:author:name]\\r\\n\\t[comment:url]\\r\\n\\r\\n"
                      }
                    }
                  ]
                }
              },
              { "component_rules_cmtls_check_string_and_prefix_it" : {
                  "USING" : {
                    "varible" : [ "content" ],
                    "prefix" : "New comments in \\u0022[subscribed-entity:title] ([subscribed-entity:comment-count])\\u0022\\r\\n"
                  },
                  "PROVIDE" : { "result" : { "full_content" : "Full content" } }
                }
              },
              { "data_set" : { "data" : [ "result" ], "value" : [ "full-content" ] } }
            ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "result" ]
    }
  }');
  $items['rules_cmtls_send_newsletter'] = entity_import('rules_config', '{ "rules_cmtls_send_newsletter" : {
      "LABEL" : "CT send newsletter",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "User", "type" : "user" },
        "content" : { "label" : "Content", "type" : "text" }
      },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "content" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "\\u0022[user:name]\\u0022 \\u003C[user:mail]\\u003E",
            "subject" : "[site:name] content updates",
            "message" : "Hello [user:name],\\r\\n\\r\\nHere\\u0027s a summary of [site:name] content updates\\r\\n\\r\\n[content]\\r\\n---\\r\\n[site:name]",
            "language" : [ "user:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_subscribe_member_to_group_on_join'] = entity_import('rules_config', '{ "rules_cmtls_subscribe_member_to_group_on_join" : {
      "LABEL" : "CT subscribe member to group on join",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "flag", "og" ],
      "ON" : [ "og_user_insert" ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "og-membership:group:etid" ] },
            "PROVIDE" : { "entity_fetched" : { "group_node" : "Group node" } }
          }
        },
        { "flag_flagnode" : {
            "flag" : "cmtls_group_follow",
            "node" : [ "group-node" ],
            "flagging_user" : [ "account" ],
            "permission_check" : 1
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_subscribe_to_group_apps'] = entity_import('rules_config', '{ "rules_cmtls_subscribe_to_group_apps" : {
      "LABEL" : "CT subscribe to group apps",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og", "views_bulk_operations", "flag" ],
      "ON" : [ "flag_flagged_cmtls_group_follow" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "cmtls_group" : "cmtls_group" } }
          }
        },
        { "og_entity_is_group" : { "entity" : [ "flagged-node" ] } }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "cmtls_application_vbo_all|default",
              "args" : [ "flagged-node:group:gid" ]
            },
            "PROVIDE" : { "entity_list" : { "group_applications" : "Group applications" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-applications" ] },
            "ITEM" : { "application" : "Application" },
            "DO" : [
              { "flag_flagnode" : {
                  "flag" : "cmtls_app_follow",
                  "node" : [ "application" ],
                  "flagging_user" : [ "flagging-user" ],
                  "permission_check" : 1
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_unpublish_comment_that_has_been_flagged_as_spam'] = entity_import('rules_config', '{ "rules_cmtls_unpublish_comment_that_has_been_flagged_as_spam" : {
      "LABEL" : "CT unpublish comment that has been flagged as spam",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "count" : { "label" : "Count", "type" : "text" },
        "flagged_comment" : { "label" : "Flagged comment", "type" : "comment" }
      },
      "IF" : [ { "data_is" : { "data" : [ "count" ], "value" : "3" } } ],
      "DO" : [
        { "data_set" : { "data" : [ "flagged-comment:status" ], "value" : "0" } }
      ]
    }
  }');
  $items['rules_cmtls_unpublish_content_that_has_been_flagged_as_spam'] = entity_import('rules_config', '{ "rules_cmtls_unpublish_content_that_has_been_flagged_as_spam" : {
      "LABEL" : "CT unpublish content that has been flagged as spam",
      "PLUGIN" : "rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "count" : { "label" : "Count", "type" : "text" },
        "flagged_node" : { "label" : "Flagged node", "type" : "node" }
      },
      "IF" : [ { "data_is" : { "data" : [ "count" ], "value" : "3" } } ],
      "DO" : [ { "node_unpublish" : { "node" : [ "flagged-node" ] } } ]
    }
  }');
  $items['rules_cmtls_unsubscribe_from_group_apps'] = entity_import('rules_config', '{ "rules_cmtls_unsubscribe_from_group_apps" : {
      "LABEL" : "CT unsubscribe from group apps",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "og", "views_bulk_operations", "flag" ],
      "ON" : [ "flag_unflagged_cmtls_group_follow" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "cmtls_group" : "cmtls_group" } }
          }
        },
        { "og_entity_is_group" : { "entity" : [ "flagged-node" ] } }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "cmtls_application_vbo_all|default",
              "args" : [ "flagged-node:group:gid" ]
            },
            "PROVIDE" : { "entity_list" : { "group_applications" : "Group applications" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-applications" ] },
            "ITEM" : { "application" : "Application" },
            "DO" : [
              { "flag_unflagnode" : {
                  "flag" : "cmtls_app_follow",
                  "node" : [ "application" ],
                  "flagging_user" : [ "flagging-user" ],
                  "permission_check" : 1
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_unsubscribe_member_to_group_on_leaving'] = entity_import('rules_config', '{ "rules_cmtls_unsubscribe_member_to_group_on_leaving" : {
      "LABEL" : "CT unsubscribe member to group on leaving",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "flag", "og" ],
      "ON" : [ "og_user_delete" ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "og-membership:group:etid" ] },
            "PROVIDE" : { "entity_fetched" : { "group_node" : "Group node" } }
          }
        },
        { "flag_unflagnode" : {
            "flag" : "cmtls_group_follow",
            "node" : [ "group-node" ],
            "flagging_user" : [ "account" ],
            "permission_check" : 1
          }
        }
      ]
    }
  }');
  return $items;
}
