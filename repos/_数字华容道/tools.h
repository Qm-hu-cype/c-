#pragma once

#include<stdio.h>
#include<graphics.h>//����ͼ�ο�
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
	int flag;//��ť���
	bool pressed;
};
//xΪ����ͼƬ��X���꣬yΪY����
void drawPNG(int  picture_x, int picture_y, IMAGE* picture);
//��Ⱦ��ť

void moveButton(Button* btn);
void drawButton(Button* btn);
void update();

void checkSuccess();
void init();
