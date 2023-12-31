//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "Settings.h"
#include "CONFIG.h"
#include "ConfigPin.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SettingsClass Settings;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SettingsClass::SettingsClass()
{
  eeprom = NULL;
  timer = DATA_MEASURE_THRESHOLD;
  
  voltage3V3.raw = voltage5V.raw = voltage200V.raw = 0;
  voltage3V3.voltage = voltage5V.voltage = voltage200V.voltage = 0;
//
//  relayDelay = RELAY_WANT_DATA_AFTER;
//  acsDelay = ACS_SIGNAL_DELAY;
//
//  currentCoeff = CURRENT_COEFF_DEFAULT; // коэффициент тока по умолчанию
//  channelPulses = 0;
//  channelDelta = 0;
//  motoresource = 0;
//  motoresourceMax = 0;
//  transformerHighBorder = TRANSFORMER_HIGH_DEFAULT_BORDER;
//  transformerLowBorder = TRANSFORMER_LOW_DEFAULT_BORDER;
//  skipCounter = INTERRUPT_SKIP_COUNTER;
//
//  asuTpFlags = 0xFF; // выдаём сигналы на все линии АСУ ТП
//
//#ifndef DISABLE_CATCH_ENCODER_DIRECTION
//  rodDirection = rpBroken;
//#else
//  rodDirection = rpUp;
//#endif
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
String SettingsClass::getUUID(const char* passedUUID)
{
    String savedUUID;

    if(!eeprom)
    {
      return savedUUID;
    }
    
    uint32_t addr = UUID_STORE_ADDRESS;
    uint8_t header1 = eeprom->read(addr); addr++;
    uint8_t header2 = eeprom->read(addr); addr++;
    uint8_t header3 = eeprom->read(addr); addr++;

    if(!(header1 == RECORD_HEADER1 && header2 == RECORD_HEADER2 && header3 == RECORD_HEADER3))
    {
      savedUUID = passedUUID;

      addr = UUID_STORE_ADDRESS;
      eeprom->write(addr,RECORD_HEADER1); addr++;
      eeprom->write(addr,RECORD_HEADER2); addr++;
      eeprom->write(addr,RECORD_HEADER3); addr++;

      uint8_t written = 0;
      for(size_t i=0;i<savedUUID.length();i++)
      {
        eeprom->write(addr,savedUUID[i]); 
        addr++;
        written++;
      }

      for(int i=written;i<32;i++)
      {
         eeprom->write(addr,'\0'); 
         addr++;
      }

      return savedUUID;
    }

    // есть сохранённый GUID, читаем его
    for(int i=0;i<32;i++)
    {
      char ch = (char) eeprom->read(addr); addr++;;
      if(!ch)
      {
        break;
      }
      savedUUID += ch;
    }

    return savedUUID;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::write8(uint32_t addr, uint8_t val)
{
  if(!eeprom)
  {
    return;    
  }

    uint32_t writeaddr = addr;
    eeprom->write(writeaddr,RECORD_HEADER1);writeaddr++;
    eeprom->write(writeaddr,RECORD_HEADER2);writeaddr++;
    
    uint8_t* writePtr = (uint8_t*)&val;
    eeprom->write(writeaddr,writePtr,sizeof(val)); 
    
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::write16(uint32_t addr, uint16_t val)
{
  if(!eeprom)
  {
    return;    
  }

    uint32_t writeaddr = addr;
    eeprom->write(writeaddr,RECORD_HEADER1);writeaddr++;
    eeprom->write(writeaddr,RECORD_HEADER2);writeaddr++;
    
    uint8_t* writePtr = (uint8_t*)&val;
    eeprom->write(writeaddr,writePtr,sizeof(val)); 
    
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::write32(uint32_t addr, uint32_t val)
{
  if(!eeprom)
  {
    return;    
  }

    uint32_t writeaddr = addr;
    eeprom->write(writeaddr,RECORD_HEADER1);writeaddr++;
    eeprom->write(writeaddr,RECORD_HEADER2);writeaddr++;
    
    uint8_t* writePtr = (uint8_t*)&val;
    eeprom->write(writeaddr,writePtr,sizeof(val)); 
    
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool SettingsClass::read8(uint32_t addr, uint8_t& val)
{
  val = 0xFF;
  
  if(!eeprom)
  {
    return false;
  }

  uint32_t readAddr = addr;
  uint8_t header1, header2;
  header1 = eeprom->read(readAddr);readAddr++;
  header2 = eeprom->read(readAddr);readAddr++;

  if(RECORD_HEADER1 == header1 && RECORD_HEADER2 == header2)
  {
     uint8_t* writePtr = (uint8_t*)&val;
     eeprom->read(readAddr,writePtr,sizeof(val));
     return true;//(val != 0xFF);
  }
  #ifdef _SETTINGS_LOAD_DEBUG
  else
  {
      Serial.print("Settings:read8 - BAD HEADER AT ADDRESS ");
      Serial.println(addr);
  }
  #endif

  return false;      
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool SettingsClass::read16(uint32_t addr, uint16_t& val)
{
  val = 0xFFFF;
  
  if(!eeprom)
  {
    return false;
  }

  uint32_t readAddr = addr;
  uint8_t header1, header2;
  header1 = eeprom->read(readAddr);readAddr++;
  header2 = eeprom->read(readAddr);readAddr++;

  if(RECORD_HEADER1 == header1 && RECORD_HEADER2 == header2)
  {
     uint8_t* writePtr = (uint8_t*)&val;
     eeprom->read(readAddr,writePtr,sizeof(val));
     return true;//(val != 0xFFFF);
  }
  #ifdef _SETTINGS_LOAD_DEBUG
  else
  {
      Serial.print("Settings:read16 - BAD HEADER AT ADDRESS ");
      Serial.println(addr);
  }
  #endif

  return false;      
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool SettingsClass::read32(uint32_t addr, uint32_t& val)
{
  val = 0xFFFFFFFF;
  
  if(!eeprom)
  {
    return false;
  }

  uint32_t readAddr = addr;
  uint8_t header1, header2;
  header1 = eeprom->read(readAddr);readAddr++;
  header2 = eeprom->read(readAddr);readAddr++;

  if(RECORD_HEADER1 == header1 && RECORD_HEADER2 == header2)
  {
     uint8_t* writePtr = (uint8_t*)&val;
     eeprom->read(readAddr,writePtr,sizeof(val));
     return true;//(val != 0xFFFFFFFF);
  }
  #ifdef _SETTINGS_LOAD_DEBUG
  else
  {
      Serial.print("Settings:read32 - BAD HEADER AT ADDRESS ");
      Serial.println(addr);
  }
  #endif

  return false;      
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::reloadSettings()
{

  if(eeprom)
  {
     // читаем настройки
 
      
  } // if(eeprom)  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SettingsClass::begin()
{
  eeprom = new EEPROM_CLASS(Wire1);
  reloadSettings();
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
void SettingsClass::set200VRawVoltage(uint16_t raw)
{
  voltage200V.raw = raw; 
  voltage200V.voltage = voltage200V.raw*(2.4 / 4096 * 100);    
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
