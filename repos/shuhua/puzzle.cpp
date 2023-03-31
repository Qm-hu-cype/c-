#define _CRT_SECURE_NO_WARNINGS

#include"tools.h"
#include<mmsystem.h>//��������
#pragma comment(lib,"winmm.lib")

IMAGE imgBg;//����ͼƬ����,������ʾ����



struct button* btns[3][3];
bool win;

//��Ⱦ��ť
void drawButton(struct button* btn) {
	if (btn == NULL) 
		return;
	//��ť����λ��
	int x = 55 + btn->col * (106 + 1);
	int y = 321 + btn->row * (106 + 1);
	//���ư�ť(����״̬,�Ƿ񱻰���)
	if (btn->pressed) {
		//drawPNG(btn->row, btn->col, &btn->imgPress);
		putimage(x, y, &btn->imgPress);//δ���µ�״̬
	}
	else {
		//drawPNG(btn->row, btn->col, &btn->imgNormal);
		putimage(x, y, &btn->imgNormal);//���µ�״̬

	}
	


}
void update()//��Ⱦ(��ʾ)��Ϸ����
{
	BeginBatchDraw();
	if (win) {
		loadimage(0, "res/suc.png");
		//FlushBatchDraw();//���ϸ���
		//��������
		//mciSendString("play res/move.mp3", 0, 0, 0);
		//��ͣһ��
		//system("pause");
		FlushBatchDraw();//���ϸ���
		system("pause");
		initAllButtons();
		win = false;
	}
	else {
		//��ʾ��Ϸ����ͼƬ
		putimage(0, 0, &imgBg);//��(0,0)λ�ÿ�ʼ��ӡͼƬ
		//��ʾ�˸���ť
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				drawButton(btns[i][j]);

				

			}
		}
	}
	EndBatchDraw();
}

//��ʼ����ť
void initButton(struct button* btn, const char* normalFile, const char* pressFile,
	int width, int height, int flag, int row, int col) {
	if (!btn)
	return;//����������voidʱʹ��return��ǰ����
	loadimage(&btn->imgNormal, normalFile, width, height, true);
	loadimage(&btn->imgPress, pressFile, width, height, true);
	btn->width = width;
	btn->height = height;
	btn->pressed = false;
	btn->flag = flag;
	btn->row = row;
	btn->col = col;

}

bool move(struct button *btn) {
	if (btn->flag == 0)return false;
	//��ǰ��ťλ��
	int row = btn->row;
	int col = btn->col;
	//�����ƶ�
	if (row>0&&btns[row - 1][col]->flag == 0) {
		//����������ѡ��ť��λ��
		struct button* tmp = btn;
		btns[row][col] = btns[row - 1][col];
			btns[row - 1][col] = tmp;
			tmp->row--;
			mciSendString("play res/move.mp3", 0, 0, 0);

			return true;
	}
	//�����ƶ�
	if (row <2  && btns[row + 1][col]->flag == 0) {
		//����������ѡ��ť��λ��
		struct button* tmp = btn;
		btns[row][col] = btns[row +1][col];
		btns[row + 1][col] = tmp;
		tmp->row++;
		mciSendString("play res/move.mp3", 0, 0, 0);

		return true;
	}
	//�����ƶ�
	if (col > 0 && btns[row ][col-1]->flag == 0) {
		//����������ѡ��ť��λ��
		struct button* tmp = btn;
		btns[row][col] = btns[row ][col-1];
		btns[row ][col-1] = tmp;
		tmp->col--;
		mciSendString("play res/move.mp3", 0, 0, 0);

		return true;
	}
	//�����ƶ�
	if (col < 2 && btns[row][col +1]->flag == 0) {
		//����������ѡ��ť��λ��
		struct button* tmp = btn;
		btns[row][col] = btns[row][col + 1];
		btns[row][col +1] = tmp;
		tmp->col++;
		mciSendString("play res/move.mp3", 0, 0, 0);

		return true;
	}
	
	return false;
}

void initAllButtons()
{
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++)
		{
			btns[i][j] = new struct button;//�ڶѿռ�,����һ���ڴ�(c++)
		//�ڶ���һ��ר�ŵĺ���,ר�ų�ʼ��ָ����ť
			char name1[64];
			char name2[64];
			int key = i * 3 + j + 1;
		

			sprintf_s(name1,sizeof(name1), "res/sz%d.png", key);
			sprintf_s(name2,sizeof(name2), "res/sz%dp.png", key);
			initButton(btns[i][j], name1, name2, 106, 106, key, i, j);
			
		}
	}
	btns[2][2]->flag = 0;//��ʾ�հװ�ť
	//��������
	int count = 0;
	srand(time (NULL));// �������
	while (count < 100) {
		//���ָ����ť
		int row = rand() % 3;//0,2
		int col = rand() % 3;
		//move
		if (move(btns[row][col]))
		{
			count++;
		}
	}
	
}
void init()
{
	//������Ϸ����
	initgraph(1080*0.4,2400*0.4);
	
	//��ʾ��Ϸ����,�ѱ���ͼƬ���ص�����
	loadimage(&imgBg,"res/bg1.png",1080*0.4,2400*0.4,true);
	//��ʼ����ť
	initAllButtons();
	win = false;
}


//��鰴ť�Ƿ񵥻���ѡ��(����)
bool checkButtonSelect(struct button* btn, ExMessage* msg) {
	int x = 55 + btn->col * (106 + 1);
	int y = 321 + btn->row * (106 + 1);
	float margin = 0.1;//�߽�ϵ��,�����߽粻���ƶ���ť	
	return msg->x > x + btn->width * margin &&
		   msg->x<x + btn->width * (1 - margin) &&
		   msg->y>y + btn->height * margin &&
		   msg->y < y + btn->height * (1 - margin);
}
//�û����
void userClick() {
	ExMessage msg;//�ж����״̬
	static button* btn = NULL;//���徲̬������������һ�ΰ���ȥ�İ�ť
	if (peekmessage(&msg)) {
		if (msg.message == WM_LBUTTONDOWN) {//��������������
			for (int i = 0;i < 3;i++) {
				for (int j = 0;j < 3;j++) {
					if (btns[i][j]->flag && checkButtonSelect(btns[i][j], &msg)) {
						btns[i][j]->pressed = true;
						btn = btns[i][j];
					}
				}
			}
		}

		else if (msg.message == WM_LBUTTONUP) {//��̧��

			if (btn) {
				move(btn);
				btn->pressed = false;
				btn = NULL;
			}

		}
	}
}

//�ж���Ϸ�Ƿ�ɹ�
bool checkSuccess() {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (btns[i][j]->flag &&btns[i][j]->flag != i * 3 + j + 1) {
				win = false;
				

				return false;
			}
				
		}
	}
	loadimage(0, "res/suc.jpg");
	mciSendString("paly res/next.mp3", 0, 0, 0);
	win = true;
	return true;
	

	
}
int main(void)
{
	init();//��ʼ��
	//��Ⱦ(��ʾ)��Ϸ����
	update();
	
	while (1)
	{
		//init();
		userClick();//���
		update();
		//initAllButtons();
	//FlushBatchDraw();//���ϸ���
		if (checkSuccess())//�ж���Ϸ�Ƿ�ɹ�
		{
			
			//mciSendString("paly res/next.mp3", 0, 0, 0);
			
			break;
		}
		
	}

	system("pause");
	closegraph();//�ر�ͼ��ϵͳ
	return 0;
}