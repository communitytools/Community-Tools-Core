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
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cmtls_image_default_styles() {
  $styles = array();

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
