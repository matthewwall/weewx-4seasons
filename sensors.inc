## sensors module for weewx skins
## Copyright Tom Keffer, Matthew Wall
## See LICENSE.txt for your rights
#errorCatcher Echo

## this is a conditional display of sensor data, including connectivity,
## battery status, and various voltages.  if there are no data available,
## then this degenerates to nothing displayed.

#def get_battery_status($x)
#if $x == 0
<span class="status_ok">OK</span>
#else
<span class="status_low">LOW</span>
#end if
#end def

## first see what sensor data are available

#set $CONNECTION_DATA = [$day.rxCheckPercent, $day.signal1, $day.signal2, $day.signal3, $day.signal4, $day.signal5, $day.signal6, $day.signal7, $day.signal8]

#set $BATTERY_DATA = [$day.txBatteryStatus, $day.windBatteryStatus, $day.rainBatteryStatus, $day.outTempBatteryStatus, $day.inTempBatteryStatus, $day.batteryStatus1, $day.batteryStatus2, $day.batteryStatus3, $day.batteryStatus4, $day.batteryStatus5, $day.batteryStatus6, $day.batteryStatus7, $day.batteryStatus8]

#set $VOLTAGE_DATA = [$day.consBatteryVoltage, $day.heatingVoltage, $day.supplyVoltage, $day.referenceVoltage, $day.batteryVoltage1, $day.batteryVoltage2, $day.batteryVoltage3, $day.batteryVoltage4, $day.batteryVoltage5, $day.batteryVoltage6, $day.batteryVoltage7, $day.batteryVoltage8]

#set $have_conn = 0
#for $x in $CONNECTION_DATA
  #if $x.has_data
    #set $have_conn = 1
  #end if
#end for

#set $have_battery_status = 0
#for $x in $BATTERY_DATA
  #if $x.has_data
    #set $have_battery_status = 1
  #end if
#end for

#set $have_voltage = 0
#for $x in $VOLTAGE_DATA
  #if $x.has_data
    #set $have_voltage = 1
  #end if
#end for


## now display the available data only

#if $have_conn or $have_battery_status or $have_voltage
<div id='sensors_widget' class="widget">
  <div class="widget_title">
    <a href="telemetry.html">Sensor Status</a>
    <a class="widget_control"
      onclick="toggle_widget('sensors')">&diams;</a>
  </div>
  <div class="widget_contents">
  <table>

#if $have_conn
    <tr><th>Connectivity</th><th></th></tr>
#if $day.rxCheckPercent.has_data
    <tr>
      <td class="label">$obs.label.rxCheckPercent</td>
      <td class="data">$current.rxCheckPercent</td>
    </tr>
#end if
#if $day.signal1.has_data
    <tr>
      <td class="label">$obs.label.signal1</td>
      <td class="data">$current.signal1</td>
    </tr>
#end if
#if $day.signal2.has_data
    <tr>
      <td class="label">$obs.label.signal2</td>
      <td class="data">$current.signal2</td>
    </tr>
#end if
#if $day.signal3.has_data
    <tr>
      <td class="label">$obs.label.signal3</td>
      <td class="data">$current.signal3</td>
    </tr>
#end if
#if $day.signal4.has_data
    <tr>
      <td class="label">$obs.label.signal4</td>
      <td class="data">$current.signal4</td>
    </tr>
#end if
#if $day.signal5.has_data
    <tr>
      <td class="label">$obs.label.signal5</td>
      <td class="data">$current.signal5</td>
    </tr>
#end if
#if $day.signal6.has_data
    <tr>
      <td class="label">$obs.label.signal6</td>
      <td class="data">$current.signal6</td>
    </tr>
#end if
#if $day.signal7.has_data
    <tr>
      <td class="label">$obs.label.signal7</td>
      <td class="data">$current.signal7</td>
    </tr>
#end if
#if $day.signal8.has_data
    <tr>
      <td class="label">$obs.label.signal8</td>
      <td class="data">$current.signal8</td>
    </tr>
#end if
#end if

#if $have_battery_status
    <tr><th>Battery Status</th><th></th></tr>
#if $day.txBatteryStatus.has_data
    <tr>
      <td class="label">$obs.label.txBatteryStatus</td>
      <td class="data">$get_battery_status($current.txBatteryStatus.raw)</td>
    </tr>
#end if
#if $day.windBatteryStatus.has_data
    <tr>
      <td class="label">$obs.label.windBatteryStatus</td>
      <td class="data">$get_battery_status($current.windBatteryStatus.raw)</td>
    </tr>
#end if
#if $day.rainBatteryStatus.has_data
    <tr>
      <td class="label">$obs.label.rainBatteryStatus</td>
      <td class="data">$get_battery_status($current.rainBatteryStatus.raw)</td>
    </tr>
#end if
#if $day.outTempBatteryStatus.has_data
    <tr>
      <td class="label">$obs.label.outTempBatteryStatus</td>
      <td class="data">$get_battery_status($current.outTempBatteryStatus.raw)</td>
    </tr>
#end if
#if $day.inTempBatteryStatus.has_data
    <tr>
      <td class="label">$obs.label.inTempBatteryStatus</td>
      <td class="data">$get_battery_status($current.inTempBatteryStatus.raw)</td>
    </tr>
#end if
#if $day.batteryStatus1.has_data
    <tr>
      <td class="label">$obs.label.batteryStatus1</td>
      <td class="data">$get_battery_status($current.batteryStatus1.raw)</td>
    </tr>
#end if
#if $day.batteryStatus2.has_data
    <tr>
      <td class="label">$obs.label.batteryStatus2</td>
      <td class="data">$get_battery_status($current.batteryStatus2.raw)</td>
    </tr>
#end if
#if $day.batteryStatus3.has_data
    <tr>
      <td class="label">$obs.label.batteryStatus3</td>
      <td class="data">$get_battery_status($current.batteryStatus3.raw)</td>
    </tr>
#end if
#if $day.batteryStatus4.has_data
    <tr>
      <td class="label">$obs.label.batteryStatus4</td>
      <td class="data">$get_battery_status($current.batteryStatus4.raw)</td>
    </tr>
#end if
#if $day.batteryStatus5.has_data
    <tr>
      <td class="label">$obs.label.batteryStatus5</td>
      <td class="data">$get_battery_status($current.batteryStatus5.raw)</td>
    </tr>
#end if
#if $day.batteryStatus6.has_data
    <tr>
      <td class="label">$obs.label.batteryStatus6</td>
      <td class="data">$get_battery_status($current.batteryStatus6.raw)</td>
    </tr>
#end if
#if $day.batteryStatus7.has_data
    <tr>
      <td class="label">$obs.label.batteryStatus7</td>
      <td class="data">$get_battery_status($current.batteryStatus7.raw)</td>
    </tr>
#end if
#if $day.batteryStatus8.has_data
    <tr>
      <td class="label">$obs.label.batteryStatus8</td>
      <td class="data">$get_battery_status($current.batteryStatus8.raw)</td>
    </tr>
#end if
#end if

#if $have_voltage
    <tr><th>Voltage</th><th></th></tr>
#if $day.consBatteryVoltage.has_data
    <tr>
      <td class="label">$obs.label.consBatteryVoltage</td>
      <td class="data">$current.consBatteryVoltage</td>
    </tr>
#end if
#if $day.heatingVoltage.has_data
    <tr>
      <td class="label">$obs.label.heatingVoltage</td>
      <td class="data">$current.heatingVoltage</td>
    </tr>
#end if
#if $day.supplyVoltage.has_data
    <tr>
      <td class="label">$obs.label.supplyVoltage</td>
      <td class="data">$current.supplyVoltage</td>
    </tr>
#end if
#if $day.referenceVoltage.has_data
    <tr>
      <td class="label">$obs.label.referenceVoltage</td>
      <td class="data">$current.referenceVoltage</td>
    </tr>
#end if
#if $day.batteryVoltage1.has_data
    <tr>
      <td class="label">$obs.label.batteryVoltage1</td>
      <td class="data">$current.batteryVoltage1</td>
    </tr>
#end if
#if $day.batteryVoltage2.has_data
    <tr>
      <td class="label">$obs.label.batteryVoltage2</td>
      <td class="data">$current.batteryVoltage2</td>
    </tr>
#end if
#if $day.batteryVoltage3.has_data
    <tr>
      <td class="label">$obs.label.batteryVoltage3</td>
      <td class="data">$current.batteryVoltage3</td>
    </tr>
#end if
#if $day.batteryVoltage4.has_data
    <tr>
      <td class="label">$obs.label.batteryVoltage4</td>
      <td class="data">$current.batteryVoltage4</td>
    </tr>
#end if
#if $day.batteryVoltage5.has_data
    <tr>
      <td class="label">$obs.label.batteryVoltage5</td>
      <td class="data">$current.batteryVoltage5</td>
    </tr>
#end if
#if $day.batteryVoltage6.has_data
    <tr>
      <td class="label">$obs.label.batteryVoltage6</td>
      <td class="data">$current.batteryVoltage6</td>
    </tr>
#end if
#if $day.batteryVoltage7.has_data
    <tr>
      <td class="label">$obs.label.batteryVoltage7</td>
      <td class="data">$current.batteryVoltage7</td>
    </tr>
#end if
#if $day.batteryVoltage8.has_data
    <tr>
      <td class="label">$obs.label.batteryVoltage8</td>
      <td class="data">$current.batteryVoltage8</td>
    </tr>
#end if
#end if
  </table>
  </div>

</div>
#end if
