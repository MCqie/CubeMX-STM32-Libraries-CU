//
// Created by Wjm on 2021/1/30.
//

#include "esp8266.h"


void esp8266_link(char *name,char* password){
    println("AT+CWJAP=\"%s\",\"%s\"",name,password);
    HAL_Delay(8000);
}


void esp8266_trsport() {

    println("AT+CWMODE=1");
    HAL_Delay(500);
    println("AT+CIPMODE=1");
    HAL_Delay(500);
    println("AT+CIPSTART=\"TCP\",\"223.247.210.191\",8888");
    HAL_Delay(3000);
    println("AT+CIPSEND");
}