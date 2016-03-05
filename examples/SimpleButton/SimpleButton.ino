// Bricktronics Example: SimpleButton
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Pushbutton sensor.
//
// This example transmits a "pressed" and "released" over the serial port
// in response to button presses and releases.
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the Bricktronics Button libraries
#include <BricktronicsButton.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.
// This sketch includes configuration blocks that are used by the W&L code
// build and test system, feel free to ignore the "// Config" lines in the code below.

// 1. With a Bricktronics Shield - Include these three lines and be sure to
// call BricktronicsShield::begin() in the setup() function below.
// You also need to install the Adafruit MCP23017 library:
//	https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
// Select the sensor port (SENSOR_1 through SENSOR_4) in the constructors below.
// If your chosen sensor port has jumpers (ports 3 and 4), connect pins 2-3 and 4-5.
//
// Config 1 - CFG_WNL_BS
//#include <Wire.h>
//#include <Adafruit_MCP23017.h>
//#include <BricktronicsShield.h>
//BricktronicsButton b(BricktronicsShield::SENSOR_1);
// Config end

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the desired sensor port (SENSOR_1 through SENSOR_4) in the constructors below.
// Connect pins 2-3 and 4-5 on the chosen sensor port.
//
// Config 2 - CFG_WNL_BMS
//#include <BricktronicsMegashield.h>
//BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
// Config end

// 3. With a Bricktronics Breakout board - No additional includes needed,
// just update the pin number in the Button constructor below.
//
// Connect these pins on the Bricktronics Breakout board:
//  Pin 1 - Connect to Arduino input pin (any digital input pin)
//  Pin 2 - Connect to Ground
//  Pin 3 - Connect to Ground
//  Pin 4 - Connect to 5V
//  Pin 5 - No connection
//  Pin 6 - No connection
//
// The BricktronicsButton() argument is simply the Arduino pin where the
// button's pin 1 is connected. No worries about PWM or interrupt pins.
//
// Config 3 - CFG_WNL_NS
//BricktronicsButton b(7);
// Config end


void setup()
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

  // Only call this if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  // Config 1 - CFG_WNL_BS
  //BricktronicsShield::begin();
  // Config end

  // Initialize the button connection
  b.begin();
}

void loop()
{
  // Wait until the button is pressed
  while (b.isReleased())
  {
    // Nothing to do here
  }
  // To get here, the button was pushed!

  // In order to debounce the button, we transmit a message on the serial
  // port and then wait a little bit longer here.
  Serial.println("pressed");
  delay(100);
  
  // Wait until the button is released
  while (b.isPressed())
  {
    // Nothing to do here
  }

  // In order to debounce the button, we transmit a message on the serial
  // port and then wait a little bit longer here.
  Serial.println("released");
  delay(100);
}

