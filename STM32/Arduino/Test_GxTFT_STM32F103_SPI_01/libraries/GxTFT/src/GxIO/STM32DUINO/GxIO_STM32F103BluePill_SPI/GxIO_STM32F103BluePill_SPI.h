// created by Jean-Marc Zingg to be the GxIO_SPI io class for the GxTFT library
//
// License: GNU GENERAL PUBLIC LICENSE V3, see LICENSE

#ifndef _GxIO_STM32F103BluePill_SPI_H_
#define _GxIO_STM32F103BluePill_SPI_H_
#include <SPI.h>
#include <SPI.h>
#include "../../GxIO.h"

#define GxIO_SPI_defaultFrequency 16000000

class GxIO_STM32F103BluePill_SPI : public GxIO
{
    
  public:
    GxIO_STM32F103BluePill_SPI(SPIClass& spi, int8_t cs, int8_t dc, int8_t rst , int8_t bl = -1);
    const char* name = "GxIO_SPI";
    void reset();
    void init();
    void setFrequency(uint32_t freq); // for SPI
    void setClockDivider(uint32_t clockDiv); // for SPI
    uint8_t transferTransaction(uint8_t d);
    uint16_t transfer16Transaction(uint16_t d);
    uint8_t readDataTransaction();
    uint16_t readData16Transaction();
    uint8_t readData();
    uint16_t readData16();
    void writeCommandTransaction(uint8_t c);
    void writeCommand16Transaction(uint16_t c);
    void writeDataTransaction(uint8_t d);
    void writeData16Transaction(uint16_t d, uint32_t num = 1);
    void writeCommand(uint8_t c);
    void writeCommand16(uint16_t c);
    void writeData(uint8_t d);
    void writeData(uint8_t* d, uint32_t num);
    void writeData16(uint16_t d, uint32_t num = 1);
    void writeAddrMSBfirst(uint16_t d);
    void startTransaction();
    void endTransaction();
    void selectRegister(bool rs_low); // for generalized readData & writeData (RA8875)
    void setBackLight(bool lit);
  protected:
    SPIClass& IOSPI;
    int8_t _cs, _dc, _rst, _bl; // Control lines
    
};


#define GxIO_Class GxIO_STM32F103BluePill_SPI

#endif


