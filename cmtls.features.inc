<?php
/**
 * @file
 * cmtls.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cmtls_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function cmtls_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function cmtls_node_info() {
  $items = array(
    'cmtls_app' => array(
      'name' => t('CT Application'),
      'base' => 'node_content',
      'description' => t('Community Tools application, defines the content type etc'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'cmtls_group' => array(
      'name' => t('CT Group'),
      'base' => 'node_content',
      'description' => t('Community Tools group, Organic Groups.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
