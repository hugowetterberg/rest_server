<?php
// $Id$

function _node_resource_retrieve($nid) {
  $node = node_load($nid);
  return $node;
}