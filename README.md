# BuzzerAlarmArduino
Use Tinkercad or any other tool to implement the following project
<br/>You have two Arduinos which are connected using serial cable
<br/> Arduino#1 is connected to the following components
<br/>1-LCD, , 2-DC motor, 3-Temperature Sensor
<br/>Arduino#2 is connected to an Alarm (Buzzer) + LED
<br/>You may use other components such as resistors, function generator, power supply, relay, etc.
<br/>The system should do the following:
<br/>1-	Read the temperature every 1.5 seconds (DO NOT USE DELAY).
<br/>2-	Starting at t=6 seconds, calculate the average temperature (Tavg) during the last 6 seconds. Repeat this process every 1.5 seconds (moving average). 
<br/>3-	Write the Tavg on the LCD.
<br/>4-	If the Tavg is larger than 29 ̊C, drive a DC motor (fan) with 20% duty cycle. And then increase the speed of the fan with 10% for every 2 ̊C increase above 29.  If the temperature goes below 27 C, turn the DC motor off.
<br/>5-	If the Temperature become more than 35 ̊C, then the alarm will work on Arduino#2 and the LED will be ON.

<br/> 
Tinkercad link :https://www.tinkercad.com/things/bIjCygdkzC4


