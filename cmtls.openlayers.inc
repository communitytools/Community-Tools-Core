<?php
/**
 * @file
 * cmtls.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function cmtls_openlayers_maps() {
  $export = array();
  
  // Get the CT marker vocabulary.
  $taxonomy = cmtls_get_taxonomy('cmtls_marker');
  
  $terms = $taxonomy['terms'];
  $voc = $taxonomy['vocabulary'];
  
  // Global map.
  $layers = array();
  $layer_weights = array();
  $layer_styles = array();
  
  foreach ($terms as $i => $term) {
    /* Display: OpenLayers Taxonomy Data Overlay */
    $layers['cmtls_global_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 'cmtls_global_marker_layers_' . $voc->machine_name .'_' . $term->tid;
    $layer_weights['cmtls_global_marker_layers_' . $voc->machine_name .'_' . $term->tid] = $i;
    $layer_styles['cmtls_global_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 'cmtls_dynamic_marker';
  }
  
  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cmtls_map_global_full';
  $openlayers_maps->title = 'CT global map';
  $openlayers_maps->description = 'Full map with all the content, layers and functions';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '500px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    // TODO: set / and get the default center, zoom, restricts
    'center' => array(
      'initial' => array(
        'centerpoint' => '24.745746999744, 59.430052559193',
        'zoom' => '12',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 1,
        'panIcons' => 1,
      ),
      'openlayers_behavior_permalink' => array(
        'anchor' => 0,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => $layers,
      ),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
      // TODO: this needs to be dynamic
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'google_normal' => 'google_normal',
      'osm_mapnik' => 'osm_mapnik',
    ) + $layers,
    'layer_weight' => $layer_weights,
    'layer_styles' => $layer_styles,
    'layer_styles_select' => $layer_styles,
    'layer_activated' => $layers,
    'layer_switcher' => $layers,
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  
  $export['cmtls_map_global_full'] = $openlayers_maps;

  // Application map.
  $layers = array();
  $layer_weights = array();
  $layer_styles = array();
  
  foreach ($terms as $i => $term) {
    /* Display: OpenLayers Taxonomy Data Overlay */
    $layers['cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 'cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid;
    $layer_weights['cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid] = $i;
    $layer_styles['cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 'cmtls_dynamic_marker';
  }

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cmtls_map_application_full';
  $openlayers_maps->title = 'CT application map';
  $openlayers_maps->description = 'Full map with all the application content, layers and functions';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '500px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    // TODO: set / and get the default center, zoom, restricts
    'center' => array(
      'initial' => array(
        'centerpoint' => '24.745746999744, 59.430052559193',
        'zoom' => '12',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 1,
        'panIcons' => 1,
      ),
      'openlayers_behavior_permalink' => array(
        'anchor' => 0,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => $layers,
      ),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
      // TODO: this needs to be dynamic
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'google_normal' => 'google_normal',
      'osm_mapnik' => 'osm_mapnik',
    ) + $layers,
    'layer_weight' => $layer_weights,
    'layer_styles' => $layer_styles,
    'layer_styles_select' => $layer_styles,
    'layer_activated' => $layers,
    'layer_switcher' => $layers,
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  
  $export['cmtls_map_application_full'] = $openlayers_maps;

  // Group map.
  $layers = array();
  $layer_weights = array();
  $layer_styles = array();
  
  foreach ($terms as $i => $term) {
    /* Display: OpenLayers Taxonomy Data Overlay */
    $layers['cmtls_group_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 'cmtls_group_marker_layers_' . $voc->machine_name .'_' . $term->tid;
    $layer_weights['cmtls_group_marker_layers_' . $voc->machine_name .'_' . $term->tid] = $i;
    $layer_styles['cmtls_group_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 'cmtls_dynamic_marker';
  }

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cmtls_map_group_full';
  $openlayers_maps->title = 'CT group map';
  $openlayers_maps->description = 'Full map with all the group content, layers and functions';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '500px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    // TODO: set / and get the default center, zoom, restricts
    'center' => array(
      'initial' => array(
        'centerpoint' => '24.745746999744, 59.430052559193',
        'zoom' => '12',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 1,
        'panIcons' => 1,
      ),
      'openlayers_behavior_permalink' => array(
        'anchor' => 0,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => $layers,
      ),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
      // TODO: this needs to be dynamic
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'google_normal' => 'google_normal',
      'osm_mapnik' => 'osm_mapnik',
    ) + $layers,
    'layer_weight' => $layer_weights,
    'layer_styles' => $layer_styles,
    'layer_styles_select' => $layer_styles,
    'layer_activated' => $layers,
    'layer_switcher' => $layers,
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  
  $export['cmtls_map_group_full'] = $openlayers_maps;

  return $export;
}
