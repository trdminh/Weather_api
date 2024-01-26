#ifndef __WIFI_SCAN__
#define __WIFI_SCAN__

#include <WiFi.h>
#include <WiFiUdp.h>
#include <Arduino.h>

extern const char *ssid;
extern const char *password;


void Scan_wifi();
void Connect_wifi();




#endif