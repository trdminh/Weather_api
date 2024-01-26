#ifndef  __WEATHER__
#define  __WEATHER__

#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <wifi_scan.h>
#include <DHT.h>

#define DHTPIN 26
#define DHTTYPE DHT11
extern String         Apikey;
extern String         city;
extern String         countryCode;
extern unsigned long  lastTime;
extern unsigned long  timerDelay;
extern String         jsonBuffer;



 
JSONVar    Data_weather_forecast();
String     httpGETRequest(const char* serverName);
void       Dht_setup();
int        Current_temp();
int        Current_humi();

#endif