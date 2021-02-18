//
// Created by MCqie on 2021/1/26.
//
#include "stdlog.h"
UART_HandleTypeDef *huarts;char debugMode=0;

enum LOG_TYPE{
    LOGINFO,LOGERROR,LOGWARNING,LOGDEBUG
};
void print(char* str,...) {
    va_list args;
    va_start(args, str);
    vprintf(str,args);
    va_end(args);
}
void println(char* str,...) {
    va_list args;
    va_start(args, str);
    vprintf(str,args);
    va_end(args);
    printf("\r\n");
}

void DebugON(){
    debugMode=1;
}
void DebugOFF(){
    debugMode=0;
}



void printperfix(enum LOG_TYPE type){
    if(type==LOGINFO){
        print("[Info]");
    }
    if(type==ERROR){
        print("[Error]");
    }
    if(type==LOGWARNING){
        print("[Warning]");
    }
    if(type==LOGDEBUG){
        print("[Debug]");
    }
}


void log_inf(char* str,...){
    printperfix(LOGINFO);
    va_list args;
    va_start(args, str);
    vprintf(str,args);
    va_end(args);
    println("");
}
void log_err(char* str,...){
    printperfix(LOGERROR);
    va_list args;
    va_start(args, str);
    vprintf(str,args);
    va_end(args);
    println("");
}
void log_wrn(char* str,...){
    printperfix(LOGWARNING);
    va_list args;
    va_start(args, str);
    vprintf(str,args);
    va_end(args);
    println("");
}

void log_debug(char* str,...){
    printperfix(LOGDEBUG);
    va_list args;
    va_start(args, str);
    vprintf(str,args);
    va_end(args);
    println("");
}



