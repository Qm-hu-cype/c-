
#include "SEqList.h"

//��ɾ��ĵȽӿں���

void SeqListInit(SL*ps)
{
	//memset(ps->a, 0, sizeof(SQDataType) * N);//���ֽڳ�ʼ��
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListDestory(SL* ps)//���ٿռ�
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void SeqListCheckCapacity(SL* ps)
{
	//���˾�Ҫ����
	if (ps->size == ps->capacity)
	{
		//����,һ����������
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->a, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
	

}

//β��,ͷ��,βɾ,ͷɾ

void SeqListPushBack(SL* ps, SQDataType x)
{
//	if (ps->size >= N)
//	{
//		printf("SeqList is Full\n");//˳�������
//		return;
//	}
//	ps->a[ps->size] = x;
//	ps->size++;
	 SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;

}
	
void SeqListPrint(SL* ps)
{
	for (int i = 0;i < ps->size;i++)
	{
		printf("%d ",ps->a[i]);
	}
}
//ͷ����
void SeqListPushFront(SL* ps, SQDataType x)
{
	//1.��ʼ����
	//2.��������
	//3.��������
	 SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopBack(SL* ps)//βɾ
{
	assert(ps->size>0);
	ps->size--;
}
void SeqListPopBack(SL* ps, SQDataType x)//ͷɾ
{
	assert(ps->size > 0);

	int start = 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->size--;
}
void SeaListInsert(SL* ps, int pos, SQDataType x)//�������
{
	assert(pos < ps->size);
	 SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end>=pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;

}

void SeaListErase(SL* ps, int pos)//���ɾ��
{
	assert(pos < ps->size);
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start] = ps->a[start];
		start++;
	}
	ps->size--;

}
int SeaListFind(SL* ps, SQDataType x)//����
{
	for (int i = 0;i <ps-> size;i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

void SeaListModity(SL* ps,int pos,SQDataType x)//��
{
	assert(pos < ps->size);
	ps->a[pos] = x;
}