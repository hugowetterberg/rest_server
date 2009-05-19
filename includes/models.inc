<?php
// $Id: models.inc,v 1.1.2.1 2009/05/19 20:15:07 hugowetterberg Exp $

/**
 * @file
 *  These are the base interfaces for resource models.
 */

/**
 * Interface that should be implemented by feed models.
 */
interface ResourceFeedModel extends Iterator {
}

/**
 * Interface that must be implemented by items returned
 * by a ResourceFeedModel.
 */
interface ResourceFeedModelItem {
  public function getName();
  public function getDescription();
  public function getUrl();
  public function getCreated();
  
  /**
   * Gets a associative array containing extra properties for the item.
   *
   * @return array
   *  The extra properties of the item as an array
   */
  public function getProperties();
}

/**
 * Interface that should be implemented by time feed models.
 */
interface ResourceTimeFeedModel extends ResourceFeedModel {
}

/**
 * Interface that must be implemented by items returned 
 * by a ResourceTimeFeedModel.
 */
interface ResourceTimeFeedModelItem extends ResourceFeedModelItem {
  /**
   * Gets the starting time of the item
   *
   * @return int
   *  The starting time of the item as a timestamp
   */
  public function getStarts();
  
  /**
   * Gets the end time of the item
   *
   * @return int
   *  The end time of the item as a timestamp
   */
  public function getEnds();
}