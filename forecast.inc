## forecast module for weewx skins
## Copyright Tom Keffer, Matthew Wall
## See LICENSE.txt for your rights
#errorCatcher Echo

#if $varExists('forecast')

<link rel='stylesheet' type='text/css' href='forecast_compact.css'/>

<div id='forecast_widget' class="widget">
  <div class="widget_title">
    Forecast
    <a class="widget_control"
      onclick="toggle_widget('forecast')">&diams;</a>
  </div>
  <div class="widget_contents">

#include "forecast_compact.inc"

  </div>
</div>

#else

<!-- forecast information is not displayed:                     -->
<!-- the ForecastVariables search list extension is not enabled -->

#end if
