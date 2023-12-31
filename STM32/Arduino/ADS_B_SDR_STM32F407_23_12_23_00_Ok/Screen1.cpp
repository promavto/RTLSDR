//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "Screen1.h"
#include "DS3231.h"
#include "ConfigPin.h"
#include "ADCSampler.h"
#include "CONFIG.h"
#include "InterruptHandler.h"
#include "InterruptScreen.h"
#include "Settings.h"
#include "Utils.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Screen1* mainScreen = NULL;
extern "C" char* sbrk(int i);
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
uint32_t redCurrentInfoMax = 0; // макс. данные по току, канал 1 (красный)
uint32_t redCurrentInfoMin = 0; // мин. данные по току, канал 1 (красный)

uint32_t blueCurrentInfoMax = 0; // макс. данные по току, канал 2 (синий)
uint32_t blueCurrentInfoMin = 0; // мин. данные по току, канал 2 (синий)

uint32_t yellowCurrentInfoMax = 0; // макс. данные по току, канал 3 (желтый)
uint32_t yellowCurrentInfoMin = 0; // мин. данные по току, канал 3 (желтый)

uint8_t currentNumSamples = 0; // кол-во семплов измерений по току


uint16_t channel1Current = 0; // ток канала 1
uint16_t channel2Current = 0; // ток канала 2
uint16_t channel3Current = 0; // ток канала 3
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loopADC()
{
#ifndef _ADC_OFF

//  static bool dataHigh_old = false;
  
  if (adcSampler.available()) 
  {
    int bufferLength = 0;
    uint16_t* cBuf = adcSampler.getADCBuffer(&bufferLength);    // Получить буфер с данными


    static uint16_t countOfPoints = 0;    
    static uint16_t* serie1 = NULL;
    static uint16_t* serie2 = NULL;
    static uint16_t* serie3 = NULL;
    
    uint16_t currentCountOfPoints = bufferLength/ NUM_CHANNELS;

    if(currentCountOfPoints != countOfPoints)
    {
      countOfPoints = currentCountOfPoints;
      
      delete [] serie1;
      delete [] serie2;
      delete [] serie3;

      serie1 = new uint16_t[countOfPoints];
      serie2 = new uint16_t[countOfPoints];
      serie3 = new uint16_t[countOfPoints];

    }

 
    uint16_t serieWriteIterator = 0;

    uint32_t raw200V = 0;
    uint32_t raw5V = 0;
    uint32_t raw3V3 = 0;

  /*
    Буфер у нас для четырёх каналов, индексы:

    0 -  Аналоговый вход трансформатора №1
    1 - Аналоговый вход трансформатора №2
    2 -  Аналоговый вход трансформатора №3
    3 - Аналоговый вход контроль питания 3.3в

*/  
    
    for (int i = 0; i < bufferLength; i = i + NUM_CHANNELS, serieWriteIterator++)                // получить результат измерения поканально, с интервалом 3
    {      
	  serie1[serieWriteIterator] = cBuf[i + 0];        // Данные 1 графика  (красный)
	  serie2[serieWriteIterator] = cBuf[i + 1];        // Данные 2 графика  (синий)
	  serie3[serieWriteIterator] = cBuf[i + 2];        // Данные 3 графика  (желтый)

	  raw3V3  += cBuf[i + 3];                          // Данные Измерение 3V3
    
    //TODO: ТУТ ЗАКОММЕНТИРОВАЛ, НЕТ КОНТРОЛЯ !!!
	  raw5V   += 0;//cBuf[i + 8];                          // Данные Измерение +5V 
	  raw200V += 0;//cBuf[i + 6];                          // Данные Измерение =200В


	  } // for

    // у нас заполнен массив показаний, можно считать ток.
    // для этого собираем максимальные и минимальные значения по каждому из каналов,
    // и плюсуем их. Как только наберём нужное кол-во семплов - работаем дальше.
    uint32_t ch1Min = 0xFFFFFFFF, ch1Max = 0, ch2Min = 0xFFFFFFFF, ch2Max = 0, ch3Min = 0xFFFFFFFF, ch3Max = 0;
    
    for(uint16_t i=0;i<countOfPoints;i++)
    {
              ch1Min = min(ch1Min,serie1[i]);
              ch2Min = min(ch2Min,serie2[i]);
              ch3Min = min(ch3Min,serie3[i]);

              ch1Max = max(ch1Max,serie1[i]);
              ch2Max = max(ch2Max,serie2[i]);
              ch3Max = max(ch3Max,serie3[i]);
              
    } // for

    if(ch1Min == 0xFFFFFFFF)
    {
      ch1Min = ch1Max;
    }

    if(ch2Min == 0xFFFFFFFF)
    {
      ch2Min = ch2Max;
    }

    if(ch3Min == 0xFFFFFFFF)
    {
      ch3Min = ch3Max;
    }

    // плюсуем полученные значения в накопительную часть
    redCurrentInfoMin += ch1Min;
    blueCurrentInfoMin += ch2Min;
    yellowCurrentInfoMin += ch3Min;

    redCurrentInfoMax += ch1Max;
    blueCurrentInfoMax += ch2Max;
    yellowCurrentInfoMax += ch3Max;

    // проверяем, собрали ли нужное кол-во семплов?
    currentNumSamples++;

    if(currentNumSamples >= CURRENT_NUM_SAMPLES)
    {
      // собрали нужное кол-во семплов, можно вычислять ток по каналам.

      // Вычисляем среднее делением на Х. От максимального отнимаем минимальное - получаем размах. Это будет величина переменного тока. 
      // Вернее, измеренное напряжение, которое мы потом преобразуем в ток из расчета 3 вольта равны 5 амперам.
      
      uint32_t channel1Avg = redCurrentInfoMax/CURRENT_NUM_SAMPLES - redCurrentInfoMin/CURRENT_NUM_SAMPLES;
      uint32_t channel2Avg = blueCurrentInfoMax/CURRENT_NUM_SAMPLES - blueCurrentInfoMin/CURRENT_NUM_SAMPLES;
      uint32_t channel3Avg = yellowCurrentInfoMax/CURRENT_NUM_SAMPLES - yellowCurrentInfoMin/CURRENT_NUM_SAMPLES;

      // вычислили напряжение, теперь вычисляем ток по формуле: 3В = 5А. Для этого напряжение надо умножить на 5, и разделить на 3

      float currentCoeff = Settings.getCurrentCoeff();
      currentCoeff /= 1000; // у нас в тысячных долях
      
      channel1Current = (COEFF_1*channel1Avg)/currentCoeff;
      channel2Current = (COEFF_1*channel2Avg)/currentCoeff;
      channel3Current = (COEFF_1*channel3Avg)/currentCoeff;

      // отсекаем минимальный нижний порог
      if(channel1Current <= CURRENT_MIN_TREAT_AS_ZERO)
      {
        channel1Current = 0;
      }

      if(channel2Current <= CURRENT_MIN_TREAT_AS_ZERO)
      {
        channel2Current = 0;
      }

      if(channel3Current <= CURRENT_MIN_TREAT_AS_ZERO)
      {
        channel3Current = 0;
      }


      // не забываем чистить за собой, подготавливая к следующему обновлению
      currentNumSamples = 0;
      
      redCurrentInfoMin = 0;
      blueCurrentInfoMin = 0;
      yellowCurrentInfoMin = 0;

      redCurrentInfoMax = 0;
      blueCurrentInfoMax = 0;
      yellowCurrentInfoMax = 0;
      
    } // if
    

    raw200V /= countOfPoints;
    raw3V3 /= countOfPoints;
    raw5V /= countOfPoints;

    Settings.set3V3RawVoltage(raw3V3);
    Settings.set5VRawVoltage(raw5V);
    Settings.set200VRawVoltage(raw200V);
      
    adcSampler.reset();                                  // все данные переданы в ком

    if(mainScreen && mainScreen->isActive())
    {
      mainScreen->requestToDrawChart(serie1, serie2, serie3, countOfPoints);      
    }

  }
  /*
    if (dataHigh_old != adcSampler.dataHigh)
    {
      dataHigh_old = adcSampler.dataHigh;
    }
    */
#endif // !_ADC_OFF
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Screen1::Screen1() : AbstractTFTScreen("Main")
{
  oldsecond = 0;
  mainScreen = this;
  points1 = NULL;
  points2 = NULL;
  points3 = NULL;
  canDrawChart = false;
  inDrawingChart = false;
  last3V3Voltage = last5Vvoltage = last200Vvoltage = -1;
  canLoopADC = false;
  isRS485Online = false;
  oldChannel1Current = oldChannel2Current = oldChannel3Current = 0xFFFF;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::drawSDSpeedInfo(TFTMenu* menu)
{
    if(!isActive())
    {
      return;      
    }  

  TFT_Class* dc = menu->getDC();
  dc->setFreeFont(TFT_SMALL_FONT); 

 uint16_t curX = 190;
  uint16_t curY = 80;

  word bgcolor = RED;
  word fgcolor = BLACK;

  if(sdSpeed.testSucceeded && (sdSpeed.writeSpeed >= MIN_SD_WRITE_SPEED) && (sdSpeed.readSpeed >= MIN_SD_READ_SPEED))
  {
    bgcolor = GREEN;
  }

  const char* str = "  SD   ";
  menu->getRusPrinter()->print(str,curX,curY,bgcolor,fgcolor);


  bgcolor = BLACK;

  if(sdSpeed.readSpeed >= MIN_SD_READ_SPEED)
  {
    fgcolor = GREEN;
  }
  else
  {
    fgcolor = RED;
  }
      

  curX = 180;
  curY += 16;
  
  String strSpeed;
  strSpeed = char(188);
  strSpeed += " ";
  strSpeed += sdSpeed.readSpeed;

  menu->getRusPrinter()->print(strSpeed.c_str(),curX,curY,bgcolor,fgcolor);

  if(sdSpeed.writeSpeed >= MIN_SD_WRITE_SPEED)
  {
    fgcolor = GREEN;
  }
  else
  {
    fgcolor = RED;
  }

  curY += 16;
  strSpeed = char(187);
  strSpeed += " ";
  strSpeed += sdSpeed.writeSpeed;

  menu->getRusPrinter()->print(strSpeed.c_str(),curX,curY,bgcolor,fgcolor);
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::drawRS485State(TFTMenu* menu)
{
    if(!isActive())
    {
      return;      
    }

  TFT_Class* dc = menu->getDC();
  dc->setFreeFont(TFT_SMALL_FONT);  

  uint16_t curX = 190;
  uint16_t curY = 20;

  word bgcolor = RED;
  word fgcolor = BLACK;

  if(isRS485Online)
  {
    bgcolor = GREEN;
  }

  const char* str = "RS485";
  menu->getRusPrinter()->print(str,curX,curY,bgcolor,fgcolor);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
void Screen1::drawVoltage(TFTMenu* menu)
{
#ifndef _DISABLE_DRAW_VOLTAGE
  if(!isActive())
  {
    return;
  }

  word color = RED;
  TFT_Class* dc = menu->getDC();
  
  dc->setFreeFont(TFT_SMALL_FONT);
  uint8_t fontHeight = FONT_HEIGHT(dc);
  
  uint16_t curX = 190;
  uint16_t curY = 20;

  VoltageData vData = Settings.get3V3Voltage();// Контроль источника питания +3.3в

  if(last3V3Voltage != vData.raw)
  {
    last3V3Voltage = vData.raw;
    
    float threshold = (3.3/100)*VOLTAGE_THRESHOLD;
    float lowBorder = 3.3 - threshold;
    float highBorder = 3.3 + threshold;
  
    if(vData.voltage >= lowBorder && vData.voltage <= highBorder)
    {
      color = GREEN;
    }
  
    int32_t vDataI = vData.voltage*10;
    String data;
    data = int32_t(vDataI/10);
    data += '.';
    data += abs(vDataI%10);
    data += "V";
    
    while(data.length() < 4)
    {
      data += ' ';
    }      

    menu->getRusPrinter()->print(data.c_str(),curX,curY,BLACK,color);
  }
*/
  //TODO: ЗАКОММЕНТИРОВАЛ ОТРИСОВКУ ВОЛЬТАЖА 5В и 200В!!!
  /*
  curY += fontHeight + 2;
  
  
  vData = Settings.get5Vvoltage();        // Контроль источника питания +5.0в

  if(last5Vvoltage != vData.raw)
  {
    last5Vvoltage = vData.raw;
    
    float threshold = (5.0/100)*VOLTAGE_THRESHOLD;
    float lowBorder = 5.0 - threshold;
    float highBorder = 5.0 + threshold;
  
    color = RED;
  
    if(vData.voltage >= lowBorder && vData.voltage <= highBorder)
    {
      color = GREEN;
    }
  
    int32_t vDataI = vData.voltage*10;
    String data;
    data = int32_t(vDataI/10);
    data += '.';
    data += abs(vDataI%10);
    data += "V";
    
    while(data.length() < 4)
    {
      data += ' ';
    }
  
    menu->getRusPrinter()->print(data.c_str(),curX,curY,BLACK,color);
  }
  
  curY += fontHeight + 2;

  
  vData = Settings.get200Vvoltage();      // Контроль источника питания 200в

  if(last200Vvoltage != vData.raw)
  {
    last200Vvoltage = vData.raw;
    
    float threshold = (200.0/100)*VOLTAGE_THRESHOLD;
    float lowBorder = 200.0 - threshold;
    float highBorder = 200.0 + threshold;
  
    color = RED;
  
    if(vData.voltage >= lowBorder && vData.voltage <= highBorder)
    {
      color = GREEN;
    }
  
    String data = String((uint16_t)vData.voltage) + "V";
    
    while(data.length() < 4)
    {
      data += ' ';
    }
  
    menu->getRusPrinter()->print(data.c_str(),curX,curY,BLACK,color);
  }
  */
/*
#endif // !_DISABLE_DRAW_VOLTAGE
   
}
*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::onDeactivate()
{
  // станем неактивными, надо выключить подписчика результатов прерываний
  InterruptHandler.setSubscriber(NULL);
  
  last3V3Voltage = last5Vvoltage = last200Vvoltage = -1;
  
  // прекращаем отрисовку графика
  chart.stopDraw();
  inDrawingChart = false;
  canDrawChart = false;
  isRS485Online = false;

#ifndef _ADC_OFF
	canLoopADC = false;
#endif // !_ADC_OFF

//  DBGLN(F("MainScreen::onDeactivate()"));
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::onActivate()
{
#ifndef _ADC_OFF
  canLoopADC = true;
#endif // !_ADC_OFF

  oldChannel1Current = oldChannel2Current = oldChannel3Current = 0xFFFF;
  oldCurrentString1 = oldCurrentString2 = oldCurrentString3 = "";

  isRS485Online = HasRS485Link;

  // мы активизируемся, назначаем подписчика результатов прерываний
  InterruptHandler.setSubscriber(ScreenInterrupt);

  //DBGLN(F("MainScreen::onActivate()"));
  
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::doSetup(TFTMenu* menu)
{
#ifndef _DISABLE_MAIN_SCREEN_BUTTONS
	screenButtons->setSymbolFont(VARIOUS_SYMBOLS_32x32);
	// тут настраиваемся, например, можем добавлять кнопки
	screenButtons->addButton(5, 140, 165, 30, "НАСТРОЙКИ");
	screenButtons->addButton(179, 130, 35, 40, "z", BUTTON_SYMBOL); // кнопка Часы 
#endif // !_DISABLE_MAIN_SCREEN_BUTTONS

	// ТУТ НАСТРАИВАЕМ НАШ ГРАФИК
	// устанавливаем ему начальные точки отсчёта координат

	chart.setCoords(5, 120);
	// говорим, какое у нас кол-во точек по X и по Y
	chart.setPoints(CHART_POINTS_COUNT,100);
	// добавляем наши тестовые графики, количеством 1

	serie1 = chart.addSerie({ 255,0,0 });     // первый график - красного цвета
	serie2 = chart.addSerie({ 0,0,255 });     // второй график - голубого цвета
	serie3 = chart.addSerie({ 255,255,0 });   // третий график - желтого цвета


}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::drawTime(TFTMenu* menu)
{

#ifndef _DISABLE_DRAW_TIME
    DS3231Time tm = RealtimeClock.getTime();
    if (oldsecond != tm.second)
    {
      TFT_Class* dc = menu->getDC();
      dc->setFreeFont(TFT_SMALL_FONT);
      
        oldsecond = tm.second;

      // получаем компоненты даты в виде строк
      String strDate = RealtimeClock.getDateStr(tm);
      String strTime = RealtimeClock.getTimeStr(tm);
  
      // печатаем их
      menu->print(strDate.c_str(), 5, 1);
      menu->print(strTime.c_str(), 90, 1);
  
#ifndef _DISABLE_DRAW_RAM_ON_SCREEN
      
      String str = "RAM: ";
      str += getFreeMemory();      
      Screen.print(str.c_str(), 10,123);
#endif // !_DISABLE_DRAW_RAM_ON_SCREEN
      
    }

#endif // !_DISABLE_DRAW_TIME

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::drawCurrent(TFTMenu* menu)
{

  if(!isActive())
  {
    return;      
  }  

    TFT_Class* dc = menu->getDC();  

  dc->setFreeFont(TFT_SMALL_FONT);
  uint8_t fontHeight = FONT_HEIGHT(dc);
  const uint8_t y_spacing = 1;
  
  uint16_t curX = 190;
  uint16_t curY = 36;  

  word bgcolor = BLACK;
  word fgcolor = RED;

  // не забываем, что раз у нас разрядность АЦП - в микровольтах (3.3/4095 = 0.0008 В), то и результат у нас - в микроамперах  
  if(oldChannel1Current != channel1Current)
  {
//    DBG("CHANNEL 1 CURRENT: "); DBGLN(channel1Current);
    
    menu->getRusPrinter()->print(oldCurrentString1.c_str(),curX,curY,bgcolor,bgcolor);
    
    oldChannel1Current = channel1Current;
    oldCurrentString1 = formatFloat(float(oldChannel1Current)/CURRENT_DIVIDER,2);
    oldCurrentString1 += "A";

    menu->getRusPrinter()->print(oldCurrentString1.c_str(),curX,curY,bgcolor,fgcolor);
  }

  fgcolor = BLUE;
  curY += fontHeight + y_spacing;

 if(oldChannel2Current != channel2Current)
  {
//    DBG("CHANNEL 2 CURRENT: "); DBGLN(channel2Current);
    
    menu->getRusPrinter()->print(oldCurrentString2.c_str(),curX,curY,bgcolor,bgcolor);
    
    oldChannel2Current = channel2Current;
    oldCurrentString2 = formatFloat(float(oldChannel2Current)/CURRENT_DIVIDER,2);
    oldCurrentString2 += "A";

    menu->getRusPrinter()->print(oldCurrentString2.c_str(),curX,curY,bgcolor,fgcolor);
  }  

 fgcolor = YELLOW;
  curY += fontHeight + y_spacing;

 if(oldChannel3Current != channel3Current)
  {

//    DBG("CHANNEL 3 CURRENT: "); DBGLN(channel3Current);
    

    menu->getRusPrinter()->print(oldCurrentString3.c_str(),curX,curY,bgcolor,bgcolor);
    
    oldChannel3Current = channel3Current;
    oldCurrentString3 = formatFloat(float(oldChannel3Current)/CURRENT_DIVIDER,2);
    oldCurrentString3 += "A";

    menu->getRusPrinter()->print(oldCurrentString3.c_str(),curX,curY,bgcolor,fgcolor);
  }    
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::doUpdate(TFTMenu* menu)
{


  drawTime(menu);
//  drawVoltage(menu);
  drawCurrent(menu);
  drawChart();

  bool hasrs = HasRS485Link;
  if(isRS485Online != hasrs)
  {
    isRS485Online = hasrs;
    drawRS485State(menu);
  }

#ifndef _ADC_OFF
  if(canLoopADC)
    loopADC();
#endif // !_ADC_OFF
	// тут обновляем внутреннее состояние
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
uint16_t Screen1::getSynchroPoint(uint16_t* points, uint16_t pointsCount)
{
 //Тут синхронизируем график, ища нужную нам точку, с которой мы его выводим
  const uint16_t lowBorder = 100; // нижняя граница, по которой ищем начало
  const uint16_t wantedBorder = 2048; // граница синхронизации
  const uint16_t maxPointToSeek = 48; // сколько точек просматриваем вперёд, для поиска значения синхронизации


  /*for(uint16_t i=0;i<pointsCount;i++)
  {
    Serial.print("Point #"); Serial.print((i+1)); Serial.print("="); Serial.println(points[i]);
  }*/

  if(pointsCount <= CHART_POINTS_COUNT || pointsCount <= maxPointToSeek)
  {
    // кол-во точек уже равно кол-ву точек на графике, синхронизировать начало - не получится
    return 0;
  }
  
  // у нас условия - ищем первый 0, после него ищём первый 2048. Если найдено за 30 первых точек - выводим следующие 150.
  // если не найдено - просто выводим первые 150 точек
  

  uint16_t iterator = 0;
  bool found = false;
  for(; iterator < maxPointToSeek; iterator++)
  {
    if(points[iterator] <= lowBorder)
    {
      // нашли нижнюю границу
      found = true;
      break;
    }
  }

  if(!found)
  {
    // нижняя граница не найдена, просто рисуем как есть
    //DBGLN(F("Low border not found!!!!"));
    return 0;
  }

  found = false;

  // теперь ищем нужную границу для синхронизации
  for(; iterator < maxPointToSeek; iterator++)
  {
    if(points[iterator] >= wantedBorder)
    {
      // нашли границу синхронизации
      found = true;
      break;
    }
  } // for

  if(!found)
  {
    // за maxPointToSeek мы так и не нашли значение синхронизации, выводим как есть
    //DBGLN(F("High border not found!!!!"));
    return 0;
  }

  //DBGLN(F("Found shift: "));
  //DBGLN((&(points[iterator]) - points));

  // нужная граница синхронизации найдена - выводим график, начиная с этой точки
 return ( (&(points[iterator]) - points) ); 
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::requestToDrawChart(uint16_t* _points1,   uint16_t* _points2,  uint16_t* _points3, uint16_t pointsCount)
{
  if(inDrawingChart)
  {
    chart.stopDraw();
  }

  canDrawChart = true;
  inDrawingChart = false;
  
  points1 = _points1;
  points2 = _points2;
  points3 = _points3;

  int shift = getSynchroPoint(points1,pointsCount);
  int totalPoints = min(CHART_POINTS_COUNT, (pointsCount - shift));

  serie1->setPoints(&(points1[shift]), totalPoints);
  serie2->setPoints(&(points2[shift]), totalPoints);
  serie3->setPoints(&(points3[shift]), totalPoints);
    
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::drawChart()
{

  if(!isActive() || !canDrawChart || inDrawingChart)
    return;

  inDrawingChart = true;    
	// рисуем сетку
	int gridX = 5; // начальная координата сетки по X
	int gridY = 20; // начальная координата сетки по Y
	int columnsCount = 6; // 5 столбцов
	int rowsCount = 4; // 6 строк
	int columnWidth = 25; // ширина столбца
	int rowHeight = 25; // высота строки 
	RGBColor gridColor = { 0,200,0 }; // цвет сетки


  static uint32_t fpsMillis = 0;
  uint32_t now = millis();

  if(now - fpsMillis > (1000/CHART_FPS) )
  {
  	// вызываем функцию для отрисовки сетки, её можно вызывать из каждого класса экрана
  	Drawing::DrawGrid(gridX, gridY, columnsCount, rowsCount, columnWidth, rowHeight, gridColor);
  
  	chart.draw();// просим график отрисовать наши серии

   fpsMillis = millis();
  }

  inDrawingChart = false;
  canDrawChart = false;

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::doDraw(TFTMenu* menu)
{
//  DBGLN(F("MainScreen::doDraw()"));
  
  drawTime(menu);
  drawCurrent(menu);

#ifndef _DISABLE_DRAW_SOFTWARE_VERSION

  // рисуем версию ПО
  TFT_Class* dc = menu->getDC();
  dc->setFreeFont(TFT_SMALL_FONT);

  uint16_t w = dc->width();
  String str = SOFTWARE_VERSION;

  int strW = menu->getRusPrinter()->textWidth(str.c_str());

  int top = 1;
  int left = w - strW - 3;

  menu->print(str.c_str(),left,top);

  drawRS485State(menu);
  drawSDSpeedInfo(menu);
  
#endif // !_DISABLE_DRAW_SOFTWARE_VERSION

    
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1::onButtonPressed(TFTMenu* menu, int pressedButton)
{
#ifndef _DISABLE_MAIN_SCREEN_BUTTONS
  // обработчик нажатия на кнопку. Номера кнопок начинаются с 0 и идут в том порядке, в котором мы их добавляли
	if (pressedButton == 0)
	{
		menu->switchToScreen("Settings"); // переключаемся на экран работы с SD
	}
	else if (pressedButton == 1)
	{
		menu->switchToScreen("SCREEN4"); // переключаемся на третий экран
	}
#endif // !_DISABLE_MAIN_SCREEN_BUTTONS
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int Screen1::getFreeMemory()
{
    char top = 't';
    return &top - reinterpret_cast<char*>(sbrk(0));

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
