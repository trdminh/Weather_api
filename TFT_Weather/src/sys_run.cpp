#include <sys_run.h>


void init(){
    Time_setup();
    Dht_setup();
    
    WiFi.mode(WIFI_STA);  
    Scan_wifi();
}


void run(){
    Print_local_time();
}