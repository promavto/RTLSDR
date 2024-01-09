// e.g. https://www.aliexpress.com/item/New-26-pin-3-5-inch-Raspberry-Pi-LCD-TFT-Touchscreen-Display-kit-RPI-Touch-Shield/32526486667.html
// e.g. https://www.aliexpress.com/item/3-5-TFT-LCD-Touch-Screen-Module-320-x-480-SPI-RGB-Display-For-Raspberry-Pi/32661117216.html

#include "../GxIO/GxIO_SPI/GxIO_SPI.h"
#include "../GxCTRL/GxCTRL_ILI9486/GxCTRL_ILI9486.h" // 320x480 e.g. 3.5inch RPI Display
GxIO_Class io(SPI, SS, D4, D3); // 480x320 3.5inch RPI Display on Wemos D1 (ESP8266)
GxCTRL_Class controller(io); // #define GxCTRL_Class is in the selected header file
TFT_Class tft(io, controller, 480, 320); // landscape HVGA 320x480 or 3.5inch RPI Display
//TFT_Class tft(io, controller, 320, 480); // portrait HVGA 320x480 or 3.5inch RPI Display
