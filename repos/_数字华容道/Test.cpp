#include "tools.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

IMAGE imgBg;


void moveButton(Button* btn)
{

}


void drawButton(Button* btn)
{

}

Button* checkButtonClick(MOUSEMSG* msg)
{
	return NULL;
}

void update()
{
	putimage(0, 0, &imgBg);
}

void checkSuccess()
{

}

void init()
{
	initgraph(1080 * 0.4, 2400 * 0.4);
	loadimage(&imgBg, "res/bg1,jpg", 1080 * 0.4, 2400 * 0.4, true);

}

int main()
{
	init();
	update();//重绘所有按钮
	Button* btn = NULL;
	while (1)
	{
		MOUSEMSG m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			btn = checkButtonClick(&m);//计算选择了那个按钮
			break;
		case WM_LBUTTONUP:
			if (btn) {
				//btn->pressed=false;
				moveButton(btn);
			}

		}
		drawButton(btn);
		checkSuccess();


	}
	system("pause");
	closegraph();
	return 0;
}

