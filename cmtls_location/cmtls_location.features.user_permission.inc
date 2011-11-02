<?php
/**
 * @file
 * cmtls_location.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_location_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_location content
  $permissions['create cmtls_location content'] = array(
    'name' => 'create cmtls_location content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any cmtls_location content
  $permissions['delete any cmtls_location content'] = array(
    'name' => 'delete any cmtls_location content',
    'roles' => array(),
  );

  // Exported permission: delete own cmtls_location content
  $permissions['delete own cmtls_location content'] = array(
    'name' => 'delete own cmtls_location content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any cmtls_location content
  $permissions['edit any cmtls_location content'] = array(
    'name' => 'edit any cmtls_location content',
    'roles' => array(),
  );

  // Exported permission: edit own cmtls_location content
  $permissions['edit own cmtls_location content'] = array(
    'name' => 'edit own cmtls_location content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
