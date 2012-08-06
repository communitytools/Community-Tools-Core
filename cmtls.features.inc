<?php
/**
 * @file
 * cmtls.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmtls_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cmtls_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function cmtls_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow".
  $flags['cmtls_app_follow'] = array(
    'content_type' => 'node',
    'title' => 'Follow',
    'global' => '0',
    'types' => array(
      0 => 'cmtls_app',
    ),
    'flag_short' => 'Follow',
    'flag_long' => 'Subscribe to [node:title]',
    'flag_message' => 'You are now subscribed to [node:title]',
    'unflag_short' => 'Unfollow',
    'unflag_long' => 'Unsubscribe from [node:title]',
    'unflag_message' => 'You are now unsubscribed from [node:title]',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'show_contextual_link' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cmtls',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Daily newsletter".
  $flags['cmtls_daily_newsletter'] = array(
    'content_type' => 'user',
    'title' => 'Daily newsletter',
    'global' => '0',
    'types' => array(),
    'flag_short' => 'Receive daily newsletter',
    'flag_long' => 'Receive daily newsletter about new content and comments in your subscribed groups, apps and threads',
    'flag_message' => 'You will now receive daily newsletter about new content',
    'unflag_short' => 'Turn off daily newsletter',
    'unflag_long' => 'Turn off daily newsletter about new content and comments',
    'unflag_message' => 'You will no longer receive daily newsletter about new content',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_profile' => 1,
    'access_uid' => '',
    'module' => 'cmtls',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Follow".
  $flags['cmtls_group_follow'] = array(
    'content_type' => 'node',
    'title' => 'Follow',
    'global' => '0',
    'types' => array(
      0 => 'cmtls_group',
    ),
    'flag_short' => 'Follow',
    'flag_long' => 'Subscribe to [node:title]',
    'flag_message' => 'You are now subscribed to [node:title]',
    'unflag_short' => 'Unfollow',
    'unflag_long' => 'Unsubscribe from [node:title]',
    'unflag_message' => 'You are now unsubscribed from [node:title]',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'show_contextual_link' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cmtls',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Instant notifications".
  $flags['cmtls_instant_notifications'] = array(
    'content_type' => 'user',
    'title' => 'Instant notifications',
    'global' => '0',
    'types' => array(),
    'flag_short' => 'Receive instant notifications',
    'flag_long' => 'Receive instantly notifications about new content and comments in your subscribed groups, apps and threads',
    'flag_message' => 'You will now receive notifications about new content',
    'unflag_short' => 'Turn off instant notifications',
    'unflag_long' => 'Turn off instant notifications about new content and comments',
    'unflag_message' => 'You will no longer receive notifications about new content',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_profile' => 1,
    'access_uid' => '',
    'module' => 'cmtls',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Follow".
  $flags['cmtls_location_follow'] = array(
    'content_type' => 'node',
    'title' => 'Follow',
    'global' => '0',
    'types' => array(
      0 => 'cmtls_location',
    ),
    'flag_short' => 'Follow',
    'flag_long' => 'Subscribe to [node:title]',
    'flag_message' => 'You are now subscribed to [node:title]',
    'unflag_short' => 'Unfollow',
    'unflag_long' => 'Unsubscribe from [node:title]',
    'unflag_message' => 'You are now unsubscribed from [node:title]',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'show_contextual_link' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cmtls',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implements hook_image_default_styles().
 */
function cmtls_image_default_styles() {
  $styles = array();

  // Exported image style: cmtls_header
  $styles['cmtls_header'] = array(
    'name' => 'cmtls_header',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '1680',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: cmtls_small
  $styles['cmtls_small'] = array(
    'name' => 'cmtls_small',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '85',
          'height' => '85',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cmtls_node_info() {
  $items = array(
    'cmtls_app' => array(
      'name' => t('Application'),
      'base' => 'node_content',
      'description' => t('Community Tools application'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'cmtls_group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('Community Tools group.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'cmtls_location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => t('Community Tools locations'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
