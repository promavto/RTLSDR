#pragma once

#include "TinyVector.h"


//--------------------------------------------------------------------------------------------------------------------------------
// версия ПО
//--------------------------------------------------------------------------------------------------------------------------------
#define SOFTWARE_VERSION "ver.2023.12.20_01"  

//--------------------------------------------------------------------------------------------------------------------------------
// настройки Serial. Настройки для общения через UART
//--------------------------------------------------------------------------------------------------------------------------------
#define SerialDEBUG                  Serial    // какой Serial использовать для работы с программой UROVConfig.exe
#define Serial_SPEED                 115200    // скорость работы с Serial
#define BUFFER_SIZE                     512    // Размер буфера входящих сообщений
//--------------------------------------------------------------------------------------------------------------------------------
#define _DEBUG // закомментировать для выключения отладочной информации
//--------------------------------------------------------------------------------------------------------------------------------
#define DATA_MEASURE_THRESHOLD                      1000    // через сколько миллисекунд обновлять показания с линий вольтажа (и часов)
#define VOLTAGE_THRESHOLD                             15    // порог изменений, в процентах, для принятия решения о том, хороший вольтаж или нет

//--------------------------------------------------------------------------------------------------------------------------------
#define  _COM_COMMANDS_OFF                                 // Подключить прием команд по КОМ порту
//--------------------------------------------------------------------------------------------------------------------------------

#define TOUCH_IRQ PC15

//--------------------------------------------------------------------------------------------------------------------------------
// Настройка подсветки дисплея
//--------------------------------------------------------------------------------------------------------------------------------
#define LCD_LED PB9                   // 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Настройки пищалки
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define USE_BUZZER                    // раскомментировать, если надо использовать пищалку для звуков при нажатии кнопок TFT-экрана
#define BUZZER_DURATION  60000        // сколько микросекунд включать пищалку
#define BUZZER_PIN        PA12        // PB8 пин, на котором висит пищалка (актуально при раскомментированной команде USE_BUZZER)
#define BUZZER_LEVEL      HIGH        // уровень для включения пищалки

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Настройка контроль аккумуляторов питания Показания умножить на 2
//--------------------------------------------------------------------------------------------------------------------------------
#define POWER_BATTERY       PB1        // аналоговый вход контроля заряда аккумулятора питания. 


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// стартовые координаты верхнего/левого угла сетки
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define INTERRUPT_CHART_GRID_X_START       5 
#define INTERRUPT_CHART_GRID_Y_START      20

#define INTERRUPT_SCREEN_SEE_TIME       6000      // сколько миллисекунд демонстрировать экран с графиками прерываний?
#define INTERRUPT_CHART_X_POINTS         150      // кол-во точек по X на графике прерываний
#define INTERRUPT_CHART_Y_POINTS         100      // кол-во точек по Y на графике прерываний
#define INTERRUPT_CHART_X_COORD            5      // Х-координата графика прерываний на экране
#define INTERRUPT_CHART_Y_COORD          120      // стартовая Y-координата графика прерываний на экране
#define CHART_POINTS_COUNT               150	  // кол-во точек на графике синусоиды на главном экране

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Вход сигналов RSSI
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define RSSI_SDR        PA0      // Вход Сигнал SDR
#define RSSI_GPS        PA1      // Сигнал GPS
#define RSSI_MAX2829    PA2      // Сигнал 2,4 - 5,8 ггц

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Вход уровня порогов с переменных резисторов
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define V_THRESHOLD1     PB0      // Порог 1
#define V_THRESHOLD2     PA4      // Порог 2
#define V_THRESHOLD3     PA3      // Порог 3


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// координаты экранов сигналов RSSI
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#define  GRID_X          5    // начальная координата сетки по X
#define  GRID_Y1        20    // начальная координата сетки по Y
#define  COLUMNS_Count  10    // 6 столбцов
#define  ROWS_Count      4    // 4 строк
#define  COLUMNS_Width  18    // ширина столбца
#define  ROW_Height     18    // высота строки 

#define  GRID_Y2        92    // начальная координата сетки2 по Y
#define  GRID_Y3       184    // начальная координата сетки3 по Y

//--------------------------------------------------------------------------------------------------------------------------------
// Настройки включения питания одной кнопкой
//--------------------------------------------------------------------------------------------------------------------------------

#define POWER_ON_IN  PA15              // вход контроля подачи питания. 
#define POWER_ON_OUT PB3               // Выход управления включения питания. 
//--------------------------------------------------------------------------------------------------------------------------------
//    Управление ключами опорного напряжения
//--------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// время в миллисекундах, после которого идёт переключение на главный экран, если какой-то экран висит долгое время
#define RESET_TO_MAIN_SCREEN_DELAY 90000
// через какое время, в миллисекундах, гасить подсветку дисплея при питании от батарей
#define BACKLIGHT_OFF_DELAY          180  // секунд (3 минуты)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define TURN_POWER_OFF_DELAY        5000  // задержка выключения контроллера по нажатию кнопки выключения питания, миллисекунд
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define TIME_POWER_OFF_DELAY         300  // задержка выключения питания 5 мин от аккумулятора, секунд
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define CORRECT_DATA                  50  // признак корректного содержания данных                 

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки получения значений осциллограммы тока
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define CURRENT_COEFF_DEFAULT           3160     // коэффициент пересчёта по току (по умолчанию), в тысячных долях
#define CURRENT_TIMER_PERIOD          2000ul     // период таймера сбора информации по осциллограммам тока, микросекунд
#define CURRENT_AVG_SAMPLES                5     // количество семплов для усреднения показаний с АЦП, перед помещением их в список осциллограммы по току
#define CURRENT_LIST_SIZE                 60     // количество записей в списке осциллограмм тока

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// стартовые координаты верхнего/левого угла сетки
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define INTERRUPT_CHART_GRID_X_START    5 
#define INTERRUPT_CHART_GRID_Y_START    20

#define NUMBER_OF_BUFFERS 6                     // Установить количество буферов
//#define SAMPLING_RATE 210000                    // период таймера 3
#define NUM_CHANNELS 6                          // Установить количество аналоговых входов
#define ADC_BUFFER_SIZE 90*NUM_CHANNELS        // Определить размер буфера хранения измеряемого сигнала     
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// кол-во кадров в секунду для отображения синусоид
#define CHART_FPS                                     30
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки порогов токового трансформатора по умолчанию
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define HIGH_DEFAULT_BORDER               3500 // верхний порог
#define LOW_DEFAULT_BORDER                2500 // нижний порог
#define Threshold_LEVEL                    100 // уровень порога по умолчанию

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// пересчет напряжения в ток
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define COEFF_1                    5.0 // первый коэффициент по пересчёту тока
#define CURRENT_NUM_SAMPLES         10 // за сколько измерений вычислять ток для главного экрана
#define CURRENT_MIN_TREAT_AS_ZERO  100 // минимальное значение тока, которое интерпретируется как 0
#define  CURRENT_DIVIDER          1000 // делитель для пересчёта напряжения в ток


////--------------------------------------------------------------------------------------------------------------------------------
//// настройки EEPROM (МИНИМАЛЬНЫЙ ОБЪЁМ EEPROM - 16 Кб !!!)
////--------------------------------------------------------------------------------------------------------------------------------
///*
//ПОДДЕРЖИВАЕМЫЕ ТИПЫ ПАМЯТИ:
//
//  EEPROM_BUILTIN // встроенный EEPROM
//  EEPROM_AT24C32 // I2C-память AT24C32
//  EEPROM_AT24C64 // I2C-память AT24C64
//  EEPROM_AT24C128 // I2C-память AT24C128 - МИНИМАЛЬНЫЙ НЕОБХОДИМЫЙ ОБЪЁМ !!!
//  EEPROM_AT24C256 // I2C-память AT24C256
//  EEPROM_AT24C512 // I2C-память AT24C512
//*/
//#define EEPROM_USED_MEMORY EEPROM_AT24C128 // используем внешнюю память I2C AT24C128
//// если используется внешнняя память AT24C* - то ниже определяется индекс микросхемы. Например, китайский модуль часов реального времени
//// с DS3231 на борту имеет модуль памяти с адресом на шине I2C 0x57, т.е. индекс такого модуля - 7, т.к. базовый адрес памяти на шине - 
//// 0x50. Настройкой ниже можно указать адрес микросхемы памяти на шине I2C.
//#define EEPROM_MEMORY_INDEX 0



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// адреса хранения в EEPROM
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define ControllerID_ADDRESS                     10 // адрес хранения 
#define TimeLedLCD_ADDRESS                      110 // адрес хранения 
#define TimePowerOff_ADDRESS                    120 // адрес хранения  
#define TftCalibrationData_ADDRESS              140 // адрес хранения  
#define Threshold1_ADDRESS                      150 // адрес хранения  
#define Threshold2_ADDRESS                      160 // адрес хранения  
#define Threshold3_ADDRESS                      170 // адрес хранения  
#define RSSI_LOW_BORDER_STORE_ADDRESS           180 // адрес хранения нижнего порога токового трансформатора (6 байт)
#define RSSI_HIGH_BORDER_STORE_ADDRESS          190 // адрес хранения верхнего порога токового трансформатора (6 байт)
#define CURRENT_COEFF_STORE_ADDRESS             220 // адрес хранения настройки коэффициента  (6 байт)
//--------------------------------------------------------------------------------------------------------------------------------
// Настройки значений по умолчанию
//--------------------------------------------------------------------------------------------------------------------------------

#define MAX_TIME_LCD_LENGTH           4 // максимальная длина вводимого времени отключения подсветки дисплея
#define MAX_TIME_POWER_LENGTH         4 // максимальная длина вводимого времени отключения прибора
#define DEFAULT_ControllerID          1 // 


//--------------------------------------------------------------------------------------------------------------------------------
// Настройки текста
//--------------------------------------------------------------------------------------------------------------------------------
#define WM_BACK_CAPTION "< НАЗАД"
#define MENU_CAPTION "СЕРВИСНОЕ МЕНЮ"
#define CAL_TIME_LCD_OFF "ОТКЛЮЧЕНИЕ LCD"
#define CAL_TIME_POWER_OFF "OTKЛ. ПРИБОРА"
#define ENTER_CAPTION "ВВОД"
#define SET_FREE "СВОБОДЕН"
#define SET_CONTROLLER_ID "CONTROLLER ID"


//--------------------------------------------------------------------------------------------------------------------------------
// экраны
//--------------------------------------------------------------------------------------------------------------------------------
#define USE_TFT_MODULE // закомментировать, если не нужна поддержка TFT


//--------------------------------------------------------------------------------------------------------------------------------
// настройки TFT (используется экран с разрешением 320x240)
//--------------------------------------------------------------------------------------------------------------------------------
// цвета для TFT
// цвета для кнопок: цвет текста, не выяснил ,цвет рамки не нажат, цвет рамки при нажатии ,цвет заполнения
//--------------------------------------------------------------------------------------------------------------------------------
#define TFT_BACK_COLOR TFT_BLACK /*TFT_WHITE*/                // цвет фона
#define TFT_BUTTON_COLORS TFT_WHITE, 0x8410, WHITE, 0xF800, 0x001F
#define TFT_BUTTON_COLORS_BLUE TFT_WHITE, TFT_GREEN, TFT_WHITE, TFT_RED, TFT_BLUE

#define TFT_FONT_COLOR 0x4A69                   // цвет шрифта по умолчанию
#define TFT_CHANNELS_BUTTON_COLORS 0x3A8D, 0xC618, 0x8410, 0xF800, 0xEF7D // цвета кнопок для каналов
#define INFO_BOX_BACK_COLOR 0x6161              // цвет фона для информационного бокса
#define INFO_BOX_BORDER_COLOR TFT_BLACK         // цвет рамки информационного бокса
#define INFO_BOX_CAPTION_COLOR 0x33D6           // цвет заголовка информационного бокса
#define SENSOR_BOX_FONT_COLOR TFT_WHITE         // цвет показаний датчика
#define SENSOR_BOX_UNIT_COLOR TFT_WHITE         // цвет единиц изменений датчика
#define MODE_ON_COLOR 0x0400                    // цвет "вкл", "авто"
#define MODE_OFF_COLOR 0x8000                   // цвет "выкл", "ручной"
#define CHANNELS_BUTTONS_TEXT_COLOR TFT_WHITE   // цвет текста кнопок каналов
#define CHANNELS_BUTTONS_BG_COLOR 0xEF7D        // цвет фона кнопок каналов
#define CHANNEL_BUTTONS_TEXT_COLOR 0x3A8D       // цвет текста кнопки одного канала
#define TIME_PART_FONT_COLOR 0x0410             // цвет текста кнопки установки компонента времени
#define TIME_PART_SELECTED_FONT_COLOR TFT_WHITE // цвет текста активной кнопки компонента времени
#define TIME_PART_BG_COLOR 0xEF7D               // цвет фона кнопки компонента времени
#define TIME_PART_SELECTED_BG_COLOR 0x0400      // цвет фона выбранной кнопки компонента времени
#define STATUS_ON_COLOR 0x07E0                  // цвет статусов на экране ожидания
//--------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef _DEBUG
#define DBG(s) { Serial1.print((s)); }
#define DBGLN(s) { Serial1.print((s)); Serial1.println(); }
#else
#define DBG(s) (void) 0
#define DBGLN(s) (void) 0
#endif
#define ENDL '\n'
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//template <typename T> inline Stream& operator << (Stream& s, T n) { s.print(n); return s; }
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define CORE_COMMAND_GET F("GET=")             // префикс для команды получения данных из модуля LCD
#define CORE_COMMAND_SET F("SET=")             // префикс для команды сохранения данных в модуль LCD
#define CORE_COMMAND_ANSWER_OK F("OK ")       // какой префикс будет посылаться в ответ на команду получения данных и её успешной отработке
#define CORE_COMMAND_ANSWER_ERROR F("ERR ")   // какой префикс будет посылаться в ответ на команду получения данных и её неуспешной отработке
#define CORE_COMMAND_PARAM_DELIMITER '#'      // разделитель параметров
#define CORE_END_OF_DATA F("[END]")
#define CORE_COMMAND_DONE F("DONE")

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
