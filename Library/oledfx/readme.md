
#OledFX

---

类型: 驱动

描述: 驱动OLED屏幕

依赖: 硬件spi(STM32)

---

##详情：
##适用外设(仅驱动填写)

---
Oled_12864_SSD1306_SPI

## CUBEMX配置

---
spi --- Trans only master 

>GPIO:
>>OLED_RES  
>
> >OLED_DC
>
>>OLED_CS
>
> 皆为高速 输出
 
详情可参考 Demo.ioc

##使用说明

---

本驱动分为2部分：

    oled.h     ---OELD显示驱动

    oledFX.h   ---OLED界面库


OledFX初始化
```c
    OLED_Init();
    OLED_ColorTurn(0);
    OLED_DisplayTurn(0);
    OLED_Refresh();
```

###oled.h常用

画图型
~~~
void OLED_DrawPoint(uint8_t x,uint8_t y);

void OLED_DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2);

void OLED_DrawSquare(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2);

void OLED_DrawCircle(uint8_t x,uint8_t y,uint8_t r);
~~~
显示文字/图像
~~~

void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size1);

void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t size1);

void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size1);

void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t num,uint8_t size1);

void OLED_ShowPicture(uint8_t x0,uint8_t y0,uint8_t x1,uint8_t y1,uint8_t BMP[]);

void OLED_Printf(uint8_t str[]);
~~~

显示
~~~

void OLED_Refresh(void);

void OLED_Clear(void);

void OLED_BuffClear(void);  //清空缓存
~~~

###oledfx.h常用
~~~

OLEDFX以组件的形式存在

组件：

lable

button

progressBar

selector

创建结构体后 既可使用 OELDFX_Draw_xXX在屏幕上显示

OLEDFX_xxx_xxx操作特定的组件

组件会存在一个属性 id 建议不要重复（会在回调函数中使用）

~~~

Scene是一个特殊的组件
~~~
需要init Ui 和 logic函数

init是初始化代码 可以通过

void OLEDFX_SceneInit(struct Scene scene);

调用

ui是ui更新代码 将所有的UI更新代码输入进去

logic是逻辑函数 将UI运行时候所需要的逻辑写入

scene的run函数只是更新一次界面 请将run放入循环语句 以保证界面的连续性

~~~

详情请参考 OledFX.h 和 oled.c

##注意事项

---

Lable组件不建议使用
