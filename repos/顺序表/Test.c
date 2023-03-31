//测试
#include "SeqList.h"

void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
		//SeqListDestory(&s1);
}

void menu()//菜单
{
	printf("********************************************\n");
	printf("1.尾插数据, 2.头插数据\n");
	printf("3.尾删数据, 4.头删数据\n");
	printf("5.打印数据, -1.退出\n");
	printf("请输入你的选项:\n");
	printf("********************************************\n");
}
int main()
{
	//TestSeqList1();
	int option = 0;
	int x = 0;
	while (option != -1)
	{
		menu();
		scanf_s("%d", &option);
	}
	switch (option)
	{
	case 1:
		printf("请输入你要插入的数据,以-1结束\n");
		do
		{
			scanf("%d", &x);
			if (x != -1)
			{
				SeqListPopBack(&s1, x);
			}
		} while (x!=-1);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
	return 0;
}
