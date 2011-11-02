<?php
/**
 * @file
 * cmtls_location.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function cmtls_location_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_cmtls_location';
  $strongarm->value = 'edit-group';
  $export['additional_settings__active_tab_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cmtls_location';
  $strongarm->value = 0;
  $export['comment_anonymous_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cmtls_location';
  $strongarm->value = '2';
  $export['comment_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cmtls_location';
  $strongarm->value = 0;
  $export['comment_default_mode_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cmtls_location';
  $strongarm->value = '50';
  $export['comment_default_per_page_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cmtls_location';
  $strongarm->value = 1;
  $export['comment_form_location_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cmtls_location';
  $strongarm->value = '1';
  $export['comment_preview_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cmtls_location';
  $strongarm->value = 0;
  $export['comment_subject_field_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cmtls_location';
  $strongarm->value = array();
  $export['menu_options_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cmtls_location';
  $strongarm->value = 'menu-cmtls:0';
  $export['menu_parent_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cmtls_location';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cmtls_location';
  $strongarm->value = '1';
  $export['node_preview_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cmtls_location';
  $strongarm->value = 1;
  $export['node_submitted_cmtls_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_cmtls_location';
  $strongarm->value = 'omitted';
  $export['og_group_type_cmtls_location'] = $strongarm;

  return $export;
}
