<?php
/**
 * @file
 * Context plugins
 * Core default contexts
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function cmtls_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT Location meta blocks';
  $context->description = 'Community Tools location metadata blocks';
  $context->tag = 'cmtls';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmtls_location' => 'cmtls_location',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cmtls_location_tags-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_location_tags-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-cmtls_location_location-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_location_location-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-cmtls_location_attachments-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_location_attachments-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Tools location metadata blocks');
  t('cmtls');
  $export['CT Location meta blocks'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT Locations wall';
  $context->description = 'Community Tools locations list';
  $context->tag = 'cmtls';
  $context->conditions = array(
    'cmtls_app_type' => array(
      'values' => array(
        'cmtls_location' => 'cmtls_location',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'node' => array(
      'values' => array(
        'cmtls_app' => 'cmtls_app',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cmtls_locations-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_locations-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Tools locations list');
  t('cmtls');
  $export['CT Locations wall'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT Group meta blocks';
  $context->description = 'Community Tools group metadata blocks';
  $context->tag = 'cmtls';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmtls_group' => 'cmtls_group',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cmtls_group_location-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_group_location-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-cmtls_group_comments-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_group_comments-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-cmtls_group_members-block_1' => array(
          'module' => 'views',
          'delta' => 'cmtls_group_members-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Tools group metadata blocks');
  t('cmtls');
  $export['CT Group meta blocks'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT Group wall';
  $context->description = 'Community Tools group content';
  $context->tag = 'cmtls';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmtls_group' => 'cmtls_group',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cmtls_group_wall-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_group_wall-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Tools group content');
  t('cmtls');
  $export['CT Group wall'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT User profile blocks';
  $context->description = 'Community Tools user profile blocks';
  $context->tag = 'cmtls';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cmtls_user_comments-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_user_comments-block',
          'region' => 'content',
          'weight' => '-25',
        ),
        'views-552bae0735a41b5d602460a160796d1d' => array(
          'module' => 'views',
          'delta' => '552bae0735a41b5d602460a160796d1d',
          'region' => 'content',
          'weight' => '-24',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Tools user profile blocks');
  t('cmtls');
  $export['CT User profile blocks'] = $context;

  return $export;
}
 
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
