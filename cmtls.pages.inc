<?php

function cmtls_add_content_page($node) {
  $goto_options = array();

  // get parent menu by path node/$node->nid
  $query = db_select('menu_links', 'menu_links')
    ->fields('menu_links', array('mlid'))
    ->condition('menu_links.link_path', 'node/' . $node->nid, '=');
  if($mlid = $query->execute()->fetchField()) {
    $goto_options['query']['mlid'] = $mlid;
  }

  // group preselect for apps
  if($node->type == 'cmtls_group') {
    $groups = og_get_group_ids('node', array($node->nid));
    $goto_options['query']['gid'] = $groups[$node->nid];
    drupal_goto('node/add/cmtls-app', $goto_options);
  }
  // group and app preselect for content nodes
  elseif($node->type == 'cmtls_app') {
    $groups = og_get_entity_groups('node', $node);
    $goto_options['query']['gid'] = array_shift($groups);
    $goto_options['query']['aid'] = $node->nid;
    $type = array_pop(array_keys(cmtls_get_app_content_types($node->cmtls_app_type)));  // multiple types yet to resolve
    drupal_goto('node/add/' . str_replace('_', '-', $type), $goto_options);
  }
  // group and app preselect for content nodes
  elseif(in_array($node->type, array_keys(cmtls_get_app_content_types()))) {
    $groups = og_get_entity_groups('node', $node);
    $goto_options['query']['gid'] = array_shift($groups);
    $goto_options['query']['aid'] = $node->field_cmtls_application[LANGUAGE_NONE][0]['nid'];
    drupal_goto('node/add/' . str_replace('_', '-', $node->type), $goto_options);
  }
  else {
    drupal_goto('node/'.$node->nid);
  }
}

/**
 * Autocompletes locations
 */
function cmtls_location_autocomplete($string = '') {
  $matches = array();

  if(strlen($string) > 1) {
    $query = db_select('location', 'location')
      ->fields('field_data_field_cmtls_location', array('entity_type', 'entity_id'))
      ->fields('location')
      ->condition('field_data_field_cmtls_location.bundle', 'cmtls_location', '=')
      ->condition('location.name', $string.'%', 'LIKE')
      ->range(0, 5);
    $query->join('field_data_field_cmtls_location', 'field_data_field_cmtls_location', 'location.lid = field_data_field_cmtls_location.field_cmtls_location_lid');
    $result = $query->execute();

    while($location = $result->fetchAssoc()) {
      // check for permissions ... is this right?
      if(entity_load_single($location['entity_type'], $location['entity_id'])) {
        if(isset($location['latitude']) && $location['latitude'] != 0.000000) {
          $location['locpick-user-latitude'] = $location['latitude'];
        }
        if(isset($location['longitude']) && $location['longitude'] != 0.000000) {
          $location['locpick-user-longitude'] = $location['longitude'];
        }
        $matches[] = $location;
      }
    }
  }

  drupal_json_output($matches);
}
