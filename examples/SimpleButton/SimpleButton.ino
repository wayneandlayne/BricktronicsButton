// Bricktronics Example: SimpleButton
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Pushbutton sensor.
//
// This example transmits a "pressed" and "released" over the serial port
// in response to button presses and releases.


// Include the Bricktronics Button librarie
#include <BricktronicsButton.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.

// 1. With a Bricktronics Shield - Include these lines and be sure to
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor port (SENSOR_1 through SENSOR_4) in the constructors below.
// If your chosen sensor port has jumpers (ports 3 and 4), connect pins 2-3 and 4-5.
//
//#include <Wire.h>
//#include <Adafruit_MCP23017.h>
//#include <BricktronicsShield.h>
//BricktronicsButton b(BricktronicsShield::SENSOR_1);

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the desired sensor port (SENSOR_1 through SENSOR_4) in the constructors below.
// Connect pins 2-3 and 4-5 on the chosen sensor port.
//
// #include <BricktronicsMegashield.h>
//BricktronicsButton b(BricktronicsMegashield::SENSOR_1);

// 3. With a Bricktronics Breakout board - No additional includes needed,
// just update the pin number in the Button constructor below.
//
// The BricktronicsButton() argument is simply the pin the button is connected to,
// that is, wherever pin 1 of the Breakout board is connected (also connect the ground pins).
// No worries about PWM or interrupt pins for the button pin.
//
//BricktronicsButton b(7);


void setup()
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

  // Only call this if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  //BricktronicsShield::begin();

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
  Serial.println("pressed");
  delay(100);
}
