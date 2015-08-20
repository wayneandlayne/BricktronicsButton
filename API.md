# BricktronicsButton API

This library interfaces with LEGO NXT and EV3 pushbutton sensors. It can be used with the [Bricktronics Shield](https://store.wayneandlayne.com/products/bricktronics-shield-kit.html), [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html), or standalone with the [Bricktronics Breakout Board](https://store.wayneandlayne.com/products/bricktronics-breakout-board.html). For the shield/megashield, use the constructor below with the BricktronicsSensorSettings struct, otherwise use the constructor below that accepts the input pin number.

## Connection with Bricktronics Shield and Megashield

Use the pushbutton sensor with any sensor port on the Bricktronics Shield or Megashield. If the chosen sensor port has jumpers, connect pins 2-3 and 4-5.

Constructor usage for [Bricktronics Shield](https://store.wayneandlayne.com/products/bricktronics-shield-kit.html)
```C++
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
BricktronicsButton b(BricktronicsShield::SENSOR_1);
```

Constructor usage for [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html)
```C++
#include <BricktronicsMegashield.h>
BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
```

## Connection with [Bricktronics Breakout Board](https://store.wayneandlayne.com/products/bricktronics-breakout-board.html)

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


## BricktronicsButton(const BricktronicsSensorSettings &settings)

Constructor - Advanced constructor that accepts a SensorSettings struct to also override the low-level Arduino functions.

### Parameters

* **const BricktronicsSensorSettings &settings** - A reference to the struct containing all the sensor settings. Get these structs from the [BricktronicsShield](https://github.com/wayneandlayne/BricktronicsShield) or [BricktronicsMegashield](https://github.com/wayneandlayne/BricktronicsMegashield) library.


## void begin(void)

Set up the sensor library internals and pin modes. Call this function once for each instance during your setup() function.


## bool isPressed(void)

Query the button to see if it is current pressed.

### Return value

* true - If the button is currently pressed
* false - If the button is not currently pressed


## bool isReleased(void)

Query the button to see if it is current released.

### Return value

* true - If the button is not currently pressed
* false - If the button is currently pressed