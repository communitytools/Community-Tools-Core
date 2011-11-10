<?php
/**
 * @file
 * Core Field API impelementations
 * Custom field for CT app type
 * definitions and API function for adding common CT fields
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
 * Common CT field info
 */
function cmtls_get_field_info($field) {
  // parent app reference
  $fields['field_cmtls_application'] = array(
    'field_config' => array(
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
    ),
    'field_instance' => array(
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
    ),
  );
  
  // location
  $fields['field_cmtls_location'] = array(
    'field_config' => array(
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
    ),
    'field_instance' => array(
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
    ),
  );
  
  // ct tags
  $fields['field_cmtls_tags'] = array(
    'field_config' => array(
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
    ),
    'field_instance' => array(
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
    ),
  );
  
  $fields['field_cmtls_main_group'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmtls_main_group',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => 'Indicates whether this is the main group of the Community Tools or not.
  
  NB! there should be only one main group',
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
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmtls_main_group',
      'label' => 'Main group',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '5',
      ),
    ),
  );

  $fields['field_cmtls_app_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmtls_app_type',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'cmtls',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'cmtls_app_type',
    ),
    'field_instance' => array(
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmtls_app_type',
      'label' => 'Application',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'cmtls',
        'settings' => array(),
        'type' => 'cmtls_app_type_select',
        'weight' => '4',
      ),
    ),
  );

  $fields['field_cmtls_app_configs'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmtls_app_configs',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
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
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmtls_app_configs',
      'label' => 'Application configurations',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '31',
      ),
    ),
  );
  
  $fields['field_cmtls_attachments'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cmtls_attachments',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
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
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cmtls_attachments',
      'label' => 'Attachments',
      'required' => 0,
      'settings' => array(
        'description_field' => 1,
        'file_directory' => 'cmtls-attachments',
        'file_extensions' => 'txt jpg png gif pdf doc xls',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '3',
      ),
    ),
  );
  
  $fields['field_first_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_first_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_first_name',
      'label' => 'First name',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'user-user-field_last_name'
  $fields['field_last_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_last_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_last_name',
      'label' => 'Last name',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );
  
  
  return isset($fields[$field]) ? $fields[$field] : array(); 
}

/**
 * Create a cmtls field in a bundle.
 *
 * @param $field_config array with field info and instance data
 */
function cmtls_create_field($field_config) {
  $field_name = $field_config['field_config']['field_name'];
  
  $field_defaults = cmtls_get_field_info($field_name);
  $field_config = drupal_array_merge_deep($field_defaults, $field_config);
  
  $field = field_info_field($field_name);
  if (empty($field)) {
    $field = field_create_field($field_config['field_config']);
  }

  $instance = field_info_instance($field_config['field_instance']['entity_type'], $field_name, $field_config['field_instance']['bundle']);
  if (empty($instance)) {
    field_create_instance($field_config['field_instance']);
  }
}
