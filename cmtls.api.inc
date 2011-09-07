<?php
/**
 * @file
 * Hooks provided by Community Tools.
 */

/**
 * Example hook for apps
 */
function hook_cmtls_app() {
  return array(
    'example_app_type' => array( //same as module name
      'title' => t('Example'),
      'description' => t('Example description'),
      'node types' => array(
        'example_node_type' => t('Example'), // the machine name of the node type => human readable title
      ),
    ),
  );
}
