//
// Created by MCqie on 2021/1/26.
//
#include "stdlog.h"
UART_HandleTypeDef *huarts;
char debugMode=0;
char* LogVersion="0.3.2 Alpha";
char* LogVersionName="Owl";
int __io_putchar(int ch){
    HAL_UART_Transmit(huarts, (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}
int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(huarts, (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}
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

void initLogger(UART_HandleTypeDef *uart){
    huarts=uart;
    printf("Serial Controled By:");
    printf("\n"
           "███╗   ███╗ ██████╗ ██████╗ ██╗███████╗\n"
           "████╗ ████║██╔════╝██╔═══██╗██║██╔════╝\n"
           "██╔████╔██║██║     ██║   ██║██║█████╗  \n"
           "██║╚██╔╝██║██║     ██║▄▄ ██║██║██╔══╝  \n"
           "██║ ╚═╝ ██║╚██████╗╚██████╔╝██║███████╗\n"
           "╚═╝     ╚═╝ ╚═════╝ ╚══▀▀═╝ ╚═╝╚══════╝\n"
           "                                       \n");
    println("Ver.%s[%s]",LogVersion,LogVersionName);
    println("Appearances often are deceiving.\n"
            "                          ——Aesop, Fables");
    println("Logger初始化成功！");
}

