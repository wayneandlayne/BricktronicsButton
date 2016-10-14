// Bricktronics Example: SimpleButtonBricktronicsMegashield
// http://www.wayneandlayne.com/bricktronics
//
// This example queries the NXT pushbutton sensor and transmits "pressed" and
// "released" over the serial port.
//
// Hardware used:
// * Wayne and Layne Bricktronics Megashield
//   https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html
// * LEGO NXT Pushbutton sensor
//
// Software libraries used:
// * Wayne and Layne BricktronicsButton library
//   https://github.com/wayneandlayne/BricktronicsButton
// * Wayne and Layne BricktronicsMegashield library
//   https://github.com/wayneandlayne/BricktronicsMegashield
//
// Written in 2016 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.


// Include the Bricktronics libraries
#include <BricktronicsMegashield.h>
#include <BricktronicsButton.h>


// Select the desired sensor port (SENSOR_1 through SENSOR_4) in the constructor below.
// Connect pins 2-3 and 4-5 on the chosen sensor port.
BricktronicsButton b(BricktronicsMegashield::SENSOR_1);


void setup()
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

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

