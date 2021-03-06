BricktronicsButton
==================

**BricktronicsButton v1.2 - A software library for LEGO NXT Pushbutton sensors.**

More details at http://www.wayneandlayne.com/bricktronics/

**To Download**
* Click the "Clone or download" button on the upper-right side of this page below the pink bar, then select "Download ZIP". Rename the uncompressed folder BricktronicsButton. Check that the BricktronicsButton folder contains BricktronicsButton.cpp and BricktronicsButton.h
* Place the BricktronicsButton library folder into your `<arduinosketchfolder>/libraries/` folder. You may need to create the libraries subfolder if this is your first installed library. Restart the Arduino IDE.

**API Highlights**
* `BricktronicsButton(uint8_t inputPin)` - Constructor
* `void begin(void)` - Call the begin function in your setup() function
* `bool isPressed(void)` - Returns true if the button is currently pressed
* `bool isReleased(void)` - Returns true if the button is currently released
* More API details in [API.md](API.md)

**If you want to use buttons with your Bricktronics Shield or Megashield, you may also be interested in these libraries:**
* [BricktronicsShield Arduino Library v1.2](https://github.com/wayneandlayne/BricktronicsShield)
* [BricktronicsMegashield Arduino Library v1.2](https://github.com/wayneandlayne/BricktronicsMegashield)

_Wayne and Layne, LLC and our products are not connected to or endorsed by the LEGO Group. LEGO, Mindstorms, and NXT are trademarks of the LEGO Group._

