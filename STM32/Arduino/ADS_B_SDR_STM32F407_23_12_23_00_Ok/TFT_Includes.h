#pragma once
//--------------------------------------------------------------------------------------------------------------------------------------
//#include <XPT2046_STM.h>   // Подключение тачсрина
#include "TFT_Touch.h"
#include <GxTFT.h>         // Hardware-specific library // Настройки дисплея
#include <GxIO/STM32GENERIC/GxIO_STM32F4_FSMC/GxIO_STM32F4_FSMC.h>
#include <GxCTRL/GxCTRL_ILI9341/GxCTRL_ILI9341.h> // 240x320
//--------------------------------------------------------------------------------------------------------------------------------------

#include "Fonts/GFXFF/gfxfont.h"
#include "BigRusFont.h"
#include "SmallRusFont.h"
#include "Various_Symbols_32x32.h"
#include "Various_Symbols_16x32.h"

#define FONTTYPE const GFXfont*
//--------------------------------------------------------------------------------------------------------------------------------------
#define TFT_Class GxTFT         // класс поддержки TFT
#define TOUCH_Class MyTFTTouch //XPT2046_STM // класс поддержки тача

#define TFT_FONT (&BigRusFont) // какой шрифт юзаем
#define TFT_SMALL_FONT (&SmallRusFont) // какой шрифт юзаем
#define VARIOUS_SYMBOLS_32x32 (&Various_Symbols_32x32)
#define VARIOUS_SYMBOLS_16x32 (&Various_Symbols_16x32)


//--------------------------------------------------------------------------------------------------------------------------------------
#define FONT_HEIGHT(dc) dc->fontHeight(1)
//--------------------------------------------------------------------------------------------------------------------------------------
