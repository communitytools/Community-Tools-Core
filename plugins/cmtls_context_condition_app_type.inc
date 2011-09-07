<?php

class cmtls_context_condition_app_type extends context_condition_node {
  function condition_values() {
    $values = array();
    foreach (module_invoke_all('cmtls_app') as $app_type => $app) {
      $values[$app_type] = $app['title'];
    }
    return $values;
  }

  function execute($node, $op) {
    if(isset($node->cmtls_app_type)) {
      foreach ($this->get_contexts($node->cmtls_app_type) as $context) {
        // Check the node form option.
        $options = $this->fetch_from_context($context, 'options');
        if ($op === 'form') {
          $options = $this->fetch_from_context($context, 'options');
          if (!empty($options['node_form']) && in_array($options['node_form'], array(CONTEXT_NODE_FORM, CONTEXT_NODE_FORM_ONLY))) {
            $this->condition_met($context, $node->cmtls_app_type);
          }
        }
        elseif (empty($options['node_form']) || $options['node_form'] != CONTEXT_NODE_FORM_ONLY) {
          $this->condition_met($context, $node->cmtls_app_type);
        }
      }      
    } 
  }
}
