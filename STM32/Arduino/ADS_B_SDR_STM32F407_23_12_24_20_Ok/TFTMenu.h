#ifndef _UTFTMENU_H
#define _UTFTMENU_H
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "TinyVector.h"
#include "CONFIG.h"

#include "TFT_Includes.h"
#include "TFT_Buttons_Rus.h"
#include "TFTRus.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class TFTMenu;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// абстрактный класс экрана для TFT
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class AbstractTFTScreen
{
  public:

    void setup(TFTMenu* menu);
    void update(TFTMenu* menu);
    void draw(TFTMenu* menu);

    const char* getName() {return screenName;}
    bool isActive() {return isActiveScreen; }
    void setActive(bool val){ isActiveScreen = val; }
  
    AbstractTFTScreen(const char* name);
    virtual ~AbstractTFTScreen();

    // вызывается, когда переключаются на экран
    virtual void onActivate(){}

    // вызывается, когда экран становится неактивным
    virtual void onDeactivate() {}

  protected:

    
    virtual void doSetup(TFTMenu* menu) = 0;
    virtual void doUpdate(TFTMenu* menu) = 0;
    virtual void doDraw(TFTMenu* menu) = 0;
    virtual void onButtonPressed(TFTMenu* menu,int pressedButton) = 0;

    TFT_Buttons_Rus* screenButtons; // кнопки на экране

    private:
      const char* screenName;
      bool isActiveScreen;
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
typedef Vector<AbstractTFTScreen*> TFTScreensList; // список экранов
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// класс-менеджер работы с TFT
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
typedef void (*OnScreenAction)(AbstractTFTScreen* screen);
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class TFTMenu
{

public:
  TFTMenu();

  void setup();
  void update();

  void addScreen(AbstractTFTScreen* screen);

  AbstractTFTScreen* getActiveScreen();
  void onAction(OnScreenAction handler) {on_action = handler;}
  void notifyAction(AbstractTFTScreen* screen);

  void switchToScreen(AbstractTFTScreen* screen);
  void switchToScreen(const char* screenName);
  void switchToScreen(unsigned int screenIndex);
  
  TFT_Class* getDC() { return tftDC; };
  TOUCH_Class* getTouch() { return tftTouch; };
  TFTRus* getRusPrinter() { return &rusPrint; };

  int print(const char* str,int x, int y);


private:

  AbstractTFTScreen* requestedToActiveScreen;
  int requestedToActiveScreenIndex;

  OnScreenAction on_action;
  
  TFTScreensList screens;

  TFT_Class* tftDC;
  TOUCH_Class* tftTouch;
  TFTRus rusPrint;

  // create instance for the selected GxIO class
  GxIO_Class io; // #define GxIO_Class is in the selected header file

  // create instance for the selected GxCTRL class
  GxCTRL_Class* controller; // #define GxCTRL_Class is in the selected header file   
    
  int currentScreenIndex;
  
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
extern TFTMenu Screen;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class MessageBoxScreen : public AbstractTFTScreen
{
  public:

  static AbstractTFTScreen* create();

  void confirm(Vector<const char*>& lines, const char* okTarget, const char* cancelTarget);
  void show(Vector<const char*>& lines, const char* okTarget);
    
protected:

    virtual void doSetup(TFTMenu* menu);
    virtual void doUpdate(TFTMenu* menu);
    virtual void doDraw(TFTMenu* menu);
    virtual void onButtonPressed(TFTMenu* menu, int pressedButton);

private:
      MessageBoxScreen();

      int noButton,yesButton;
      const char* targetOkScreen;
      const char* targetCancelScreen;
      Vector<const char*> lines;

      
     
  
  
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
extern MessageBoxScreen* MessageBox;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// работа с экранной клавиатурой
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
typedef enum
{
  ktDigits, // только 0-9
  ktHex, // 0-9, A-F
  
} KeyboardType;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// подписчик на результат ввода данных с экранной клавиатуры
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct KeyboardInputTarget
{
  virtual void onKeyboardInput(bool enterPressed, const String& enteredValue) = 0;
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// класс экранной клавиатуры
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class KeyboardScreen : public AbstractTFTScreen
{
  public:

  static AbstractTFTScreen* create();

  void show(KeyboardType type, const String& initialValue, AbstractTFTScreen* targetScreen, KeyboardInputTarget* targetInput, int maxLength=-1); 
    
protected:

    virtual void doSetup(TFTMenu* menu);
    virtual void doUpdate(TFTMenu* menu);
    virtual void doDraw(TFTMenu* menu);
    virtual void onButtonPressed(TFTMenu* menu, int pressedButton);

private:
      KeyboardScreen();
      
     String input;
     KeyboardInputTarget* targetInput;
     AbstractTFTScreen* targetScreen;

    size_t input_maxlength;

    int clearButton, enterButton, exitButton;


     void drawValue(TFTMenu* menu);
  
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
extern KeyboardScreen* ScreenKeyboard;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif
