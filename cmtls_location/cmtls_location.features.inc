<?php
/**
 * @file
 * cmtls_location.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cmtls_location_ctools_plugin_api() {
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
function cmtls_location_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function cmtls_location_node_info() {
  $items = array(
    'cmtls_location' => array(
      'name' => t('CT location'),
      'base' => 'node_content',
      'description' => t('Community Tools basic content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
