//
// Created by Wjm on 2021/1/26.
//
/*******************************************************************************
 * 使用前需要进行引脚定义
 * 改变宏定义即可
 *
 *
 * *******************************************/

#ifndef SECOND_HW_KEY_H
#define SECOND_HW_KEY_H
#include "main.h"
#include "stm32f1xx_hal.h"
#include <string.h>


#include "../stdlog/stdlog.h"
//scan
//行检测
char KEY_SCAN(void);
//定位
char KEY_ROW_SCAN(void);
//测试专用
void HW_KEY_FUNCTION(void);
//按键判断
void USE_key(int i,void (*fun)());


#define HW_GPIO GPIOC

#define HW_RW0 KEY_row0_Pin
#define HW_RW1 KEY_row1_Pin
#define HW_RW2 KEY_row2_Pin
#define HW_RW3 KEY_row3_Pin


#define KEY_CLO0_OUT_LOW  HAL_GPIO_WritePin(HW_GPIO,GPIO_PIN_0,GPIO_PIN_RESET)
#define KEY_CLO1_OUT_LOW  HAL_GPIO_WritePin(HW_GPIO,GPIO_PIN_1,GPIO_PIN_RESET)
#define KEY_CLO2_OUT_LOW  HAL_GPIO_WritePin(HW_GPIO,GPIO_PIN_2,GPIO_PIN_RESET)
#define KEY_CLO3_OUT_LOW  HAL_GPIO_WritePin(HW_GPIO,GPIO_PIN_3,GPIO_PIN_RESET)

#define KEY_CLO0_OUT_HIGH  HAL_GPIO_WritePin(HW_GPIO,GPIO_PIN_0,GPIO_PIN_SET)
#define KEY_CLO1_OUT_HIGH  HAL_GPIO_WritePin(HW_GPIO,GPIO_PIN_1,GPIO_PIN_SET)
#define KEY_CLO2_OUT_HIGH  HAL_GPIO_WritePin(HW_GPIO,GPIO_PIN_2,GPIO_PIN_SET)
#define KEY_CLO3_OUT_HIGH  HAL_GPIO_WritePin(HW_GPIO,GPIO_PIN_3,GPIO_PIN_SET)




#endif //SECOND_HW_KEY_H
