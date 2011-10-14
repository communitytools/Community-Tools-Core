<?php
/**
 * @file
 * cmtls core Field API impelementations
 * 
 * - Application type field for application nodes 
 * 
 */

/**
 * Implements hook_field_info().
 *
 * Provides the description of the field.
 */
function cmtls_field_info() {
  return array(
    // app type field
    'cmtls_app_type' => array(
      'label' => t('Application type'),
      'description' => t('Community Tools application type'),
      'default_widget' => 'cmtls_app_type_select',
      'default_formatter' => 'cmtls_app_type',
    ),
  );
}

/**
 * Implements hook_field_validate().
 *
 * @see cmtls_field_widget_error()
 * TODO: proper validation
 */
function cmtls_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  foreach ($items as $delta => $item) {
    if (!empty($item['cmtls_app_type'])) {
      if (0) {
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'cmtls_invalid',
          'message' => t('Color must be in the HTML format #abcdef.'),
        );
      }
    }
  }
}


/**
 * Implements hook_field_is_empty().
 *
 */
function cmtls_field_is_empty($item, $field) {
  return empty($item['cmtls_app_type']);
}

/**
 * Implements hook_field_formatter_info().
 *
 * @see cmtls_field_formatter_view()
 */
function cmtls_field_formatter_info() {
  return array(
    // app type formatter
    'cmtls_app_type' => array(
      'label' => t('Default'),
      'field types' => array('cmtls_app_type'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 *
 * @see cmtls_field_formatter_info()
 */
function cmtls_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    // This formatter simply outputs the app type and description
    case 'cmtls_app_type':
      $apps = module_invoke_all('cmtls_app');
      foreach ($items as $delta => $item) {
        // get possible app types from hook_cmtls_app
        foreach ($apps as $app_type => &$apps) {
          if($app_type == $item['cmtls_app_type']) {
            $element[$delta] = array(
              '#type' => 'html_tag',
              '#tag' => 'span',
              '#value' => $apps['title'] . ' (' . $apps['description'] . ')',
            );
            break;
          }
        }
      }
      break;
  }

  return $element;
}

/**
 * Implements hook_field_widget_info().
 *
 * @see cmtls_field_widget_form()
 */
function cmtls_field_widget_info() {
  return array(
    // app type selector widget
    'cmtls_app_type_select' => array(
       'label' => t('Application'),
       'field types' => array('cmtls_app_type'),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 *
 */
function cmtls_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $value = isset($items[$delta]['cmtls_app_type']) ? $items[$delta]['cmtls_app_type'] : NULL;

  $widget = $element;
  $widget['#delta'] = $delta;

  switch ($instance['widget']['type']) {
    // app type select widget
    case 'cmtls_app_type_select':
      // get possible app types from hook_cmtls_app
      $app_types = array();
      foreach (module_invoke_all('cmtls_app') as $app_type => $app) {
        $app_types[$app_type] = $app['title'];
      }
      
      $widget += array(
        '#type' => 'radios',
        '#default_value' => $value,
        '#options' => $app_types, 
      );
    break;
  }

  $element['cmtls_app_type'] = $widget;
  return $element;
}

/**
 * Implements hook_field_widget_error().
 *
 * @see cmtls_field_validate()
 * @see form_error()
 */
function cmtls_field_widget_error($element, $error, $form, &$form_state) {
  switch ($error['error']) {
    case 'cmtls_invalid':
      form_error($element, $error['message']);
      break;
  }
}

/**
 * Implements hook_field_schema().
 * 
 */
function cmtls_field_schema($field) {
  $columns = array();
  
  // app type
  if ($field['type'] == 'cmtls_app_type') {
      $columns = array(
        'cmtls_app_type' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      );
  }

  return array('columns' => $columns);
}

/**
 * Common CT fields
 */

/**
 * info array for cmtls field
 */
function cmtls_get_field_info($field) {
  // parent app reference
  $fields['field_cmtls_application'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_cmtls_application',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'cmtls_app' => 'cmtls_app',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => '0',
    'type' => 'node_reference',
  );
  
  // location
  $fields['field_cmtls_location'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_cmtls_location',
    'foreign keys' => array(),
    'indexes' => array(
      'lid' => array(
        0 => 'lid',
      ),
    ),
    'module' => 'location_cck',
    'settings' => array(
      'gmap_macro' => '[gmap ]',
      'gmap_marker' => 'small orange',
      'location_settings' => array(
        'display' => array(
          'hide' => array(
            'additional' => 'additional',
            'city' => 0,
            'coords' => 'coords',
            'country' => 0,
            'country_name' => 'country_name',
            'fax' => 0,
            'locpick' => 'locpick',
            'map_link' => 0,
            'name' => 0,
            'phone' => 0,
            'postal_code' => 0,
            'province' => 0,
            'province_name' => 'province_name',
            'street' => 0,
          ),
        ),
        'form' => array(
          'fields' => array(
            'additional' => array(
              'collect' => '0',
              'default' => '',
              'weight' => '-97',
            ),
            'city' => array(
              'collect' => '1',
              'default' => '',
              'weight' => '-96',
            ),
            'country' => array(
              'collect' => '1',
              'default' => 'ee',
              'weight' => '-93',
            ),
            'fax' => array(
              'collect' => '0',
              'default' => '',
              'weight' => '30',
            ),
            'locpick' => array(
              'collect' => '1',
              'weight' => '-100',
            ),
            'name' => array(
              'collect' => '1',
              'default' => '',
              'weight' => '-99',
            ),
            'phone' => array(
              'collect' => '0',
              'default' => '',
              'weight' => '25',
            ),
            'postal_code' => array(
              'collect' => '1',
              'default' => '',
              'weight' => '-94',
            ),
            'province' => array(
              'collect' => '1',
              'default' => '',
              'weight' => '-95',
            ),
            'street' => array(
              'collect' => '1',
              'default' => '',
              'weight' => '-98',
            ),
          ),
        ),
      ),
    ),
    'translatable' => '0',
    'type' => 'location',
  );
  
  // ct tags
  $fields['field_cmtls_tags'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_cmtls_tags',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'parent' => '0',
          'vocabulary' => 'cmtls_tags',
        ),
      ),
    ),
    'translatable' => '0',
    'type' => 'taxonomy_term_reference',
  );
  
  return $fields[$field]; 
}

/**
 * info array for cmtls field
 */
function cmtls_get_field_instance($field) {
  dpm($field);
  $fields['field_cmtls_application'] = array(
    'default_value' => NULL,
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => '5',
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => '5',
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cmtls_application',
    'label' => 'Application',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => '7',
    ),
  );
      
  // location
  $fields['field_cmtls_location'] = array(
    'default_value' => NULL,
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => '3',
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => '4',
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cmtls_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'location_cck',
      'settings' => array(),
      'type' => 'location',
      'weight' => '4',
    ),
  );

  // ct tags
  $fields['field_cmtls_tags'] = array(
    'default_value' => NULL,
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => '4',
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => '2',
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cmtls_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => '1',
    ),
  );
  
  return $fields[$field];
}

/**
 * Create a cmtls field in a bundle.
 *
 * @param $bundle
 *   The bundle name.
 */
function cmtls_create_field($field_name, $bundle) {
  $field = field_info_field($field_name);
  if (empty($field)) {
    $field = cmtls_get_field_info($field_name);
    $field = field_create_field($$field);
  }

  $instance = field_info_instance('node', $field_name, $bundle);
  if (empty($instance)) {
    $instance = cmtls_get_field_instance($field_name);
    $instance += array(
      'bundle' => $bundle,
    );

    field_create_instance($instance);
  }
}
 
 