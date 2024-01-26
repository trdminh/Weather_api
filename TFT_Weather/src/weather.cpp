#include <weather.h>

String Apikey = "4d7bc52458715c7ef7e26a5a81b7036a";
String city = "Hanoi";
String countryCode = "VN";
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;
String jsonBuffer;
DHT dht(DHTPIN, DHTTYPE);



String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  
  http.begin(client, serverName);
  

  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    //Serial.print("HTTP Response code: ");
    //Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  
  http.end();

  return payload;
}

JSONVar Data_weather_forecast(){
  JSONVar my_object;
  if(WiFi.status()== WL_CONNECTED){
            //String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + Apikey;
      String serverPath = "http://api.openweathermap.org/data/2.5/forecast?q=" + city +"," + countryCode + "&cnt=7&APPID="+Apikey;
            
      
      jsonBuffer = httpGETRequest(serverPath.c_str());
            //Serial.println(jsonBuffer);
      my_object = JSON.parse(jsonBuffer);
            

      if (JSON.typeof(my_object) == "undefined") {
        Serial.println("Parsing input failed!");
        return 0;
      }
      return my_object;
  }
  else{
    return 0;
  }
  
}


void Dht_setup(){
  dht.begin();
}

int Current_temp(){

  int temp     = dht.readTemperature();
  return temp;
}

int Current_humi(){
  int humi = dht.readHumidity();
  return humi;
}
