<?php
/**
 * @file
 * Custom context conditions for CT
 */

/**
 * Implements hook_context_plugins()
 */
function cmtls_context_plugins() {
  $plugins = array();
  $plugins['cmtls_context_condition_app_type'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'cmtls') .'/plugins',
      'file' => 'cmtls_context_condition_app_type.inc',
      'class' => 'cmtls_context_condition_app_type',
      'parent' => 'context_condition_node',
    ),
  );
  return $plugins;
}

/**
 * Implements hook_context_registry()
 */
function cmtls_context_registry() {
  return array(
    'conditions' => array(
      'cmtls_app_type' => array(
        'title' => t('CT Application type'),
        'plugin' => 'cmtls_context_condition_app_type',
      ),
    ),
  );
}

/**
 * Implements hook_context_node_condition_alter()
 * 
 * adds the 'cmtls_app_type' condition to nodes
 */
function cmtls_context_node_condition_alter(&$node, $op) {
  if ($plugin = context_get_plugin('condition', 'cmtls_app_type')) {
    $plugin->execute($node, $op);
  }
}
