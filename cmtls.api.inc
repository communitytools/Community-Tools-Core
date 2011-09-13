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

/**
 * Example hook for app config
 * 
 * @param $config existing configuration values
 */
function hook_cmtls_app_config($config) {
  // form API fields  
  $form['example_app_type'] = array(
    '#type' => 'fieldset',
    '#title' => t('Example settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['example_app_type']['example_field'] = array(
    '#type' => 'radios',
    '#title' => t('Example field'),
    '#options' => array(
    ),
  );
  
  return $form;
}
