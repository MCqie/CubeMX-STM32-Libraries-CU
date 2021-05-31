//
// Created by Wjm on 2021/5/31.
//

#ifndef CUBEMX_STM32_LIBRARIES_CU_XM_CSB_H
#define CUBEMX_STM32_LIBRARIES_CU_XM_CSB_H

#define XM_CSB_TIM htim3 //用啥改啥
#define XM_CSB_TIM_2 TIM3
#define XM_CSB_TIM_CHANNEL TIM_CHANNEL_2 //用啥改啥

uint8_t CapIndex = 0;
uint8_t CapValReady = 1;
float USData = 0;         //这个是我们用的值   //25.5cm-350cm
uint16_t CapVal = 0;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
//void XM_CSB_Callback(TIM_HandleTypeDef *htim);

void RCCdelay_us(uint32_t udelay);

void USTrig();

float Getdata();

#endif //CUBEMX_STM32_LIBRARIES_CU_XM_CSB_H
