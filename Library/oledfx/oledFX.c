//
// Created by MCqie on 2021/1/17.
//
#include "oledFX.h"
//util
void OLEDFX_squFill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){
    uint8_t i,n;
    for(i=x1;i<x2+1;i++)
    {
        for(n=y1;n<y2+1;n++)
        {
            OLED_DrawPoint(i,n);
        }
    }
}


void OLEDFX_squToggle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){
    uint8_t i,n;
    for(i=x1;i<x2+1;i++)
    {
        for(n=y1;n<y2+1;n++)
        {
            OLED_TogglePoint(i,n);
        }
    }
}

//Scene  Scene_UI更新
void OLEDFX_SceneInit(struct Scene scene){
    scene.Init();
    OLED_Refresh();
}
void OLEDFX_SceneUpdate(struct Scene scene){
    OLED_BuffClear();
    scene.UI();
    OLED_Refresh();
}
void OLEDFX_SceneRun(struct Scene scene){
    scene.logic();
    OLEDFX_SceneUpdate(scene);
}

//button
void OLEDFX_Draw_Button(struct Button btn){
    if(btn.select==1) {
        OLED_DrawSquare(btn.x0, btn.y0, btn.x1, btn.y1);
        OLED_ShowString((btn.x0 + btn.x1) / 2 - strlen((btn.str)) * 3, (btn.y0 + btn.y1) / 2 - 8, btn.str, btn.size);
        OLEDFX_squToggle(btn.x0, btn.y0, btn.x1, btn.y1);
    }else{
        OLED_DrawSquare(btn.x0, btn.y0, btn.x1, btn.y1);
        OLED_ShowString((btn.x0 + btn.x1) / 2 - strlen((btn.str)) * 3, (btn.y0 + btn.y1) / 2 - 8, btn.str, btn.size);
    }
}
void OLEDFX_Button_ToggleSelect(struct Button* btn){
    if(btn->select==1){
        btn->select=0;
    }else{
        btn->select=1;
    }
}


//progressBar
void OLEDFX_Draw_ProgressBar(struct ProgressBar prog){
    int m=prog.MAXValue-prog.MinValue;
    int z=prog.NowVlaue-prog.MinValue;
    int sm=prog.x1-prog.x0;
    double zb=1.0*z/m;
    int x2=sm*zb;
    if(x2>=prog.x1){
        x2 = prog.x1;
        if(prog.IT==0) {
            prog.IT=1;
            OLEDFX_Progress_MAXValueEvent(&prog);
        }
    }else{
       prog.IT=0;
    }
    if(prog.printMode){
        OLEDFX_squFill(prog.x0,prog.y0,x2+prog.x0,prog.y1);
    }else {
        OLEDFX_squToggle(prog.x0,prog.y0,x2+prog.x0,prog.y1);
    }
    OLED_DrawSquare(prog.x0, prog.y0, prog.x1, prog.y1);
}

void OLEDFX_Draw_label(struct label label){
    OLED_ShowString(label.x0,label.y0,label.str,label.size);
}
void OLEDFX_Draw_Selector(struct Selector sel){
    if(sel.select==1) {
        OLED_DrawSquare(sel.x0, sel.y0, sel.x1, sel.y1);
        OLED_ShowString((sel.x0 + sel.x1) / 2 - strlen((sel.getValue(sel.index))) * 3, (sel.y0 + sel.y1) / 2 - 8,sel.getValue(sel.index), sel.size);
        OLED_ShowString(sel.x1,(sel.y0 + sel.y1) / 2 - 8,"+",16);
        OLEDFX_squToggle(sel.x0, sel.y0, sel.x1, sel.y1);
    }else{
        OLED_DrawSquare(sel.x0, sel.y0, sel.x1, sel.y1);
        OLED_ShowString((sel.x0 + sel.x1) / 2 - strlen((sel.getValue(sel.index))) * 3, (sel.y0 + sel.y1) / 2 - 8,sel.getValue(sel.index), sel.size);
        OLED_ShowString(sel.x1,(sel.y0 + sel.y1) / 2 - 8,"+",16);
    }
}
void OLEDFX_Selector_NextUnit(struct Selector *sel){
    if(sel->select==1) {
        if (sel->index < sel->maxindex) {
            sel->index++;
        } else {
            sel->index = 0;
        }
    }

}
void OLEDFX_Selector_BeforeUnit(struct Selector *sel){
    if(sel->select==1) {
        if (sel->index > 0) {
            sel->index--;
        } else {
            sel->index = sel->maxindex;
        }
    }
}
void OLEDFX_Button_Click(struct Button* btn) {
    OLEDFX_Button_ClickEvent(btn);
}

