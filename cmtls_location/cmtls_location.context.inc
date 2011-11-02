<?php
/**
 * @file
 * cmtls_location.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function cmtls_location_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT location meta blocks';
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
  $export['CT location meta blocks'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT locations wall';
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
  $export['CT locations wall'] = $context;

  return $export;
}
