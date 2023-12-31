#include "TFTMenu.h"
#include "CONFIG.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TFTMenu* tftMenuManager;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
AbstractTFTScreen::AbstractTFTScreen(const char* name)
{
  screenName = name;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
AbstractTFTScreen::~AbstractTFTScreen()
{
  delete screenButtons;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void AbstractTFTScreen::setup(TFTMenu* menu)
{
  screenButtons = new TFT_Buttons_Rus(menu->getDC(), menu->getTouch(),menu->getRusPrinter());
  screenButtons->setTextFont(TFT_FONT);
  screenButtons->setButtonColors(TFT_BUTTON_COLORS);

  doSetup(menu);
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void AbstractTFTScreen::update(TFTMenu* menu)
{
  if(isActive())
  {
  int pressedButton = screenButtons->checkButtons();
  
  if(pressedButton != -1)
  {
    menu->notifyAction(this);
    onButtonPressed(menu, pressedButton);
  }

    if(isActive())
      doUpdate(menu);
  }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void AbstractTFTScreen::draw(TFTMenu* menu)
{
  if(isActive())
  {
    doDraw(menu);
    
    if(isActive())
      screenButtons->drawButtons(); 
  }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TFTMenu
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TFTMenu::TFTMenu()
{
  currentScreenIndex = -1;
  requestedToActiveScreen = NULL;
  requestedToActiveScreenIndex = -1;
  on_action = NULL;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void TFTMenu::notifyAction(AbstractTFTScreen* screen)
{
  if(on_action)
    on_action(screen);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void TFTMenu::addScreen(AbstractTFTScreen* screen)
{
  screen->setup(this);
  screens.push_back(screen);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void TFTMenu::setup()
{
  tftMenuManager = this;

  controller = new GxCTRL_Class(io);   

  tftDC = new TFT_Class(io, *controller, 320, 240);   // landscape 240x320
  tftTouch = new TOUCH_Class(TFT_TOUCH_CS_PIN,-1,TOUCH_SCALE_X,TOUCH_SCALE_Y,TOUCH_MIN_RAW_X,TOUCH_MAX_RAW_X,TOUCH_MIN_RAW_Y,TOUCH_MAX_RAW_Y);

  #if TFT_INIT_DELAY > 0
  delay(TFT_INIT_DELAY);
  #endif
  
  tftDC->init();
  tftDC->setRotation(1);
  tftDC->fillScreen(TFT_BACK_COLOR);
  tftDC->setFreeFont(TFT_FONT);

  //tftTouch->InitTouch(TFT_ORIENTATION);
  //tftTouch->setPrecision(TOUCH_PRECISION);
  tftTouch->begin();
  
  
  rusPrint.init(tftDC);

  // добавляем экран мессадж-бокса
  addScreen(MessageBoxScreen::create());

  // добавляем экран экранной клавиатуры
  addScreen(KeyboardScreen::create());
  

  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int TFTMenu::print(const char* str,int x, int y)
{
  return rusPrint.print(str,x,y);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void TFTMenu::update()
{

  if(requestedToActiveScreen != NULL)
  {
    // попросили сделать экран активным
    AbstractTFTScreen* screen = requestedToActiveScreen;
    currentScreenIndex = requestedToActiveScreenIndex;
    
    requestedToActiveScreen = NULL;

//	DBG(F("Активируем экран "));
//	DBGLN(screen->getName());
    
    screen->setActive(true);
    screen->onActivate();

    tftDC->fillScreen(TFT_BACK_COLOR); // clear screen first


    screen->update(this);
    screen->draw(this);

//	DBG(F("Экран "));
//	DBG(screen->getName());
//	DBGLN(F(" отрисован."));

    return;
    
  } // if(requestedToActiveScreen != NULL)

  if(currentScreenIndex == -1) // ни разу не рисовали ещё ничего, исправляемся
  {
    if(screens.size())
    {
     switchToScreen((unsigned int)0); // переключаемся на первый экран, если ещё ни разу не показали ничего     
    }
  }

  if(currentScreenIndex == -1)
  {
    return;
  }

  // обновляем текущий экран
  AbstractTFTScreen* currentScreen = screens[currentScreenIndex];
  currentScreen->update(this);
  
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
AbstractTFTScreen* TFTMenu::getActiveScreen()
{
  if(currentScreenIndex < 0 || !screens.size())
    return NULL;

  return screens[currentScreenIndex];
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void TFTMenu::switchToScreen(AbstractTFTScreen* screen)
{

	if (requestedToActiveScreen != NULL) // ждём переключения на новый экран
	{
		//DBGLN(F("Ждём переключения на какой-то экран!"));
		return;
	}
  
  if(currentScreenIndex > -1 && screens.size())
  {
     AbstractTFTScreen* si = screens[currentScreenIndex];

	 //DBG(F("Деактивируем экран "));
	 //DBGLN(si->getName());

     si->setActive(false);
     si->onDeactivate();
  }
  
  for(size_t i=0;i<screens.size();i++)
  {
    if(screens[i] == screen)
    {
		//DBG(F("Переключаемся на экран "));
		//DBGLN(screen->getName());

      requestedToActiveScreen = screen;
      requestedToActiveScreenIndex = i;

      break;
    }
  }  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void TFTMenu::switchToScreen(unsigned int screenIndex)
{
  if(screenIndex < screens.size())
  {
      switchToScreen(screens[screenIndex]);
  }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void TFTMenu::switchToScreen(const char* screenName)
{
  
  // переключаемся на запрошенный экран
  for(size_t i=0;i<screens.size();i++)
  {
    AbstractTFTScreen* si = screens[i];
    if(!strcmp(si->getName(),screenName))
    {
		//DBG(F("Переключаемся на экран "));
		//DBGLN(screenName);
      switchToScreen(si);
      break;
    }
  }

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TFTMenu Screen;
MessageBoxScreen* MessageBox;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MessageBoxScreen::MessageBoxScreen() : AbstractTFTScreen("MessageBox")
{
  targetOkScreen = NULL;
  targetCancelScreen = NULL; 
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MessageBoxScreen::doSetup(TFTMenu* menu)
{

  yesButton = screenButtons->addButton(5, 107, 210, 30, "ДА");
  noButton = screenButtons->addButton(5, 142, 210, 30, "НЕТ");


}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MessageBoxScreen::doUpdate(TFTMenu* menu)
{
    // тут обновляем внутреннее состояние
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MessageBoxScreen::doDraw(TFTMenu* menu)
{
  TFT_Class* dc = menu->getDC();
//  uint8_t* oldFont = dc->getFont();

  dc->setFreeFont(TFT_FONT);

   int fontHeight = FONT_HEIGHT(dc);
   int displayWidth = dc->width();
   int lineSpacing = 2;  

   int curX = 0;
   int curY = 10;

    for(size_t i=0;i<lines.size();i++)
    {
      int lineLength = menu->getRusPrinter()->textWidth(lines[i]);
      curX = (displayWidth - lineLength)/2;    
      menu->print(lines[i],curX,curY);
      curY += fontHeight + lineSpacing;
    }
  

//  dc->setFont(oldFont);

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MessageBoxScreen::onButtonPressed(TFTMenu* menu, int pressedButton)
{
  if(pressedButton == noButton && targetCancelScreen)
  {
    menu->switchToScreen(targetCancelScreen);
  }
  else  
  if(pressedButton == yesButton && targetOkScreen)
  {
    menu->switchToScreen(targetOkScreen);
  }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MessageBoxScreen::show(Vector<const char*>& _lines, const char* okTarget)
{
  lines = _lines;
  screenButtons->relabelButton(yesButton,"ОК");
  screenButtons->hideButton(noButton);

  if(!okTarget)
  {
    screenButtons->hideButton(yesButton);  
  }
  else
  {
    screenButtons->showButton(yesButton);      
  }
  
  targetOkScreen = okTarget;
  targetCancelScreen = NULL;

  Screen.switchToScreen(this);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MessageBoxScreen::confirm(Vector<const char*>& _lines, const char* okTarget, const char* cancelTarget)
{
  lines = _lines;

  screenButtons->relabelButton(yesButton,"ДА");
  screenButtons->relabelButton(noButton,"НЕТ");
  
  screenButtons->showButton(noButton);
  screenButtons->showButton(yesButton);
  
  targetOkScreen = okTarget;
  targetCancelScreen = cancelTarget;

  Screen.switchToScreen(this);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
AbstractTFTScreen* MessageBoxScreen::create()
{
    MessageBox = new MessageBoxScreen();
    return MessageBox;  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// KeyboardScreen
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
KeyboardScreen* ScreenKeyboard;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
AbstractTFTScreen* KeyboardScreen::create()
{
  ScreenKeyboard = new KeyboardScreen();
  return ScreenKeyboard;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
KeyboardScreen::KeyboardScreen() : AbstractTFTScreen("KBD")
{
  targetInput = NULL;
  targetScreen = NULL;

  // максимум 8 символов в HEX-представлении
  input_maxlength = 8;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void KeyboardScreen::doSetup(TFTMenu* menu)
{
  const char* capts[] = 
  {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"
  };

  const uint8_t buttons_in_row = 4;
  const uint8_t total_rows = 4;
  
  const uint8_t btn_width = 50;
  const uint8_t btn_height = 25;

  int curTop = 30;
  int btnCntr = 0;

  int curLeft;

  for(uint8_t i=0;i<total_rows;i++)
  {
    curLeft = 4;
    for(uint8_t j=0;j<buttons_in_row;j++)
    {
      screenButtons->addButton(curLeft, curTop, btn_width, btn_height, capts[btnCntr]);
      btnCntr++;
      curLeft += btn_width + 2;
    } // for
    
    curTop += btn_height + 2;
  } // for

  curLeft = 4;
  curTop += 6;
  
  const uint8_t controlButtonWidth = 66;
  const uint8_t controlButtonHeight = 30;
  
  clearButton = screenButtons->addButton(curLeft, curTop, controlButtonWidth, controlButtonHeight, "DEL");
  curLeft += controlButtonWidth + 4;

  exitButton = screenButtons->addButton(curLeft, curTop, controlButtonWidth, controlButtonHeight, "ВЫХ");
  curLeft += controlButtonWidth + 4;

  enterButton = screenButtons->addButton(curLeft, curTop, controlButtonWidth, controlButtonHeight, "ВВОД");
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void KeyboardScreen::doUpdate(TFTMenu* menu)
{
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void KeyboardScreen::doDraw(TFTMenu* menu)
{
  // сначала рисуем бокс для поля ввода
  
  TFT_Class* dc = menu->getDC();
  int screenW = dc->width();
  int boxX = 4;
  int boxY = 2;
  int boxX2 = screenW - 8;
  int boxY2 = 20;
  
  dc->drawRoundRect(boxX,boxY,boxX2,boxY2,2,WHITE);
  
  drawValue(menu);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void KeyboardScreen::onButtonPressed(TFTMenu* menu, int pressedButton)
{
  if(pressedButton < 16)
  {
    // нажата одна из кнопок ввода значений
    input += screenButtons->getLabel(pressedButton);

    //Тут проверяем на максимальную длину    
    if(input.length() > input_maxlength)
      input.remove(input_maxlength);
         
    drawValue(menu);
  }
  else
  {
    // нажата одна из управляющих кнопок
    if(pressedButton == exitButton)
    {
      if(targetInput)
        targetInput->onKeyboardInput(false,"");

      Screen.switchToScreen(targetScreen);
    }
    else
    if(pressedButton == clearButton)
    {
      input = "";
      drawValue(menu);
    }
    else
    if(pressedButton == enterButton)
    {
      if(targetInput)
        targetInput->onKeyboardInput(true,input);

      Screen.switchToScreen(targetScreen);
    }
  } // else
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void KeyboardScreen::show(KeyboardType type, const String& initialValue, AbstractTFTScreen* _targetScreen, KeyboardInputTarget* _targetInput, int maxLength)
{
  targetScreen = _targetScreen;
  targetInput = _targetInput;

  input = initialValue;
  
  if(maxLength > 0)
    input_maxlength = maxLength;
  else
    input_maxlength = 8;
      
  //Тут проверяем на максимальную длину 
  if(input.length() > input_maxlength)
     input.remove(input_maxlength);
        

  //Тут убираем некоторые кнопки, если тип != ktHex
  switch(type)
  {
    case ktDigits:
    {
      for(int i=10;i<16;i++)
        screenButtons->hideButton(i);
    }
    break; // ktDigits

    case ktHex:
    {
      for(int i=10;i<16;i++)
        screenButtons->showButton(i);      
    }
    break; // ktHex
    
  } // switch

  Screen.switchToScreen(this);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void KeyboardScreen::drawValue(TFTMenu* menu)
{
  //тут рисуем то, что введено
 int textX = 6;
 int textY = 4;

 TFT_Class* dc = menu->getDC();

 dc->setFreeFont(TFT_FONT);


// int strLen = menu->getRusPrinter()->textWidth(input.c_str());
  int screenW = dc->width();
  int boxX = 5;
  int boxY = 3;
  int boxX2 = screenW - 10;
  int boxY2 = 19;
  
  dc->fillRect(boxX,boxY,boxX2,boxY2,BLACK);

 menu->print(input.c_str(),textX,textY);

/*
 textX += strLen;

 // забиваем пробелами оставшуюся часть
 for(size_t i=strLen;i<input_maxlength;i++)
 {
   menu->print(" ",textX,textY);
   textX +=  menu->getRusPrinter()->textWidth(" ");
 }
*/

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
