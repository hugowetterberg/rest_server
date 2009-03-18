<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xcal="http://www.ietf.org/rfc/rfc2445">
<xsl:strip-space elements="*"/>
<xsl:preserve-space elements="text"/>
<xsl:output method="text" media-type="text/calendar" encoding="utf-8"/>
<xsl:template match="/iCalendar">
BEGIN:VCALENDAR
<xsl:apply-templates/>
END:VCALENDAR
</xsl:template>
<xsl:template match="xcal:vcalendar">
  <xsl:apply-templates select=""/>
</xsl:template>
</xsl:stylesheet>
