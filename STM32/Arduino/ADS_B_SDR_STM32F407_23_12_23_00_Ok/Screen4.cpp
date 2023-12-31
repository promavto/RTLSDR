//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "Screen4.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Screen4::Screen4() : AbstractTFTScreen("SCREEN4")
{
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen4::doSetup(TFTMenu* menu)
{
  // тут настраиваемся, например, можем добавлять кнопки
  screenButtons->addButton( 5, 2, 210, 30, "Уст.время");
  screenButtons->addButton(5, 37, 210, 30, "Уст.дату");
 
  screenButtons->addButton(5, 140, 210, 30, "ВЫХОД");  //5, 140, 165, 30
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen4::doUpdate(TFTMenu* menu)
{
    // тут обновляем внутреннее состояние
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen4::doDraw(TFTMenu* menu)
{
  //TFT_Class* dc = menu->getDC();
  //dc->setColor(VGA_MAROON);
  //dc->setBackColor(WHITE);
  //dc->setBackColor(BLACK);
   // тут рисуем, что надо именно нам, кнопки прорисуются сами после того, как мы тут всё отрисуем
 // menu->print("Экран номер 2", 10, 0);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen4::onButtonPressed(TFTMenu* menu, int pressedButton)
{
  // обработчик нажатия на кнопку. Номера кнопок начинаются с 0 и идут в том порядке, в котором мы их добавляли
 
  if (pressedButton == 0)
	  menu->switchToScreen("SCREEN5"); // переключаемся на 5 экран
  else if (pressedButton == 1)
	  menu->switchToScreen("SCREEN6"); // переключаемся на 6 экран
  else if (pressedButton == 2)
	  menu->switchToScreen("Main"); // переключаемся на первый экран
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
