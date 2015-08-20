# BricktronicsButton API

This library interfaces with LEGO NXT and EV3 pushbutton sensors. It can be used with the Bricktronics Shield, Bricktronics Megashield, or standalone with the Bricktronics Breakout Board. For the shield/megashield, use the constructor below with the BricktronicsSensorSettings struct, otherwise use the constructor below that accepts the input pin number.

## Connection with Bricktronics Shield and Megashield

Use the pushbutton sensor with any sensor port on the Bricktronics Shield or Megashield. If the chosen sensor port has jumpers, connect pins 2-3 and 4-5.

Constructor usage for Bricktronics Shield:
```C++
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
BricktronicsButton b(BricktronicsShield::SENSOR_1);
```

Constructor usage for Bricktronics Megashield:
```C++
#include <BricktronicsMegashield.h>
BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
```

## Connection with Bricktronics Breakout Board

* Pin 1 - Connect to any digital input pin (this is the constructor argument below)
* Pin 2 - Connect to Ground
* Pin 3 - Connect to Ground
* Pin 4 - Connect to 5V
* Pin 5 - No connection
* Pin 6 - No connection

Constructor usage for Bricktronics Breakout Board:
```C++
BricktronicsButton b(7); // Arduino pin 7 is connected to breakout board pin 1.
```

## Quick Example

```C++
#include <BricktronicsButton.h>

// Use one of the constructor options listed above.
BricktronicsButton b(7);

void setup()
{
    Serial.begin(115200);
    b.begin();
}

void loop()
{
    while(b.isReleased());
    Serial.println("pressed");
    delay(100);
            
    while(b.isPressed());
    Serial.println("released");
    delay(100);
}
```

## BricktronicsButton(uint8_t inputPin)

Constructor - Simple constructor that accepts an input pin

### Parameters

* **uint8_t inputPin** - The Arduino pin number where the button's pin 1 is connected.

### Return value

* Nothing

## Enums

* `FOO_BAR` - Use this for that
* `BAR_FOO` - This this for the other thing
