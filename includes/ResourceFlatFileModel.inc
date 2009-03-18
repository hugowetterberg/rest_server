<?php
// $Id$

class ResourceFlatFileModel implements Iterator {
  protected $data = NULL;
  protected $columns = NULL;

  /**
   * Constructor for ResourceFlatFileModel
   *
   * @param mixed $data
   *  The data as an array, otherwise the data will be treated
   *  as a single row source with the $data param as the first
   *  and last row.
   * @param mixed $columns
   *  An array with column names, or a string with comma separated column names
   * @author Hugo Wetterberg
   */
  public function __construct($data, $columns=NULL) {
    if (!is_array($data)) {
      $this->data = array($data);
    }
    else {
      $this->data = $data;
    }

    // Compile a list of columns if none was provided
    if (!$columns) {
      $item = $this->acceptable_item(current($this->data));
      if (!empty($item)) {
        $this->columns = array();
        foreach ($item as $key => $value) {
          $this->columns[$key] = TRUE;
        }
      }
      reset($this->data);
    }
    // Use the provided string or array
    else {
      if (is_string($columns)) {
        $columns = preg_split('/,/', $columns);
      }
      if (is_array($columns)) {
        $this->columns = array();
        foreach ($columns as $col) {
          $this->columns[$col] = TRUE;
        }
      }
    }
  }

  /**
   * Turns the item into an array
   *
   * @param mixed $item 
   * @return array
   */
  private function acceptable_item($item) {
    if (is_array($item)) {
      return $item;
    }
    else if (is_object($item)) {
      return (array)$item;
    }
    else {
      return array($item);
    }
  }

  /**
   * Standardizes the item, making it follow the existing
   * columns.
   *
   * @param mixed $item 
   *  The source item
   * @return array
   *  An array with the values
   */
  private function standardize_item($item) {
    $item = $this->acceptable_item($item);
    $standardized = array();
    if ($this->columns) {
      foreach ($this->columns as $key => $use) {
        $standardized[$key] = isset($item[$key]) ? $item[$key] : '';
      }
    }
    return $standardized;
  }

  public function current() {
    $item = current($this->data);
    if ($item) {
      return $this->standardize_item($item);
    }

    return FALSE;
  }

  public function key() {
    return key($this->data);
  }

  public function next() {
    next($this->data);
  }

  public function rewind() {
    reset($this->data);
  }

  public function valid() {
    // It's safe to use current as there never should be a boolean
    // in the node array.
    return $this->$columns && current($this->data)!==FALSE;
  }
}