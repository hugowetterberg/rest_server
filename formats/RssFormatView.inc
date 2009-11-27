<?php
// $Id: RssFormatView.inc,v 1.1.2.2 2009/11/27 20:37:22 hugowetterberg Exp $

class RssFormatView extends RESTServerView {
  function render() {
    $items = '';
    foreach ($this->model as $item) {
      $items .= format_rss_item($item->getName(), $item->getUrl(), $item->getDescription(), array(
        'pubDate' => date('r', $item->getCreated()),
      ));
    }

    $out = '<?xml version="1.0" encoding="utf-8"?>' . "\n";
    $out .= '<rss version="2.0" xml:base="' . url('', array('absolute'=>TRUE)) . '"  xmlns:dc="http://purl.org/dc/elements/1.1/">' . "\n";
    $out .= format_rss_channel(variable_get('site_name',''), url($_GET['q'], array('absolute'=>TRUE)), variable_get('site_name',''), $items);

    return $out;
  }
}