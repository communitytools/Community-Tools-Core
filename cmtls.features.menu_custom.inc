<?php
/**
 * @file
 * cmtls.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function cmtls_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-cmtls
  $menus['menu-cmtls'] = array(
    'menu_name' => 'menu-cmtls',
    'title' => 'CT Menu',
    'description' => 'Community Tools group and applications menu',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CT Menu');
  t('Community Tools group and applications menu');


  return $menus;
}
