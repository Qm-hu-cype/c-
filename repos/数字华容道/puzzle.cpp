#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<graphics.h>//引入图形库
#include<time.h>
#include "tools.h"
#include<mmsystem.h>//播放音乐
#pragma comment(lib,"winmm.lib")

IMAGE imgBg;//定义一个图片变量,用来显示背景

int offx = 55;//左部边距
int offy = 321;//顶部边距  

/*//按钮的初始化
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

			//对k个按钮进行初始化
			char name1[64], name2[64];
			sprintf(name1, "res/sz%d.png", k + 1);
			sprintf(name1, "res/sz%dp.png", k + 1);
			initButton(btns[k], name1, name2, 106, 106, k + 1);//按钮宽高均为106
			//按钮坐标
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



//创建按钮类型
struct Button
{
	IMAGE imgNormal;//按钮在普通状态下的的图片
	IMAGE imgPress;//按下去的状态
	int width, height;//宽高
	int x, y;//按钮坐标
	int flag;//按钮标记
	bool pressed;//表示当前是否被按下
};

 struct Button btns[8];//按钮
 int data[3][3];
//按钮的初始化
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

			//对k个按钮进行初始化
			char name1[64], name2[64];//文件名
			sprintf_s(name1, "res/sz%d.png", k + 1);
			sprintf_s(name1, "res/sz%dp.png", k + 1);
			initButton(&btns[k], name1, name2, 106, 106, k + 1);//按钮宽高均为106
			//按钮坐标
			btns[k].x = offx + j * (106 + 1);
			btns[k].y = offy + i * (106 + 1);

		}
	}
	//to do,,,打乱数据结构
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
//检查指定按钮,是否被选择
bool checkButtonSelect(Button *btn,MOUSEMSG *msg) {
	//  按钮范围
	if (msg->x >= btn->x + btn->width * 0.1
		&& msg->x <= btn->x + btn->width * 0.9
		&& msg->y >= btn->y + btn->height * 0.1
		&& msg->y <= btn->y + btn->height * 0.9) {
		return true;
	}
	else
		return false;
	
	
}
//判断能否移动
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
	//创建游戏窗口
	initgraph(1080 * 0.4, 2400 * 0.4);
	//把背景图片加载到变量中
	loadimage(&imgBg, _T("res/bg1.png"), 1080 * 0.4, 2400 * 0.4, true);
	//初始化按钮
	buttonsInit();
}



//更新游戏画面
void update()
{
	putimage(0, 0, &imgBg);//让坐标(0,0)位置显示之前的绘图输出
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
	Gameinit();// init初始化 grap图形窗口
	//更新游戏画面
	update();
	Button* btn = NULL;
	//BeginBatchDraw();//批量绘图但不输出到屏幕上
	 //更新游戏画面

	//EndBatchDraw();//直到EndBatchDraw()才将之前的绘图输出


	while (1)
	{
		//获取鼠标信息
		MOUSEMSG m = GetMouseMsg();
		//鼠标左键按下,抬起开始移动
		switch(m.uMsg)//判断鼠标状态
		{
		case  WM_LBUTTONDOWN://按下
		//单击按下进行选择
		//计算那个按键被点击
			btn=checkButtonClick(m);
			break;
		case  WM_LBUTTONUP://抬起
			if (btn) {
				btn->pressed = false;
				moveButton(btn);
			}
			break;

		}
	}
	drawButton(btn);
	//判断游戏是否成功
	system("pause");//冻结屏幕
	closegraph();//关闭图形窗口
	return 0;
}