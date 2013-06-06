<?php
/**
 * @file
 * hbi_vimeo_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hbi_vimeo_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ebo_vimeo_video_final';
  $feeds_importer->config = array(
    'name' => 'ebo_vimeo_video_final',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'ebo_video',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'eBO Video',
            'target' => 'field_ebo_video',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Tags',
            'target' => 'field_video_tags',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'eBO Users',
            'target' => 'field_ebo_users',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'eBO Categories',
            'target' => 'field_ebo_categories',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'plain_text',
        'author' => '0',
        'authorize' => 1,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ebo_vimeo_video_final'] = $feeds_importer;

  return $export;
}
