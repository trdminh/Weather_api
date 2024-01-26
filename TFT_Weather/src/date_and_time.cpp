#include <date_and_time.h>


const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 25200;
const int   daylightOffset_sec = 3600;


void Time_setup(){
    Serial.begin(9600); 
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    //Print_local_time();
}

void Print_local_time(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  char timeHour[3];
  strftime(timeHour,3, "%H", &timeinfo);
  String hour = timeHour; 
  Serial.println(hour);
  
}
