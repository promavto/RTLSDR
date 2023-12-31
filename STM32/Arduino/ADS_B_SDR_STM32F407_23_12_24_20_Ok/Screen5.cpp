//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "Screen5.h"
#include "DS3231.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Screen5::Screen5() : AbstractTFTScreen("SCREEN5")
{
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen5::doSetup(TFTMenu* menu)
{
	// тут настраиваемся, например, можем добавлять кнопки

	screenButtons->setSymbolFont(VARIOUS_SYMBOLS_32x32);

	screenButtons->addButton(79, 25, 35, 35, "c",BUTTON_SYMBOL);
	screenButtons->addButton(127, 25, 35, 35, "c", BUTTON_SYMBOL);
	screenButtons->addButton(175, 25, 35, 35, "c", BUTTON_SYMBOL);
	screenButtons->addButton(79, 95, 35, 35, "d", BUTTON_SYMBOL);
	screenButtons->addButton(127, 95, 35, 35, "d", BUTTON_SYMBOL);
	screenButtons->addButton(175, 95, 35, 35, "d", BUTTON_SYMBOL);
	screenButtons->setTextFont(TFT_FONT);
	screenButtons->addButton(5, 145, 100, 30, "ВЫХОД");
	screenButtons->addButton(119, 145, 100, 30, "СОХР."); // кнопка Часы 

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen5::doUpdate(TFTMenu* menu)
{
    // тут обновляем внутреннее состояние
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen5::doDraw(TFTMenu* menu)
{
  TFT_Class* dc = menu->getDC();
  //dc->setColor(WHITE);
  //dc->setBackColor(BLACK);
  dc->setFreeFont(TFT_FONT);
 
 // получаем текущую дату
  DS3231Time dt = RealtimeClock.getTime();

  t_temp_date = dt.dayOfMonth;
  t_temp_mon = dt.month;
  t_temp_year = dt.year;
  t_temp_dow = dt.dayOfWeek;
  t_temp_hour = dt.hour;
  t_temp_min = dt.minute;
  t_temp_sec = dt.second;

  if (t_temp_date == 0)
  {
	  t_temp_date = 10;
	  t_temp_mon = 1;
	  t_temp_year = 2018;
	  t_temp_dow = 2;
	  t_temp_hour = 9;
	  t_temp_min = 0;
	  t_temp_sec = 0;
  }


  if (t_temp_hour<10)
  {
	  menu->getRusPrinter()->print("0", 81, 70);
	  menu->getRusPrinter()->print(String(t_temp_hour).c_str(), 97, 70);
  }
  else
  {
	  menu->getRusPrinter()->print(String(t_temp_hour).c_str(), 81, 70);
  }
  if (t_temp_min<10)
  {
	  menu->getRusPrinter()->print("0", 128, 70);
	  menu->getRusPrinter()->print(String(t_temp_min).c_str(), 144, 70);
  }
  else
  {
	  menu->getRusPrinter()->print(String(t_temp_min).c_str(), 128, 70);
  }
  if (t_temp_sec<10)
  {
	  menu->getRusPrinter()->print("0", 175, 70);
	  menu->getRusPrinter()->print(String(t_temp_sec).c_str(), 191, 70);
  }
  else
  {
	  menu->getRusPrinter()->print(String(t_temp_sec).c_str(), 175, 70);
  }


  
  
  // тут рисуем, что надо именно нам, кнопки прорисуются сами после того, как мы тут всё отрисуем
  menu->getRusPrinter()->print("Установка", 35, 1,BLACK, WHITE);
  menu->getRusPrinter()->print("Время", 0, 70,BLACK, WHITE);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen5::onButtonPressed(TFTMenu* menu, int pressedButton)
{
	TFT_Class* dc = menu->getDC();
//	dc->setColor(WHITE);
//	dc->setBackColor(BLACK);
  // обработчик нажатия на кнопку. Номера кнопок начинаются с 0 и идут в том порядке, в котором мы их добавляли
  if(pressedButton == 6)
    menu->switchToScreen("SCREEN4"); // переключаемся на первый экран
  else if (pressedButton == 7)
  {
	  RealtimeClock.setTime(t_temp_sec, t_temp_min, t_temp_hour, t_temp_dow, t_temp_date, t_temp_mon, t_temp_year);
  }
  else if (pressedButton == 0)
  {
	  t_temp_hour += 1;
	  if (t_temp_hour == 24)
		  t_temp_hour = 0;

    dc->fillRect(81,70,50,20,BLACK);
    
	  if (t_temp_hour<10)
	  {
		  menu->getRusPrinter()->print("0", 81, 70);
		  menu->getRusPrinter()->print(String(t_temp_hour).c_str(), 97, 70);
	  }
	  else
	  {
		  menu->getRusPrinter()->print(String(t_temp_hour).c_str(), 81, 70);
	  }
  }
  else if (pressedButton == 1)
  {
	  t_temp_min += 1;
	  if (t_temp_min == 60)
		  t_temp_min = 0;

    dc->fillRect(128,70,50,20,BLACK);
     
	  if (t_temp_min<10)
	  {
		  menu->getRusPrinter()->print("0", 128, 70);
		  menu->getRusPrinter()->print(String(t_temp_min).c_str(), 144, 70);
	  }
	  else
	  {
		  menu->getRusPrinter()->print(String(t_temp_min).c_str(), 128, 70);
	  }
  }
  else if (pressedButton == 2)
  {
	  t_temp_sec += 1;
	  if (t_temp_sec == 60)
		  t_temp_sec = 0;

    dc->fillRect(175,70,50,20,BLACK);
    
	  if (t_temp_sec<10)
	  {
		  menu->getRusPrinter()->print("0", 175, 70);
		  menu->getRusPrinter()->print(String(t_temp_sec).c_str(), 191, 70);
	  }
	  else
	  {
		  menu->getRusPrinter()->print(String(t_temp_sec).c_str(), 175, 70);
	  }
  }
  else if (pressedButton == 3)
  {
	  t_temp_hour -= 1;
	  if (t_temp_hour < 0)
		  t_temp_hour = 23;

    dc->fillRect(81,70,50,20,BLACK);
    
	  if (t_temp_hour<10)
	  {
		  menu->getRusPrinter()->print("0", 81, 70);
		  menu->getRusPrinter()->print(String(t_temp_hour).c_str(), 97, 70);
	  }
	  else
	  {
		  menu->getRusPrinter()->print(String(t_temp_hour).c_str(), 81, 70);
	  }
  }
  else if (pressedButton == 4)
  {
	  t_temp_min -= 1;
	  if (t_temp_min < 0)
		  t_temp_min = 59;

    dc->fillRect(128,70,50,20,BLACK);
    
	  if (t_temp_min<10)
	  {
		  menu->getRusPrinter()->print("0", 128, 70);
		  menu->getRusPrinter()->print(String(t_temp_min).c_str(), 144, 70);
	  }
	  else
	  {
		  menu->getRusPrinter()->print(String(t_temp_min).c_str(), 128, 70);
	  }
  }
  else if (pressedButton == 5)
  {
	  t_temp_sec -= 1;
	  if (t_temp_sec < 0)
		  t_temp_sec = 59;

    dc->fillRect(175,70,50,20,BLACK);
    
	  if (t_temp_sec<10)
	  {
		  menu->getRusPrinter()->print("0", 175, 70);
		  menu->getRusPrinter()->print(String(t_temp_sec).c_str(), 191, 70);
	  }
	  else
	  {
		  menu->getRusPrinter()->print(String(t_temp_sec).c_str(), 175, 70);
	  }
  }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
