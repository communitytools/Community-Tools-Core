<?php
/**
 * @file
 * cmtls.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function cmtls_openlayers_maps() {
  // Defaults setting map.
  $export = array();
  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cmtls_map_defaults';
  $openlayers_maps->title = 'CT map defaults';
  $openlayers_maps->description = 'Default settings for other CT maps';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '500px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 0',
        'zoom' => '1',
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
        'sortBaseLayer' => '0',
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
        'maximizeDefault' => 0,
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
        'layers' => array(),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'google_normal' => 'google_normal',
      'osm_mapnik' => 'osm_mapnik',
    ),
    'layer_weight' => array(
    ),
    'layer_styles' => array(
    ),
    'layer_styles_select' => array(
    ),
    'layer_activated' => array(
    ),
    'layer_switcher' => array(
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );

  $export['cmtls_map_defaults'] = $openlayers_maps;
  
  // Get the defaults.
  $default_map = openlayers_map_load('cmtls_map_defaults');
  if(!$default_map) {
    $default_map = $openlayers_maps;
  }
  
  // Get the CT marker vocabulary.
  $taxonomy = cmtls_get_taxonomy('cmtls_marker');
  
  $terms = $taxonomy['terms'];
  $voc = $taxonomy['vocabulary'];
  
  // Global map.
  $layers = array();
  $layer_weights = array();
  $layer_styles = array();
  
  foreach ($terms as $i => $term) {
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
    'center' => $default_map->data['center'],
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
    'default_layer' => $default_map->data['default_layer'],
    'layers' => $default_map->data['layers'] + $layers,
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
  $layer_switcher = array();
  $layer_weights = array();
  $layer_styles = array();
  
  foreach ($terms as $i => $term) {
    $layers['cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 'cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid;
    $layer_weights['cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid] = $i;
    $layer_styles['cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 'cmtls_dynamic_marker';
    $layer_switcher['cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term->tid] = 0;
  }

  // Show only layers that are in this application.
  $aid = (int)arg(1);
  if($aid && $application = node_load($aid)) {
    if($application->type == 'cmtls_app' && isset($application->field_cmtls_map_marker[LANGUAGE_NONE][0]['tid']) && (int)$application->field_cmtls_map_marker[LANGUAGE_NONE][0]['tid']) {
      $parent_tid = $application->field_cmtls_map_marker[LANGUAGE_NONE][0]['tid'];
      $term_layers[] = taxonomy_term_load($parent_tid);
      $term_layers = array_merge($term_layers, taxonomy_get_tree($voc->vid, $parent_tid));
      foreach($term_layers as $term_layer) {
        $layer_switcher['cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term_layer->tid] = 'cmtls_application_marker_layers_' . $voc->machine_name .'_' . $term_layer->tid;
      }
    }
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
    'center' => $default_map->data['center'],
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
    'default_layer' => $default_map->data['default_layer'],
    'layers' => $default_map->data['layers'] + $layers,
    'layer_weight' => $layer_weights,
    'layer_styles' => $layer_styles,
    'layer_styles_select' => $layer_styles,
    'layer_activated' => $layer_switcher,
    'layer_switcher' => $layer_switcher,
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
    'center' => $default_map->data['center'],
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
    'default_layer' => $default_map->data['default_layer'],
    'layers' => $default_map->data['layers'] + $layers,
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

  // The geometry widget map.
  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cmtls_geometry_widget';
  $openlayers_maps->title = 'CT map widget';
  $openlayers_maps->description = 'Map widget used for geometry input.';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => $default_map->data['center'],
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(
        'feature_types' => array(
          'point' => 'point',
          'path' => 'path',
          'polygon' => 'polygon',
        ),
        'allow_edit' => 1,
      ),
      'openlayers_behavior_geolocate' => array(
        'bind' => '1',
        'zoom_level' => '12',
        'watch' => '1',
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
    ),
    'default_layer' => $default_map->data['default_layer'],
    'layers' => $default_map->data['layers'],
    'layer_weight' => array(
    ),
    'layer_styles' => array(
    ),
    'layer_styles_select' => array(
    ),
    'layer_activated' => array(
    ),
    'layer_switcher' => array(
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );

  $export['cmtls_geometry_widget'] = $openlayers_maps;

  return $export;
}
