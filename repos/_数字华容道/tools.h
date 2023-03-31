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

struct Button {
	IMAGE imgNormal;
	IMAGE imgPress;
	int width, hight;
	int x, y;
	int flag;//按钮标记
	bool pressed;
};
//x为载入图片的X坐标，y为Y坐标
void drawPNG(int  picture_x, int picture_y, IMAGE* picture);
//渲染按钮

void moveButton(Button* btn);
void drawButton(Button* btn);
void update();

void checkSuccess();
void init();
