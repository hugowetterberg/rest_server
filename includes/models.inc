<?php
// $Id$

/**
 * @file
 *  These are the base interfaces for resource models.
 */

/**
 * Interface that should be implemented by feed models.
 */
interface ResourceFeedModel implements Iterator {
  /**
   * Returns the current feed model item.
   *
   * @return ResourceFeedModelItem
   */
  public function current();
}

/**
 * Interface that must be implemented by items returned
 * by a ResourceFeedModel.
 */
interface ResourceFeedModelItem {
  public function getName();
  public function getDescription();
  public function getUrl();
  
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
interface ResourceTimeFeedModel implements ResourceFeedModel {
  /**
   * Returns the current time feed model item.
   *
   * @return ResourceTimeFeedModelItem
   */
  public function current();
}

/**
 * Interface that must be implemented by items returned 
 * by a ResourceTimeFeedModel.
 */
interface ResourceTimeFeedModelItem implements ResourceFeedModelItem {
  /**
   * Gets the time of the item
   *
   * @return int
   *  The time of the item as a timestamp
   */
  public function getTime();
}