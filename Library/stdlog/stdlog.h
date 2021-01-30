//
// Created by MCqie on 2021/1/9.
//
#ifndef SERIALTEST_STDLOG_H
#define SERIALTEST_STDLOG_H
//printf重定向
#include "main.h"
#include "stdio.h"
#include "stdarg.h"
int __io_putchar(int ch);
int fputc(int ch, FILE *f);
enum LOG_TYPE;
void print(char* str,...);
void println(char* str,...);

void DebugON();
void DebugOFF();

void printperfix(enum LOG_TYPE type);


void log_inf(char* str,...);
void log_err(char* str,...);
void log_wrn(char* str,...);

void log_debug(char* str,...);

void initLogger(UART_HandleTypeDef *uart);

#endif //SERIALTEST_STDLOG_H
