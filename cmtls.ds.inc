<?php
/**
 * @file
 * cmtls.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cmtls_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_cmtls_app|cmtls_teaser';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_cmtls_app';
  $ds_fieldsetting->view_mode = 'cmtls_teaser';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['comment|comment_node_cmtls_app|cmtls_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_cmtls_app|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_cmtls_app';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_cmtls_timeago',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['comment|comment_node_cmtls_app|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_cmtls_group|cmtls_teaser';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_cmtls_group';
  $ds_fieldsetting->view_mode = 'cmtls_teaser';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['comment|comment_node_cmtls_group|cmtls_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_cmtls_group|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_cmtls_group';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_cmtls_timeago',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['comment|comment_node_cmtls_group|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_cmtls_location|cmtls_teaser';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_cmtls_location';
  $ds_fieldsetting->view_mode = 'cmtls_teaser';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['comment|comment_node_cmtls_location|cmtls_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_cmtls_location|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_cmtls_location';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'cmtls_comment_spam_flag_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:8:"sanitize";i:0;s:7:"context";s:28:"argument_entity_id:comment_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:5:"token";s:7:"subtype";s:45:"comment:flag-cmtls-inappropriate-comment-link";}',
        'load_terms' => 0,
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_cmtls_timeago',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['comment|comment_node_cmtls_location|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cmtls_app|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cmtls_app';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '40',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cmtls_app|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cmtls_group|cmtls_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cmtls_group';
  $ds_fieldsetting->view_mode = 'cmtls_teaser';
  $ds_fieldsetting->settings = array(
    'cmtls_group_members' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'cmtls_group_subscription' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|cmtls_group|cmtls_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cmtls_group|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cmtls_group';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '40',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cmtls_group|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cmtls_location|cmtls_location_bare';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cmtls_location';
  $ds_fieldsetting->view_mode = 'cmtls_location_bare';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|cmtls_location|cmtls_location_bare'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cmtls_location|cmtls_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cmtls_location';
  $ds_fieldsetting->view_mode = 'cmtls_teaser';
  $ds_fieldsetting->settings = array(
    'cmtls_comments_count' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'cmtls_location_indicator' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|cmtls_location|cmtls_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cmtls_location|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cmtls_location';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cmtls_location|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|cmtls_teaser';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'cmtls_teaser';
  $ds_fieldsetting->settings = array(
    'name' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['user|user|cmtls_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'ds_user_picture' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cmtls_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cmtls_comment_spam_flag_link';
  $ds_field->label = 'CT comment spam flag link';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'comment' => 'comment',
  );
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['cmtls_comment_spam_flag_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cmtls_comments_count';
  $ds_field->label = 'Comments count';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php

print views_embed_view(\'cmtls_common_elements\', \'cmtls_common_comment_count_block\', $entity->nid);
',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['cmtls_comments_count'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cmtls_group_members';
  $ds_field->label = 'Group members';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php return cmtls_group_ds_members_field($entity);',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['cmtls_group_members'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cmtls_group_subscription';
  $ds_field->label = 'Group subscription';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php print cmtls_group_ds_subscription_field($entity);',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['cmtls_group_subscription'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cmtls_location_indicator';
  $ds_field->label = 'Location indicator';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php

if(isset($entity->field_cmtls_geometry[LANGUAGE_NONE][0][\'wkt\']) && $entity->field_cmtls_geometry[LANGUAGE_NONE][0][\'wkt\']) {
  echo \'<div class="cmtls-location-indicator"><span>Geotagged</span></div>\';
}',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['cmtls_location_indicator'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cmtls_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_cmtls_app|cmtls_teaser';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_cmtls_app';
  $ds_layout->view_mode = 'cmtls_teaser';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'ds_user_picture',
        1 => 'author',
      ),
      'middle' => array(
        0 => 'comment_body',
      ),
      'footer' => array(
        0 => 'post_date',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left_column',
      'author' => 'left_column',
      'comment_body' => 'middle',
      'post_date' => 'footer',
    ),
    'classes' => array(),
  );
  $export['comment|comment_node_cmtls_app|cmtls_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_cmtls_app|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_cmtls_app';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'ds_user_picture',
      ),
      'middle' => array(
        0 => 'author',
        1 => 'post_date',
        2 => 'comment_body',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left_column',
      'author' => 'middle',
      'post_date' => 'middle',
      'comment_body' => 'middle',
    ),
    'classes' => array(),
  );
  $export['comment|comment_node_cmtls_app|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_cmtls_group|cmtls_teaser';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_cmtls_group';
  $ds_layout->view_mode = 'cmtls_teaser';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'ds_user_picture',
        1 => 'author',
      ),
      'middle' => array(
        0 => 'comment_body',
      ),
      'footer' => array(
        0 => 'post_date',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left_column',
      'author' => 'left_column',
      'comment_body' => 'middle',
      'post_date' => 'footer',
    ),
    'classes' => array(),
  );
  $export['comment|comment_node_cmtls_group|cmtls_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_cmtls_group|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_cmtls_group';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'ds_user_picture',
      ),
      'middle' => array(
        0 => 'author',
        1 => 'post_date',
        2 => 'comment_body',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left_column',
      'author' => 'middle',
      'post_date' => 'middle',
      'comment_body' => 'middle',
    ),
    'classes' => array(),
  );
  $export['comment|comment_node_cmtls_group|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_cmtls_location|cmtls_teaser';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_cmtls_location';
  $ds_layout->view_mode = 'cmtls_teaser';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'ds_user_picture',
        1 => 'author',
      ),
      'middle' => array(
        0 => 'comment_body',
      ),
      'footer' => array(
        0 => 'post_date',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left_column',
      'author' => 'left_column',
      'comment_body' => 'middle',
      'post_date' => 'footer',
    ),
    'classes' => array(),
  );
  $export['comment|comment_node_cmtls_location|cmtls_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_cmtls_location|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_cmtls_location';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'ds_user_picture',
      ),
      'middle' => array(
        0 => 'author',
        1 => 'post_date',
        2 => 'comment_body',
      ),
      'footer' => array(
        0 => 'cmtls_comment_spam_flag_link',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left_column',
      'author' => 'middle',
      'post_date' => 'middle',
      'comment_body' => 'middle',
      'cmtls_comment_spam_flag_link' => 'footer',
    ),
    'classes' => array(),
  );
  $export['comment|comment_node_cmtls_location|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_app|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_app';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'comments',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|cmtls_app|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_group|cmtls_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_group';
  $ds_layout->view_mode = 'cmtls_teaser';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'middle' => array(
        0 => 'title',
        1 => 'body',
      ),
      'right_column' => array(
        0 => 'cmtls_group_subscription',
      ),
      'footer' => array(
        0 => 'cmtls_group_members',
        1 => 'field_cmtls_location',
      ),
      'left_column' => array(
        0 => 'field_cmtls_group_avatar',
      ),
    ),
    'fields' => array(
      'title' => 'middle',
      'cmtls_group_subscription' => 'right_column',
      'cmtls_group_members' => 'footer',
      'body' => 'middle',
      'field_cmtls_group_avatar' => 'left_column',
      'field_cmtls_location' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|cmtls_group|cmtls_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_group|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_group';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'classes' => array(),
  );
  $export['node|cmtls_group|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_location|cmtls_location_bare';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_location';
  $ds_layout->view_mode = 'cmtls_location_bare';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'middle' => array(
        0 => 'title',
      ),
      'footer' => array(
        0 => 'field_cmtls_tags',
      ),
    ),
    'fields' => array(
      'title' => 'middle',
      'field_cmtls_tags' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|cmtls_location|cmtls_location_bare'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_location|cmtls_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_location';
  $ds_layout->view_mode = 'cmtls_teaser';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'middle' => array(
        0 => 'title',
        1 => 'body',
      ),
      'footer' => array(
        0 => 'cmtls_location_indicator',
        1 => 'field_cmtls_address',
        2 => 'field_cmtls_tags',
        3 => 'cmtls_comments_count',
      ),
    ),
    'fields' => array(
      'title' => 'middle',
      'body' => 'middle',
      'cmtls_location_indicator' => 'footer',
      'field_cmtls_address' => 'footer',
      'field_cmtls_tags' => 'footer',
      'cmtls_comments_count' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|cmtls_location|cmtls_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_location|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_location';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'comments',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|cmtls_location|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_location|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_location';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_cmtls_tags',
        2 => 'body',
        3 => 'field_cmtls_attachments',
      ),
      'right' => array(
        0 => 'field_cmtls_geometry',
        1 => 'field_cmtls_address',
        2 => 'field_cmtls_location',
      ),
      'footer' => array(
        0 => 'group_advanced',
        1 => 'group_content_access',
        2 => 'group_audience',
        3 => 'group_hidden',
        4 => 'field_cmtls_application',
      ),
      'hidden' => array(
        0 => 'path',
        1 => 'redirect',
        2 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_cmtls_tags' => 'left',
      'body' => 'left',
      'field_cmtls_attachments' => 'left',
      'field_cmtls_geometry' => 'right',
      'field_cmtls_address' => 'right',
      'field_cmtls_location' => 'right',
      'group_advanced' => 'footer',
      'path' => 'hidden',
      'redirect' => 'hidden',
      'group_content_access' => 'footer',
      'group_audience' => 'footer',
      'group_hidden' => 'footer',
      '_add_existing_field' => 'hidden',
      'field_cmtls_application' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|cmtls_location|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|cmtls_teaser';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'cmtls_teaser';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'ds_user_picture',
      ),
      'middle' => array(
        0 => 'name',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left_column',
      'name' => 'middle',
    ),
    'classes' => array(),
  );
  $export['user|user|cmtls_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_cmtls_description',
        1 => 'ds_user_picture',
      ),
    ),
    'fields' => array(
      'field_cmtls_description' => 'ds_content',
      'ds_user_picture' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['user|user|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function cmtls_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'cmtls_location_bare';
  $ds_view_mode->label = 'CT Location bare';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['cmtls_location_bare'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'cmtls_teaser';
  $ds_view_mode->label = 'CT teaser';
  $ds_view_mode->entities = array(
    'comment' => 'comment',
    'node' => 'node',
    'user' => 'user',
  );
  $export['cmtls_teaser'] = $ds_view_mode;

  return $export;
}
