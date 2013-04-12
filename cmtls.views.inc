<?php
/**
 * @file
 * cmtls.views.inc
 */

function cmtls_add_layers($view, $group = FALSE, $app = FALSE) {
  // Get the CT marker vocabulary
  $taxonomy = cmtls_get_taxonomy('cmtls_marker');
  
  $terms = $taxonomy['terms'];
  $voc = $taxonomy['vocabulary'];
  
  // Add CT marker vocabulary terms as layers (openlayers_taxonomy).
  foreach ($terms as $term) {
    /* Display: OpenLayers Taxonomy Data Overlay */
    $handler = $view->new_display('openlayers', $voc->name . ' - ' . $term->name, $voc->machine_name .'_' . $term->tid);
    $handler->display->display_options['title'] = 'Taxonomy layer';
    $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    if($group) {
      /* Contextual filter: OG membership: OG group gid */
      $handler->display->display_options['arguments']['group']['id'] = 'group';
      $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
      $handler->display->display_options['arguments']['group']['field'] = 'group';
      $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
      $handler->display->display_options['arguments']['group']['default_action'] = 'default';
      $handler->display->display_options['arguments']['group']['exception']['value'] = '';
      $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
      $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
      $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
      $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
      $handler->display->display_options['arguments']['group']['specify_validation'] = TRUE;
      $handler->display->display_options['arguments']['group']['validate']['type'] = 'og';
    }
    if($app) {
      /* Contextual filter: Content: Application (field_cmtls_application) */
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_action'] = 'default';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['exception']['value'] = '';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'node';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['specify_validation'] = TRUE;
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['validate']['type'] = 'node';
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['validate_options']['types'] = array(
        'cmtls_app' => 'cmtls_app',
      );
      $handler->display->display_options['arguments']['field_cmtls_application_nid']['validate_options']['access'] = TRUE;
    }
    /* Contextual filter: Content: Has taxonomy term ID (with depth) */
    $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
    $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
    $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
    $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
    $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
    $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = ($group || $app ? '%2' :'%1');
    $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['argument'] = $term->tid;
    $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
    $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
    $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
    $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
    /* Contextual filter: Content: Has taxonomy term ID depth modifier */
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  }

  return $view;
}
 
/**
 * Implements hook_views_default_views().
 * 
 * Creates the dynamic taxonomy based layers for Openlayers
 */
function cmtls_views_default_views() {
  $views = array();
  
  // Global map layers
  $view = new view();
  $view->name = 'cmtls_global_marker_layers';
  $view->description = 'Markers at the global level';
  $view->tag = 'cmtls';
  $view->base_table = 'node';
  $view->human_name = 'CT global marker layers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_cmtls_geometry',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'body',
    'view_mode' => 'full',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Marker (field_cmtls_map_marker) */
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['id'] = 'field_cmtls_map_marker_tid';
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['table'] = 'field_data_field_cmtls_map_marker';
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['field'] = 'field_cmtls_map_marker_tid';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['id'] = 'taxonomy_term_to_file';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['field'] = 'taxonomy_term_to_file';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['relationship'] = 'field_cmtls_map_marker_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Map */
  $handler->display->display_options['fields']['field_cmtls_geometry']['id'] = 'field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['table'] = 'field_data_field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['field'] = 'field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['label'] = '';
  $handler->display->display_options['fields']['field_cmtls_geometry']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmtls_geometry']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_cmtls_geometry']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'taxonomy_term_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['empty'] = '/sites/all/modules/cmtls/images/default_marker.png';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  
  $view = cmtls_add_layers($view);
  
  $views[$view->name] = $view;

  // Group map layers
  $view = new view();
  $view->name = 'cmtls_group_marker_layers';
  $view->description = 'Markers at the group level';
  $view->tag = 'cmtls';
  $view->base_table = 'node';
  $view->human_name = 'CT group marker layers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_cmtls_geometry',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'body',
    'view_mode' => 'full',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Marker (field_cmtls_map_marker) */
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['id'] = 'field_cmtls_map_marker_tid';
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['table'] = 'field_data_field_cmtls_map_marker';
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['field'] = 'field_cmtls_map_marker_tid';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['id'] = 'taxonomy_term_to_file';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['field'] = 'taxonomy_term_to_file';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['relationship'] = 'field_cmtls_map_marker_tid';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Map */
  $handler->display->display_options['fields']['field_cmtls_geometry']['id'] = 'field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['table'] = 'field_data_field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['field'] = 'field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['label'] = '';
  $handler->display->display_options['fields']['field_cmtls_geometry']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmtls_geometry']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_cmtls_geometry']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'taxonomy_term_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['empty'] = '/sites/all/modules/cmtls/images/default_marker.png';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Contextual filter: OG membership: OG group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['exception']['value'] = '';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['group']['validate']['type'] = 'og';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  
  $view = cmtls_add_layers($view, TRUE);
  
  $views[$view->name] = $view;
  
  $view = new view();
  $view->name = 'cmtls_application_marker_layers';
  $view->description = 'Markers at the application level';
  $view->tag = 'cmtls';
  $view->base_table = 'node';
  $view->human_name = 'CT application marker layers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_cmtls_geometry',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'body',
    'view_mode' => 'full',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Marker (field_cmtls_map_marker) */
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['id'] = 'field_cmtls_map_marker_tid';
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['table'] = 'field_data_field_cmtls_map_marker';
  $handler->display->display_options['relationships']['field_cmtls_map_marker_tid']['field'] = 'field_cmtls_map_marker_tid';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['id'] = 'taxonomy_term_to_file';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['field'] = 'taxonomy_term_to_file';
  $handler->display->display_options['relationships']['taxonomy_term_to_file']['relationship'] = 'field_cmtls_map_marker_tid';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: Content: Application (field_cmtls_application) */
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Map */
  $handler->display->display_options['fields']['field_cmtls_geometry']['id'] = 'field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['table'] = 'field_data_field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['field'] = 'field_cmtls_geometry';
  $handler->display->display_options['fields']['field_cmtls_geometry']['label'] = '';
  $handler->display->display_options['fields']['field_cmtls_geometry']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmtls_geometry']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_cmtls_geometry']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'taxonomy_term_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['empty'] = '/sites/all/modules/cmtls/images/default_marker.png';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['validate_options']['types'] = array(
    'cmtls_app' => 'cmtls_app',
  );
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['validate_options']['access'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  
  $view = cmtls_add_layers($view, FALSE, TRUE);
  
  $views[$view->name] = $view;

  return $views;
}

/**
 * Implements hook_taxonomy_term_delete().
 */
function cmtls_taxonomy_term_delete($term) {
  // Flush the cache if we're creating, editing, or deleting a term
  views_invalidate_cache();
}

/**
 * Implements hook_taxonomy_term_presave().
 */
function cmtls_taxonomy_term_presave($term) {
  // Flush the cache if we're creating, editing, or deleting a term
  views_invalidate_cache();
}
