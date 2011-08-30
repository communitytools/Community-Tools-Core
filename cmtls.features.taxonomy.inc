<?php
/**
 * @file
 * cmtls.features.taxonomy.inc
 */

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function cmtls_taxonomy_default_vocabularies() {
  return array(
    'cmtls_tags' => array(
      'name' => 'CT Tags',
      'machine_name' => 'cmtls_tags',
      'description' => 'Tags used in Community Tools',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
