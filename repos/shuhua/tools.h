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


struct button {

	IMAGE imgNormal;//δ���°�ť��״̬
	IMAGE imgPress;//����ȥ��״̬
	int width;//��
	int height;//��
	int flag;//���ӳ�Ա,������ʾ������Ϣ:��ť��Ӧ����
	int pressed;//��ǰ�Ƿ񱻰���
	int row, col;//��ǰ��ť�ڵڼ���,�ڼ���
};
//xΪ����ͼƬ��X���꣬yΪY����
void drawPNG(int  picture_x, int picture_y, IMAGE* picture);
//��Ⱦ��ť
void drawButton(struct button* btn);
void update();
void initAllButtons();
void init();
bool checkButtonSelect(struct button* btn, ExMessage* msg);
void userClick();
