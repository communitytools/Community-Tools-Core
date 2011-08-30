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
    'example_content_type' => array(
      'title' => t('Example'),
      'description' => t('Example description'),
    ),
  );
}
