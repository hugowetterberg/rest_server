<?php
// $Id$

function _node_resource_retrieve($nid) {
  $node = node_load($nid);
  return $node;
}

function _node_resource_recent($page) {
  $res = db_query_range("SELECT nid, title, created
    FROM {node}
    ORDER BY created DESC", $page*20, 20);

  $nodes = array();
  while ($node = db_fetch_array($res)) {
    $nodes['node/' . $node['nid']] = $node;
  }
  return $nodes;
}