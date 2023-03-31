#define _CRT_SECURE_NO_WARNINGS

#include"tools.h"
#include<mmsystem.h>//播放音乐
#pragma comment(lib,"winmm.lib")

IMAGE imgBg;//定义图片变量,用来显示背景



struct button* btns[3][3];
bool win;

//渲染按钮
void drawButton(struct button* btn) {
	if (btn == NULL) 
		return;
	//按钮坐标位置
	int x = 55 + btn->col * (106 + 1);
	int y = 321 + btn->row * (106 + 1);
	//绘制按钮(两种状态,是否被按下)
	if (btn->pressed) {
		//drawPNG(btn->row, btn->col, &btn->imgPress);
		putimage(x, y, &btn->imgPress);//未按下的状态
	}
	else {
		//drawPNG(btn->row, btn->col, &btn->imgNormal);
		putimage(x, y, &btn->imgNormal);//按下的状态

	}
	


}
void update()//渲染(显示)游戏界面
{
	BeginBatchDraw();
	if (win) {
		loadimage(0, "res/suc.png");
		//FlushBatchDraw();//马上更新
		//播放音乐
		//mciSendString("play res/move.mp3", 0, 0, 0);
		//暂停一下
		//system("pause");
		FlushBatchDraw();//马上更新
		system("pause");
		initAllButtons();
		win = false;
	}
	else {
		//显示游戏背景图片
		putimage(0, 0, &imgBg);//从(0,0)位置开始打印图片
		//显示八个按钮
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				drawButton(btns[i][j]);

				

			}
		}
	}
	EndBatchDraw();
}

//初始化按钮
void initButton(struct button* btn, const char* normalFile, const char* pressFile,
	int width, int height, int flag, int row, int col) {
	if (!btn)
	return;//返回类型是void时使用return提前结束
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
	//当前按钮位置
	int row = btn->row;
	int col = btn->col;
	//向上移动
	if (row>0&&btns[row - 1][col]->flag == 0) {
		//交换空与所选按钮的位置
		struct button* tmp = btn;
		btns[row][col] = btns[row - 1][col];
			btns[row - 1][col] = tmp;
			tmp->row--;
			mciSendString("play res/move.mp3", 0, 0, 0);

			return true;
	}
	//向下移动
	if (row <2  && btns[row + 1][col]->flag == 0) {
		//交换空与所选按钮的位置
		struct button* tmp = btn;
		btns[row][col] = btns[row +1][col];
		btns[row + 1][col] = tmp;
		tmp->row++;
		mciSendString("play res/move.mp3", 0, 0, 0);

		return true;
	}
	//向左移动
	if (col > 0 && btns[row ][col-1]->flag == 0) {
		//交换空与所选按钮的位置
		struct button* tmp = btn;
		btns[row][col] = btns[row ][col-1];
		btns[row ][col-1] = tmp;
		tmp->col--;
		mciSendString("play res/move.mp3", 0, 0, 0);

		return true;
	}
	//向右移动
	if (col < 2 && btns[row][col +1]->flag == 0) {
		//交换空与所选按钮的位置
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
			btns[i][j] = new struct button;//在堆空间,分配一块内存(c++)
		//在定义一个专门的函数,专门初始化指定按钮
			char name1[64];
			char name2[64];
			int key = i * 3 + j + 1;
		

			sprintf_s(name1,sizeof(name1), "res/sz%d.png", key);
			sprintf_s(name2,sizeof(name2), "res/sz%dp.png", key);
			initButton(btns[i][j], name1, name2, 106, 106, key, i, j);
			
		}
	}
	btns[2][2]->flag = 0;//表示空白按钮
	//打乱排序
	int count = 0;
	srand(time (NULL));// 随机种子
	while (count < 100) {
		//随机指定按钮
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
	//创建游戏窗口
	initgraph(1080*0.4,2400*0.4);
	
	//显示游戏界面,把背景图片加载到变量
	loadimage(&imgBg,"res/bg1.png",1080*0.4,2400*0.4,true);
	//初始化按钮
	initAllButtons();
	win = false;
}


//检查按钮是否单击被选择(按下)
bool checkButtonSelect(struct button* btn, ExMessage* msg) {
	int x = 55 + btn->col * (106 + 1);
	int y = 321 + btn->row * (106 + 1);
	float margin = 0.1;//边界系数,碰到边界不会移动按钮	
	return msg->x > x + btn->width * margin &&
		   msg->x<x + btn->width * (1 - margin) &&
		   msg->y>y + btn->height * margin &&
		   msg->y < y + btn->height * (1 - margin);
}
//用户点击
void userClick() {
	ExMessage msg;//判断鼠标状态
	static button* btn = NULL;//定义静态变量来保存上一次按下去的按钮
	if (peekmessage(&msg)) {
		if (msg.message == WM_LBUTTONDOWN) {//鼠标左键单击按下
			for (int i = 0;i < 3;i++) {
				for (int j = 0;j < 3;j++) {
					if (btns[i][j]->flag && checkButtonSelect(btns[i][j], &msg)) {
						btns[i][j]->pressed = true;
						btn = btns[i][j];
					}
				}
			}
		}

		else if (msg.message == WM_LBUTTONUP) {//左抬起

			if (btn) {
				move(btn);
				btn->pressed = false;
				btn = NULL;
			}

		}
	}
}

//判断游戏是否成功
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
	init();//初始化
	//渲染(显示)游戏界面
	update();
	
	while (1)
	{
		//init();
		userClick();//点击
		update();
		//initAllButtons();
	//FlushBatchDraw();//马上更新
		if (checkSuccess())//判断游戏是否成功
		{
			
			//mciSendString("paly res/next.mp3", 0, 0, 0);
			
			break;
		}
		
	}

	system("pause");
	closegraph();//关闭图形系统
	return 0;
}