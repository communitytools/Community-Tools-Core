<?php
/**
 * @file
 * cmtls_features.openlayers_styles.inc
 */

/**
 * Implements hook_openlayers_styles().
 */
function cmtls_features_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'cmtls_dynamic_marker';
  $openlayers_styles->title = 'CT dynamic marker';
  $openlayers_styles->description = 'Marker based on CT marker taxonomy';
  $openlayers_styles->data = array(
    'externalGraphic' => '${uri}',
    'pointRadius' => 6,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 0.4,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 21,
    'graphicHeight' => 25,
    'graphicOpacity' => 1,
    'graphicXOffset' => -10,
    'graphicYOffset' => -25,
    'labelAlign' => 'cm',
  );
  $export['cmtls_dynamic_marker'] = $openlayers_styles;

  return $export;
}
