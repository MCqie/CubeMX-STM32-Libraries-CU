//
// Created by MCqie on 2021/1/17.
//

#ifndef U8G2DEMO_OLEDFX_H
#define U8G2DEMO_OLEDFX_H
#include "oled.h"
#include "string.h"
//util
void OLEDFX_squFill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void OLEDFX_squToggle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
//label 标签
struct label{
    uint8_t x0;
    uint8_t y0;
    uint8_t* str;
    uint8_t size;
    int id;
};
void OLEDFX_Draw_label(struct label label);

//Scene  Scene_UI更新
struct Scene{
    void (*Init)();
    void (*UI)();
    void (*logic)();
};
void OLEDFX_SceneInit(struct Scene scene);
void OLEDFX_SceneUpdate(struct Scene scene);
void OLEDFX_SceneRun(struct Scene scene);

//button
struct Button{
    uint8_t x0;
    uint8_t y0;
    uint8_t x1;
    uint8_t y1;
    uint8_t* str;
    uint8_t size;
    char select;
    int id;
} ;
void OLEDFX_Draw_Button(struct Button btn);
void OLEDFX_Button_ToggleSelect(struct Button* btn);
void OLEDFX_Button_Click(struct Button* btn);
//EVENT
void OLEDFX_Button_ClickEvent(struct Button* btn) __attribute__((weak));


//progressBar
struct ProgressBar{
    uint8_t x0;
    uint8_t y0;
    uint8_t x1;
    uint8_t y1;
    int MAXValue;
    int MinValue;
    int NowVlaue;
    char printMode; //1为覆盖 0为取反
    int id;
    char IT;
};
void OLEDFX_Draw_ProgressBar(struct ProgressBar prog);
//EVENT
void OLEDFX_Progress_MAXValueEvent(struct ProgressBar* prog) __attribute__((weak));
#endif //U8G2DEMO_OLEDFX_H


//Selector
struct Selector{
    uint8_t x0;
    uint8_t y0;
    uint8_t x1;
    uint8_t y1;
    char select;
    uint8_t* (*getValue)(int index);
    uint8_t size;
    int index;
    int maxindex;
    int id;
};
void OLEDFX_Draw_Selector(struct Selector sel);
void OLEDFX_Selector_NextUnit(struct Selector *sel);
void OLEDFX_Selector_BeforeUnit(struct Selector *sel);