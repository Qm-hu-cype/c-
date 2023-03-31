#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<graphics.h>//����ͼ�ο�
#include<time.h>
#include "tools.h"
#include<mmsystem.h>//��������
#pragma comment(lib,"winmm.lib")

IMAGE imgBg;//����һ��ͼƬ����,������ʾ����

int offx = 55;//�󲿱߾�
int offy = 321;//�����߾�  

/*//��ť�ĳ�ʼ��
void initButton(Button* btn, const char* normalFile, const char* pressFile, int width, int height,
	int flag)
{
	//loadimage(&btn->imgNormal,normalFile,width,height,true);
	//loadimage(&btn->imgPress,pressFile,width,height,true);
	btn->width = width;
	btn->height = height;
	btn->pressed = false;
	btn->flag = flag;
}*/
/*/
void buttonsInit()
{
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++)
		{
			int k = i * 3 + j;
			if (k == 8) return;

			//��k����ť���г�ʼ��
			char name1[64], name2[64];
			sprintf(name1, "res/sz%d.png", k + 1);
			sprintf(name1, "res/sz%dp.png", k + 1);
			initButton(btns[k], name1, name2, 106, 106, k + 1);//��ť��߾�Ϊ106
			//��ť����
			btns[k].x = offx + j * (106 + 1);
			btns[k].y = offy + i * (106 + 1);

		}
	}
}*/


void drawButton(Button* btn)
{
	if (!btn) {
		return;
	}
	if (btn->pressed) {
		drawPNG(btn->x, btn->y, &btn->imgPress);
	}
	else {
		drawPNG(btn->x, btn->y, &btn->imgNormal);
	}
}



//������ť����
struct Button
{
	IMAGE imgNormal;//��ť����ͨ״̬�µĵ�ͼƬ
	IMAGE imgPress;//����ȥ��״̬
	int width, height;//���
	int x, y;//��ť����
	int flag;//��ť���
	bool pressed;//��ʾ��ǰ�Ƿ񱻰���
};

 struct Button btns[8];//��ť
 int data[3][3];
//��ť�ĳ�ʼ��
void initButton(Button* btn, const char* normalFile, const char* pressFile, int width, int height,
	int flag){

	loadimage(&btn->imgNormal, normalFile, width, height, true);
	loadimage(&btn->imgPress, pressFile, width, height, true);
	btn->width = width;
	btn->height = height;
	btn->pressed = false;
	btn->flag = flag;
}

void buttonsInit()
{
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++)
		{
			int k = i * 3 + j;
			data[i][j] = k + 1;
			if (k == 8)
				data[2][2] = 0;
				return;

			//��k����ť���г�ʼ��
			char name1[64], name2[64];//�ļ���
			sprintf_s(name1, "res/sz%d.png", k + 1);
			sprintf_s(name1, "res/sz%dp.png", k + 1);
			initButton(&btns[k], name1, name2, 106, 106, k + 1);//��ť��߾�Ϊ106
			//��ť����
			btns[k].x = offx + j * (106 + 1);
			btns[k].y = offy + i * (106 + 1);

		}
	}
	//to do,,,�������ݽṹ
}void drawButton(Button* btn) {
	if (!btn) return;
	if (btn->pressed) {
		drawPNG(btn->x, btn -> y, &btn->imgPress);
	}
	else
	{
		drawPNG(btn->x, btn->y, &btn->imgNormal);
	}
}
//���ָ����ť,�Ƿ�ѡ��
bool checkButtonSelect(Button *btn,MOUSEMSG *msg) {
	//  ��ť��Χ
	if (msg->x >= btn->x + btn->width * 0.1
		&& msg->x <= btn->x + btn->width * 0.9
		&& msg->y >= btn->y + btn->height * 0.1
		&& msg->y <= btn->y + btn->height * 0.9) {
		return true;
	}
	else
		return false;
	
	
}
//�ж��ܷ��ƶ�
bool canMove(int sz, int* y, int* x) {
	int flag = 0,i,j;
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			if (data[i][j] == sz) {
				flag = 1;break;
			}
		}if (flag)break;
	}
	if (i > 0 && data[i - 1][j] == 0) {
		*x = 0;
		*y = -1;
		data[i][j] = 0;
		return true;
	}
	if (i < 2 && data[i + 1][j] == 0) {
		*x = 1;
		*y = 0;
		data[i + 1][j] = sz;
		data[i][j] = 0;
		return true;
	}
	if (j > 0 && data[i][j - 1] == 0) {
		*x = -1;
		*y = 0;
		data[i][j - 1] = sz;
		data[i][j] = 0;
		return true;
		}
	if (j < 2 && data[i][j - 1] == 0) {
		*x = 1;
		*y = 0;
		data[i][j + 1] = sz;
		data[i][j] = 0;
		return true;
	}return false;
}void update();
void moveBotton(Button* button) {
	int x, y;
	if (canMove(button->flag,&x,&y)) {
		button->x += x * (106 + 1);
		button->y += y * (106 + 1);
		mciSendString("play res/move3.mp3", 0, 0, 0);
		update();
	}
}
void  Gameinit() {
	//������Ϸ����
	initgraph(1080 * 0.4, 2400 * 0.4);
	//�ѱ���ͼƬ���ص�������
	loadimage(&imgBg, _T("res/bg1.png"), 1080 * 0.4, 2400 * 0.4, true);
	//��ʼ����ť
	buttonsInit();
}



//������Ϸ����
void update()
{
	putimage(0, 0, &imgBg);//������(0,0)λ����ʾ֮ǰ�Ļ�ͼ���
	for (int i = 0;i < 8;i++) {
		drawButton(&btns[i]);
	}
}

 Button* checkButtonClick(MOUSEMSG msg) {
	 for (int i = 0;i < 8;i++) {
		 if (checkButtonSelect(&btns[i], &msg)) {
			 btns[i].pressed = true;
			 return &btns[i];
		 }
	 }return 0;
}
int main(void)
{
	Gameinit();// init��ʼ�� grapͼ�δ���
	//������Ϸ����
	update();
	Button* btn = NULL;
	//BeginBatchDraw();//������ͼ�����������Ļ��
	 //������Ϸ����

	//EndBatchDraw();//ֱ��EndBatchDraw()�Ž�֮ǰ�Ļ�ͼ���


	while (1)
	{
		//��ȡ�����Ϣ
		MOUSEMSG m = GetMouseMsg();
		//����������,̧��ʼ�ƶ�
		switch(m.uMsg)//�ж����״̬
		{
		case  WM_LBUTTONDOWN://����
		//�������½���ѡ��
		//�����Ǹ����������
			btn=checkButtonClick(m);
			break;
		case  WM_LBUTTONUP://̧��
			if (btn) {
				btn->pressed = false;
				moveButton(btn);
			}
			break;

		}
	}
	drawButton(btn);
	//�ж���Ϸ�Ƿ�ɹ�
	system("pause");//������Ļ
	closegraph();//�ر�ͼ�δ���
	return 0;
}