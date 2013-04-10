<?php
/**
 * @file
 * cmtls.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function cmtls_features_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cmtls_geometry_side_map';
  $openlayers_maps->title = 'CT geometry sidebar map';
  $openlayers_maps->description = 'A map used in the sidebar';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '200px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
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
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 'cmtls_common_elements_cmtls_common_geometry_ol_overlay',
          'mapquest_osm' => 0,
        ),
        'point_zoom_level' => '14',
        'zoomtolayer_scale' => '1',
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 'cmtls_common_elements_cmtls_common_geometry_ol_overlay',
    ),
    'layer_weight' => array(
      'cmtls_map_cmtls_map_location_ol_overlay' => '0',
      'cmtls_map_cmtls_map_event_ol_overlay' => '0',
      'cmtls_map_cmtls_map_media_ol_overlay' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => '0',
      'cmtls_map_cmtls_map_post_ol_overlay' => '0',
      'cmtls_map_cmtls_map_application_ol_overlay' => '0',
      'openlayers_geojson_picture_this' => '0',
      'cmtls_common_location_openlayers_1' => '0',
      'cmtls_locations_page_map_ol_overlay' => '0',
      'cmtls_map_cmtls_map_group_ol_overlay' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'cmtls_common_location_openlayers_1' => '0',
      'cmtls_locations_page_map_ol_overlay' => '0',
      'cmtls_map_cmtls_map_group_ol_overlay' => '0',
      'cmtls_map_cmtls_map_application_ol_overlay' => '0',
      'cmtls_map_cmtls_map_post_ol_overlay' => '0',
      'cmtls_map_cmtls_map_location_ol_overlay' => '0',
      'cmtls_map_cmtls_map_event_ol_overlay' => '0',
      'cmtls_map_cmtls_map_media_ol_overlay' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 'default_marker_black_small',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'cmtls_common_location_openlayers_1' => '0',
      'cmtls_locations_page_map_ol_overlay' => '0',
      'cmtls_map_cmtls_map_group_ol_overlay' => '0',
      'cmtls_map_cmtls_map_application_ol_overlay' => '0',
      'cmtls_map_cmtls_map_post_ol_overlay' => '0',
      'cmtls_map_cmtls_map_location_ol_overlay' => '0',
      'cmtls_map_cmtls_map_event_ol_overlay' => '0',
      'cmtls_map_cmtls_map_media_ol_overlay' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 'default_marker_black_small',
    ),
    'layer_activated' => array(
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 'cmtls_common_elements_cmtls_common_geometry_ol_overlay',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'cmtls_common_location_openlayers_1' => 0,
      'cmtls_locations_page_map_ol_overlay' => 0,
      'cmtls_map_cmtls_map_group_ol_overlay' => 0,
      'cmtls_map_cmtls_map_application_ol_overlay' => 0,
      'cmtls_map_cmtls_map_post_ol_overlay' => 0,
      'cmtls_map_cmtls_map_location_ol_overlay' => 0,
      'cmtls_map_cmtls_map_event_ol_overlay' => 0,
      'cmtls_map_cmtls_map_media_ol_overlay' => 0,
    ),
    'layer_switcher' => array(
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'cmtls_common_location_openlayers_1' => 0,
      'cmtls_locations_page_map_ol_overlay' => 0,
      'cmtls_map_cmtls_map_group_ol_overlay' => 0,
      'cmtls_map_cmtls_map_application_ol_overlay' => 0,
      'cmtls_map_cmtls_map_post_ol_overlay' => 0,
      'cmtls_map_cmtls_map_location_ol_overlay' => 0,
      'cmtls_map_cmtls_map_event_ol_overlay' => 0,
      'cmtls_map_cmtls_map_media_ol_overlay' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['cmtls_geometry_side_map'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cmtls_geometry_widget';
  $openlayers_maps->title = 'CT geometry widget';
  $openlayers_maps->description = 'A Map Used for Geofield Input';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-30.812120436925, 26.872452028284',
        'zoom' => '1',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
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
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'google_normal' => 'google_normal',
      'osm_mapnik' => 'osm_mapnik',
    ),
    'layer_weight' => array(
      'ct_map_ol_map_ol_overlay' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => '0',
      'ct_map_ol_map_ol_overlay' => '0',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => '0',
      'ct_map_ol_map_ol_overlay' => '0',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 0,
      'ct_map_ol_map_ol_overlay' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 0,
      'ct_map_ol_map_ol_overlay' => 0,
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

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cmtls_location_full_map';
  $openlayers_maps->title = 'CT locations full map';
  $openlayers_maps->description = 'Full map for locations';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '500px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
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
        'layers' => array(
          'cmtls_locations_page_map_ol_overlay' => 0,
        ),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'cmtls_locations_page_map_ol_overlay' => 'cmtls_locations_page_map_ol_overlay',
          'mapquest_osm' => 0,
          'google_normal' => 0,
          'osm_mapnik' => 0,
        ),
        'point_zoom_level' => '5',
        'zoomtolayer_scale' => '1',
      ),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'google_normal' => 'google_normal',
      'osm_mapnik' => 'osm_mapnik',
      'cmtls_locations_page_map_ol_overlay' => 'cmtls_locations_page_map_ol_overlay',
    ),
    'layer_weight' => array(
      'cmtls_map_cmtls_map_location_ol_overlay' => '0',
      'cmtls_map_cmtls_map_event_ol_overlay' => '0',
      'cmtls_map_cmtls_map_media_ol_overlay' => '0',
      'cmtls_locations_page_map_ol_overlay' => '0',
      'cmtls_map_cmtls_map_post_ol_overlay' => '0',
      'cmtls_map_cmtls_map_application_ol_overlay' => '0',
      'openlayers_geojson_picture_this' => '0',
      'cmtls_common_location_openlayers_1' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => '0',
      'cmtls_map_cmtls_map_group_ol_overlay' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'cmtls_common_location_openlayers_1' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => '0',
      'cmtls_map_cmtls_map_group_ol_overlay' => '0',
      'cmtls_map_cmtls_map_application_ol_overlay' => '0',
      'cmtls_map_cmtls_map_post_ol_overlay' => '0',
      'cmtls_map_cmtls_map_location_ol_overlay' => '0',
      'cmtls_map_cmtls_map_event_ol_overlay' => '0',
      'cmtls_map_cmtls_map_media_ol_overlay' => '0',
      'cmtls_locations_page_map_ol_overlay' => 'default_marker_black_small',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'cmtls_common_location_openlayers_1' => '0',
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => '0',
      'cmtls_map_cmtls_map_group_ol_overlay' => '0',
      'cmtls_map_cmtls_map_application_ol_overlay' => '0',
      'cmtls_map_cmtls_map_post_ol_overlay' => '0',
      'cmtls_map_cmtls_map_location_ol_overlay' => '0',
      'cmtls_map_cmtls_map_event_ol_overlay' => '0',
      'cmtls_map_cmtls_map_media_ol_overlay' => '0',
      'cmtls_locations_page_map_ol_overlay' => 'default_marker_black_small',
    ),
    'layer_activated' => array(
      'cmtls_locations_page_map_ol_overlay' => 'cmtls_locations_page_map_ol_overlay',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'cmtls_common_location_openlayers_1' => 0,
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 0,
      'cmtls_map_cmtls_map_group_ol_overlay' => 0,
      'cmtls_map_cmtls_map_application_ol_overlay' => 0,
      'cmtls_map_cmtls_map_post_ol_overlay' => 0,
      'cmtls_map_cmtls_map_location_ol_overlay' => 0,
      'cmtls_map_cmtls_map_event_ol_overlay' => 0,
      'cmtls_map_cmtls_map_media_ol_overlay' => 0,
    ),
    'layer_switcher' => array(
      'cmtls_locations_page_map_ol_overlay' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'cmtls_common_location_openlayers_1' => 0,
      'cmtls_common_elements_cmtls_common_geometry_ol_overlay' => 0,
      'cmtls_map_cmtls_map_group_ol_overlay' => 0,
      'cmtls_map_cmtls_map_application_ol_overlay' => 0,
      'cmtls_map_cmtls_map_post_ol_overlay' => 0,
      'cmtls_map_cmtls_map_location_ol_overlay' => 0,
      'cmtls_map_cmtls_map_event_ol_overlay' => 0,
      'cmtls_map_cmtls_map_media_ol_overlay' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['cmtls_location_full_map'] = $openlayers_maps;

  return $export;
}
