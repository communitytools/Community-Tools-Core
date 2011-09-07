<?php
/**
 * Adds cmtls core and other node types to node type filter as single options
 */
class views_handler_filter_cmtls_node_type extends views_handler_filter_node_type {
  
  protected $cmtls_content_node_types = array();
  protected $cmtls_content_node_types_titles = array();
  protected $cmtls_core_node_types = array('cmtls_group' => 'cmtls_group', 'cmtls_app' => 'cmtls_app', );
  
  function construct() {
    parent::construct();
    
    foreach (module_invoke_all('cmtls_app') as $node_type => $app) {
      $this->cmtls_content_node_types[$node_type] = $node_type;
      $this->cmtls_content_node_types_titles[$node_type] = $app['title'];
    }
  }
  function get_value_options() {
    parent::get_value_options();
    
    $this->value_options['cmtls_core_node_types'] = t('CT: Groups and Applications');

    if($this->cmtls_content_node_types) {
      $this->value_options['cmtls_content_node_types'] = t('CT: '.implode(', ', $this->cmtls_content_node_types_titles));
    }
  }
  
  function op_simple() {
    if (empty($this->value)) {
      return;
    }
    $this->ensure_my_table();
    
    if(in_array('cmtls_core_node_types', $this->value)) {
      unset($this->value['cmtls_core_node_types']);
      $this->value += $this->cmtls_core_node_types;
    }

    if(in_array('cmtls_content_node_types', $this->value)) {
      unset($this->value['cmtls_content_node_types']);
      $this->value += $this->cmtls_content_node_types;
    }

    // We use array_values() because the checkboxes keep keys and that can cause
    // array addition problems.
    $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", array_values($this->value), $this->operator);
  }
}
