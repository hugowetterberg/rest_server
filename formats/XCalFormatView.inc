<?php
// $Id$

class XCalFormatView extends RESTServerView {
  function render() {
    global $language;
    $doc = new DomDocument('1.0', 'utf-8');

    $icalendar = $doc->appendChild($doc->createElement('iCalendar'));
    $icalendar->setAttribute('xmlns', 'http://www.ietf.org/rfc/rfc2445');

    $vc = $icalendar->appendChild($doc->createElement('vcalendar'));
    $this->value($doc, $vc, 'version', '2.0');
    $this->value($doc, $vc, 'prodid', '-//Drupal//' . $language->language);

    $tf = 'Ymd\This';

    foreach ($this->model as $item) {
      $vevent = $vc->appendChild($doc->createElement('vevent'));
      $this->value($doc, $vevent, 'summary', $item->getName());
      $this->value($doc, $vevent, 'description', $item->getDescription());
      $this->value($doc, $vevent, 'dtstart', date($tf, $item->getStarts()));
      $this->value($doc, $vevent, 'dtend', date($tf, $item->getEnds()));
      $this->value($doc, $vevent, 'url', $item->getUrl());
    }

    if (isset($this->arguments['transform']) && $this->arguments['transform']=='ical') {
      $xsl = new DOMDocument;
      $xsl->load(drupal_get_path('module', 'xcal_format') . '/ical.xslt');
      
      $proc = new XSLTProcessor();
      $proc->importStyleSheet($xsl);
      return $proc->transformToXML($doc);
    }
    else {
      $doc->formatOutput = TRUE;
      return $doc->saveXml();
    }
  }
  
  private function value($doc, $p, $name, $value) {
    $elem = $p->appendChild($doc->createElement($name));
    $elem->appendChild($doc->createTextNode($value));
  }
}