<?php


function cmtls_location_views_query_alter(&$view, &$query) {
  if($view->name == 'cmtls_locations') {
    $config = cmtls_get_app_config();
    
    if($config['cmtls_location']['sorting_field'] && !isset($_location['sort_by'])) {
      $query->orderby[1]['field'] = $_location['sort_by'] = $_GET['sort_by'] = $config['cmtls_location']['sorting_field'];
    }

    if($config['cmtls_location']['sorting_dir'] && !isset($_location['sort_order'])) {
      $query->orderby[1]['direction'] = $_location['sort_order'] = $_GET['sort_order'] = $config['cmtls_location']['sorting_dir'];
    }
  }
}
