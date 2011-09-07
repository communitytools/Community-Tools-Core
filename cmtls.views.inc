<?php
/**
 * @file
 * Views plugins for CT
 */

/**
 * Implements hook_views_data_alter()
 * to change node type filter
 */
function cmtls_views_data_alter(&$data) {
  $data['node']['type']['filter']['handler'] = 'views_handler_filter_cmtls_node_type';
}
