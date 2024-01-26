#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>
#include <sys_run.h>



//#include "Fonts/DSEG7_Classic_Mini_Bold_30.h"
//#include "Fonts/DSEG7_Classic_Mini_Bold_22.h"



#define _cs   15   // 3 goes to TFT CS
#define _dc   2   // 4 goes to TFT DC
#define _mosi 23  // 5 goes to TFT MOSI
#define _sclk 18  // 6 goes to TFT SCK/CLK
#define _rst  4  // ESP RST to TFT RESET
#define _miso 19   // Not connected




void setup()
{
    Connect_wifi();
    Time_setup();
}

void loop(){
  delay(1000);
  //Print_local_time();
  //Current_Weather();
  //JSONVar object = Data_weather_forecast();
  //Serial.println(object);
  run();
}








