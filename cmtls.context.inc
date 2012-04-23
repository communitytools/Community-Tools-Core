<?php
/**
 * @file
 * cmtls.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cmtls_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmtls_app_page';
  $context->description = 'Community Tools app page';
  $context->tag = 'CT app';
  $context->conditions = array(
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
        'views-cb129c8a19431ae6b2fd1711646e2de2' => array(
          'module' => 'views',
          'delta' => 'cb129c8a19431ae6b2fd1711646e2de2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-cmtls_common_elements-block_1' => array(
          'module' => 'views',
          'delta' => 'cmtls_common_elements-block_1',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT app');
  t('Community Tools app page');
  $export['cmtls_app_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmtls_group_action_block';
  $context->description = 'Shows the action buttons block for groups';
  $context->tag = 'CT group';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT group');
  t('Shows the action buttons block for groups');
  $export['cmtls_group_action_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmtls_group_page';
  $context->description = 'Community Tools group page';
  $context->tag = 'CT group';
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
        'views-cmtls_applications-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_applications-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-529099a455b0fa960718b1af2e03cae6' => array(
          'module' => 'views',
          'delta' => '529099a455b0fa960718b1af2e03cae6',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-cmtls_media-block_1' => array(
          'module' => 'views',
          'delta' => 'cmtls_media-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-cb129c8a19431ae6b2fd1711646e2de2' => array(
          'module' => 'views',
          'delta' => 'cb129c8a19431ae6b2fd1711646e2de2',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-e77b8b5723833505a9050ca84e36015c' => array(
          'module' => 'views',
          'delta' => 'e77b8b5723833505a9050ca84e36015c',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-46d8ed88f8cfdc87b69f60ac1c127427' => array(
          'module' => 'views',
          'delta' => '46d8ed88f8cfdc87b69f60ac1c127427',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-cmtls_common_elements-block_1' => array(
          'module' => 'views',
          'delta' => 'cmtls_common_elements-block_1',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT group');
  t('Community Tools group page');
  $export['cmtls_group_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmtls_location_page';
  $context->description = 'Community Tools single location page';
  $context->tag = 'CT location';
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
        'views-cb129c8a19431ae6b2fd1711646e2de2' => array(
          'module' => 'views',
          'delta' => 'cb129c8a19431ae6b2fd1711646e2de2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-d3b739be3a716e61b54f0c1254eefd60' => array(
          'module' => 'views',
          'delta' => 'd3b739be3a716e61b54f0c1254eefd60',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-53e22d565fc4333e016372c7c33e1bfc' => array(
          'module' => 'views',
          'delta' => '53e22d565fc4333e016372c7c33e1bfc',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-cmtls_common_elements-block_2' => array(
          'module' => 'views',
          'delta' => 'cmtls_common_elements-block_2',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT location');
  t('Community Tools single location page');
  $export['cmtls_location_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmtls_locations_page';
  $context->description = 'Community Tools locations page';
  $context->tag = 'CT location';
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
        'views-cmtls_locations-block_1' => array(
          'module' => 'views',
          'delta' => 'cmtls_locations-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-70e4ff6f0b0b36bd4a7ff6e634319a80' => array(
          'module' => 'views',
          'delta' => '70e4ff6f0b0b36bd4a7ff6e634319a80',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT location');
  t('Community Tools locations page');
  $export['cmtls_locations_page'] = $context;

  return $export;
}
