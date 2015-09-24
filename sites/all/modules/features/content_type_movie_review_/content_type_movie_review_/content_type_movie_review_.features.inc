<?php
/**
 * @file
 * content_type_movie_review_.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_movie_review__ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_movie_review__node_info() {
  $items = array(
    'movie_review' => array(
      'name' => t('Movie Review'),
      'base' => 'node_content',
      'description' => t('A content item to store movie reviews '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
