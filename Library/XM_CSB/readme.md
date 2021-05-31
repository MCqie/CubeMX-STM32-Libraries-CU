#XM_CSB

---

类型: 库

描述: 一个超声波的使用

依赖: 

---

##详情：
##适用外设(仅驱动填写)

---



## CUBEMX配置

---
TIM3 clock source : internal clock  
TIM3 channel2: Input Capture direct mode
详细看.ioc
##使用说明

---

 void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

 void RCCdelay_us(uint32_t udelay); 

 void USTrig(); 

 float Getdata();   //获取数据

