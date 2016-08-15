// Bricktronics Example: SimpleButtonBricktronicsBreakoutBoard
// http://www.wayneandlayne.com/bricktronics
//
// This example queries the NXT pushbutton sensor and transmits "pressed" and
// "released" over the serial port.
//
// Hardware used:
// * Wayne and Layne Bricktronics Breakout Board
//   https://store.wayneandlayne.com/products/bricktronics-breakout-board.html
// * LEGO NXT Pushbutton sensor
//
// Software libraries used:
// * Wayne and Layne BricktronicsButton library
//   https://github.com/wayneandlayne/BricktronicsButton
// * Adafruit MCP23017 library
//   https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
//
// Written in 2016 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.


// Include the Bricktronics libraries
#include <BricktronicsButton.h>


// Connect these pins on the Bricktronics Breakout board:
//  Pin 1 - Connect to Arduino input pin (any digital input pin)
//  Pin 2 - Connect to Ground
//  Pin 3 - Connect to Ground
//  Pin 4 - Connect to 5V
//  Pin 5 - No connection
//  Pin 6 - No connection
//
// The BricktronicsButton() argument is simply the Arduino pin where pin 1
// on the breakout board is connected.
//
BricktronicsButton b(7);


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

