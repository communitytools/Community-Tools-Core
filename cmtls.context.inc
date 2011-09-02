<?php
/**
 * @file
 * cmtls.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function cmtls_context_default_contexts() {
  $export = array();

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
        'views-cmtls_group_members-block_1' => array(
          'module' => 'views',
          'delta' => 'cmtls_group_members-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
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
          'weight' => '-10',
        ),
        'views-552bae0735a41b5d602460a160796d1d' => array(
          'module' => 'views',
          'delta' => '552bae0735a41b5d602460a160796d1d',
          'region' => 'content',
          'weight' => '-9',
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
