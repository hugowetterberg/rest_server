<?php
// $Id: RssFormatView.inc,v 1.1.2.1 2009/05/19 20:15:07 hugowetterberg Exp $

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
    $out .= format_rss_channel(variable_get('site_name',''), url($_GET['q'], array('absolute'=>TRUE)), 'RssFormatView', $items);

    return $out;
  }
}