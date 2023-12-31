//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "Settings.h"
#include "CONFIG.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SettingsClass Settings;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SettingsClass::SettingsClass()
{
 
  timer = DATA_MEASURE_THRESHOLD;
  
  voltage3V3.raw = voltage5V.raw =  0;
  voltage3V3.voltage = voltage5V.voltage =  0;

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::begin()
{

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::set3V3RawVoltage(uint16_t raw)
{
   voltage3V3.raw = raw;  
   voltage3V3.voltage = voltage3V3.raw*(3.3 / 4096 * 2);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::set5VRawVoltage(uint16_t raw)
{
  voltage5V.raw = raw; 
  voltage5V.voltage = voltage5V.raw*(2.4 / 4096 * 2);
  
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::update()
{
#ifndef _CORE_TEMP_OFF

  uint32_t now = millis();
  
  if(now - timer > DATA_MEASURE_THRESHOLD)
  {
    timer = now;
    coreTemp = RealtimeClock.getTemperature();  
  }

#endif // !_CORE_TEMP_OFF  
}

void  SettingsClass::setVer(String ver)
{
    ver_prog = ver;
}

String  SettingsClass::getVer()
{
    return ver_prog;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
