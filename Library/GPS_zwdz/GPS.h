//
// Created by Wjm on 2021/1/27.
//

#ifndef SECOND_GPS_H
#define SECOND_GPS_H

#include "usart.h"
#include "string.h"
#include "../stdlog/stdlog.h"
#include "gpio.h"


typedef struct
{
    uint32_t latitude_bd;					//纬度   分扩大100000倍，实际要除以100000
    uint8_t nshemi_bd;						//北纬/南纬,N:北纬;S:南纬
    uint32_t longitude_bd;			  //经度 分扩大100000倍,实际要除以100000
    uint8_t ewhemi_bd;						//东经/西经,E:东经;W:西经
} gps_msg;

/* E53_ST1传感器数据类型定义 ------------------------------------------------------------*/
typedef struct
{
    float    Longitude;				//经度
    float    Latitude;        //纬度
} E53_ST1_Data_TypeDef;

//外部调用获取数据
E53_ST1_Data_TypeDef getData();
//函数功能：从buf里面得到第cx个逗号所在的位置
uint8_t NMEA_Comma_Pos(uint8_t *buf,uint8_t cx);
//：返回m的n次方值
uint32_t NMEA_Pow(uint8_t m,uint8_t n);
//函数功能：str数字转换为（int）数字，以','或者'*'结束
int NMEA_Str2num(uint8_t *buf,uint8_t*dx);
//函数功能：解析GNRMC信息
void NMEA_BDS_GPRMC_Analysis(gps_msg *gpsmsg,uint8_t *buf);
//存储数据
void E53_ST1_Read_Data(void);
//main外初始化GPS
void GPSinit();

#endif //SECOND_GPS_H
