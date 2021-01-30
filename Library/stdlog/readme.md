#stdlog

---

类型: 库

描述: 一个利用串口输出日志的库

依赖: Usart

---

##详情：
##适用外设(仅驱动填写)

---



## CUBEMX配置

---
1个Usart 使用 asynchronous模式

##使用说明

---

导入 stdlog.h

`#include "stdlog.h" `

初始化 

`initLogger(&huart1);`

此库实现

void print(char* str,...);  串口打印

void println(char* str,...); 打印并换行

void log_inf(char* str,...); 以log形式打印 info

void log_err(char* str,...); 以log形式打印 error

void log_wrn(char* str,...);以log形式打印 warning



##注意事项

---

使用本库的串口 不得作为通信串口

若作为通信串口 请适当修改本库