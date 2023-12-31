// FSMC_LowLevel.h - �������������� ������� FSMC ��� LCD

// ������������� FSMC
void FSMC_Init ( void );

// ������ � ������� LCD
void FSMC_LcdWriteReg ( uint8_t LCD_Reg, uint16_t LCD_RegValue );

// ������ �������� LCD
uint16_t FSMC_LcdReadReg ( uint8_t LCD_Reg );

// ������ ������� � LCD
void FSMC_LcdWriteCmd ( uint16_t val );

// ������ ������� �� LCD
uint16_t FSMC_LcdReadCmd ( void );

// ������ ������ �� LCD
uint16_t FSMC_LcdReadData ( void );

// ������ ������ � LCD
void FSMC_LcdWriteData ( uint16_t val );

// �������� ����� ������ �� DMA � LCD
// count - ����� ������ � ������, �.�. ������ 4
void FSMC_TransferDataDMAToLCD ( void *buffer, uint32_t count, bool isRamAddressIncrement );

// �������� ����� ������ �� DMA �� LCD
// count - ����� ������ � ������, �.�. ������ 4
void FSMC_TransferDataDMAFromLCD ( void *buffer, uint32_t count );

