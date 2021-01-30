#CubeMX—STM32-Libraries-CU

---

<B>本项目分为两类文件

1.硬件驱动

2.常用库

---

注意：在Library中的一些`驱动/库`可能会依赖其他`库`文件 此时 请将对应的 `库` 文件也一同复制

如果要引用其他项目的库文件 请在md文件中说明 并提供下载地址

---

下面我们将对于上述两种文件进行规范

本项目结构

>library
> 
> >xxx(driver/lib)
> >
> > > XXX.c<br>XXX.h<br>xxx.md
> 
> >xxx(driver/lib)
>> >...
> 
> ...
>
可以看到每一个 ``lib/driver``都包含了必要的.c和.h文件

---

#.c和.h文件必须要满足以下规范

##任何.c内用到的 宏定义 必须在.h中声明 而不是直接调用

在.c文件中(正确的写法)
```c
HAL_GPIO_ReadPin(HW_GPIO,HW_RW0);
```

在.h文件中
```c
#define HW_GPIO GPIOC
#define HW_RW0 KEY_row0_Pin
```

在.c文件中(错误的写法)
```c
HAL_GPIO_ReadPin(GPIOC,KEY_row0_Pin);
```

##每个库都应该有自己的md文件

md文件中应该包含了
 
`库/驱动` 的使用方法

`驱动` 的适用外设型号

`驱动` 外设连线方式 以及 CubeMX的配置

---
PS:
>原则上 每一个.c文件都要有.h文件来调用
> > 若库还未开发完全 请在md文件中标明
