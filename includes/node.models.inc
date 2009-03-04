<?php
// $Id$

class NodeResourceFeedModel implements ResourceTimeFeedModel {
  protected $nodes = NULL;
  
  public function __construct($data) {
    $this->nodes = $data;
  }
  
  public function current() {
    $node = current($this->nodes);
    if ($node!==FALSE) {
      return new NodeResourceFeedModelItem($node);
    }
    return FALSE;
  }
  
  public function key() {
    return key($this->nodes);
  }
  
  public function next() {
    next($this->nodes);
  }
  
  public function rewind() {
    reset($this->nodes);
  }
  
  public function valid() {
    // It's safe to use current as there never should be a boolean
    // in the node array.
    return current($this->nodes)!==FALSE;
  }
}

class NodeResourceFeedModelItem implements ResourceTimeFeedModelItem {
  protected $node = NULL;
  
  public function __construct($data) {
    $this->node = $data;
  }
  
  /**
   * Returns the raw node title
   *
   * @return string
   *  The title of the node
   */
  public function getName() {
    return $this->node->title;
  }
  
  /**
   * Calls node_build_content to create a teaser
   */
  public function getDescription() {
    if (!isset($this->node->content)) {
      $this->node = node_build_content($this->node, TRUE, FALSE);
    }
    return $this->node->teaser;
  }
  
  /**
   * Returns the absolute url to the node
   *
   * @return string
   *  The node url
   */
  public function getUrl() {
    return url('node/' . $this->node->nid, array('absolute' => TRUE));
  }
  
  /**
   * Gets the created time for the node
   *
   * @return int
   *  The created time of the node as a timestamp
   */
  public function getTime() {
    return $this->node->created;
  }
}