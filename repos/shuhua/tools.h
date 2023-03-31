#pragma once

#include<stdio.h>
#include<graphics.h>//引入图形库
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tools.h"
#include <conio.h>


struct button {

	IMAGE imgNormal;//未按下按钮的状态
	IMAGE imgPress;//按下去的状态
	int width;//宽
	int height;//高
	int flag;//附加成员,用来显示其他信息:按钮对应数字
	int pressed;//当前是否被按下
	int row, col;//当前按钮在第几行,第几列
};
//x为载入图片的X坐标，y为Y坐标
void drawPNG(int  picture_x, int picture_y, IMAGE* picture);
//渲染按钮
void drawButton(struct button* btn);
void update();
void initAllButtons();
void init();
bool checkButtonSelect(struct button* btn, ExMessage* msg);
void userClick();
