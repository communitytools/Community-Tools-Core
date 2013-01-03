<?php
/**
 * @file
 * Core Field API impelementations
 * Custom field for CT app type
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
    'cmtls_addressfield' => array(
      'label' => t('CT address formatter'),
      'field types' => array('addressfield'),
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
    // Format the addresfield ignoring the country.
    case 'cmtls_addressfield':
      $handlers = $instance['widget']['settings']['format_handlers'];
      foreach ($items as $delta => $address) {
        // Skip the address if only country is given.
        if(!($address['administrative_area']
          || $address['administrative_area']
          || $address['sub_administrative_area']
          || $address['postal_code']
          || $address['locality']
          || $address['dependent_locality']
          || $address['thoroughfare']
          || $address['sub_premise']
          || $address['organisation_name']
          || $address['name_line']
          || $address['first_name']
          || $address['last_name']
          || $address['data']
          || $address['premise'])) continue;
        // Remove the country from display.
        $address['country'] = NULL;
        // Generate the address format.
        $context = array(
          'mode' => 'render',
          'field' => $field,
          'instance' => $instance,
          'langcode' => $langcode,
          'delta' => $delta,
        );
        $element[$delta] = addressfield_generate($address, $handlers, $context);
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
 * returns array with app content types
 */
function cmtls_get_app_content_types($module = NULL) {
  $types = array();

  $apps = module_invoke_all('cmtls_app');

  foreach ($apps as $m => $config) {
    if(isset($config['node types'])) $types += $config['node types'];
    if($module == $m) {
      if(isset($config['node types'])) return $config['node types'];
      else return array();
    }
  }

  return $types;
}

