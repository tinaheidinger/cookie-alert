# cookie-alert

We developed an Arduino project that detects changes on the light sensor and raises an alarm - both acoustic and via Twitter, as long as the alarm has not been disarmed within two seconds.

## Example Usage

The Arduino can be inserted into a cookie jar. The light sensor detects whenever the jar is being opened. Unless the user disarms the alarm, the buzzer goes off and the user receives a Twitter notification.

## Implementation Details

The light sensor would detect whenever the jar is being opened. The user can disarm the alarm by pushing the respective button within two seonds, otherwise the buzzer would play an one second 440 Hz tone. Plus, the XBee connected to the arduino sends a signal to another XBee connected to an Arduino Yun. The Yun has a Twitter account configured and tweets a message mentioning the configured user.

## Hardware

- Arduino Duemilanove
- Arduino Yun
- XBee Coordinator
- XBee Router

### Sensors & Material

- Light sensor
- Buzzer
- Button
- Resistor
- Wires

## Software

- Arduino 1.6.5
- Temboo Twitter Choreography
- Twitter Apps
