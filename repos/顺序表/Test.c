//����
#include "SeqList.h"

void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
		//SeqListDestory(&s1);
}

void menu()//�˵�
{
	printf("********************************************\n");
	printf("1.β������, 2.ͷ������\n");
	printf("3.βɾ����, 4.ͷɾ����\n");
	printf("5.��ӡ����, -1.�˳�\n");
	printf("���������ѡ��:\n");
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
		printf("��������Ҫ���������,��-1����\n");
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
