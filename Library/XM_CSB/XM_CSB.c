//
// Created by Wjm on 2021/5/31.
//

#include "XM_CSB.h"
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
    if(htim->Instance == XM_CSB_TIM_2)
    {
        if(CapIndex == 0)
        {
            CapIndex = 1;
            __HAL_TIM_SET_COUNTER(htim,0);//设置定时器3计数值为0
            //清除原来的捕获极性
            TIM_RESET_CAPTUREPOLARITY(htim,XM_CSB_TIM_CHANNEL);
            //定时器2通道1设置为下降沿捕获
            TIM_SET_CAPTUREPOLARITY(htim,XM_CSB_TIM_CHANNEL,TIM_ICPOLARITY_FALLING);

        }
        else
        {
            HAL_TIM_IC_Stop_IT(htim,XM_CSB_TIM_CHANNEL);//关闭TIM2_CH1输入捕获
            CapVal = __HAL_TIM_GET_COMPARE(htim,XM_CSB_TIM_CHANNEL);
            CapValReady = 1;
            //清除原来的捕获极性
            TIM_RESET_CAPTUREPOLARITY(htim,XM_CSB_TIM_CHANNEL);
            //定时器2通道1设置为上升沿捕获
            TIM_SET_CAPTUREPOLARITY(htim,XM_CSB_TIM_CHANNEL,TIM_ICPOLARITY_RISING);
            CapIndex = 0;
        }

    }
}

void RCCdelay_us(uint32_t udelay){
    __IO uint32_t Delay = udelay * 32 / 8;//(SystemCoreClock / 8U / 1000000U)
    do
    {
        __NOP();
    }
    while (Delay --);
}

void USTrig()
{
    HAL_GPIO_WritePin(TRIG_GPIO_Port,TRIG_Pin,GPIO_PIN_SET);
    RCCdelay_us(50);
    HAL_GPIO_WritePin(TRIG_GPIO_Port,TRIG_Pin,GPIO_PIN_RESET);
}

float Getdata(){
    if(CapValReady == 1)
    {
        //log_inf("%d",CapVal);
        //25.5cm-350cm
        USData = CapVal * 34000.0/1000000/2;//声速34000cm/s TIM3Freq：1000000Hz
        if(USData <= 350 && USData >= 1)
        {
           // log_inf("US:%.2fcm\r\n",USData);
        }
        __HAL_TIM_DISABLE(&XM_CSB_TIM);
        HAL_Delay(100);
        __HAL_TIM_SET_COUNTER(&XM_CSB_TIM,0);//设置定时器3计数值为0
        __HAL_TIM_ENABLE(&XM_CSB_TIM);
        CapValReady = 0;
        USTrig();
        HAL_TIM_IC_Start_IT(&XM_CSB_TIM,XM_CSB_TIM_CHANNEL);//定时器3通道2输入捕获使能   需需修改
    }

    return USData;
}