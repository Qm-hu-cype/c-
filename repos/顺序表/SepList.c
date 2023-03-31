
#include "SEqList.h"

//增删查改等接口函数

void SeqListInit(SL*ps)
{
	//memset(ps->a, 0, sizeof(SQDataType) * N);//按字节初始化
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListDestory(SL* ps)//销毁空间
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void SeqListCheckCapacity(SL* ps)
{
	//满了就要扩容
	if (ps->size == ps->capacity)
	{
		//扩容,一般是扩两倍
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

//尾插,头插,尾删,头删

void SeqListPushBack(SL* ps, SQDataType x)
{
//	if (ps->size >= N)
//	{
//		printf("SeqList is Full\n");//顺序表满了
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
//头插入
void SeqListPushFront(SL* ps, SQDataType x)
{
	//1.初始条件
	//2.结束条件
	//3.迭代过程
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
void SeqListPopBack(SL* ps)//尾删
{
	assert(ps->size>0);
	ps->size--;
}
void SeqListPopBack(SL* ps, SQDataType x)//头删
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
void SeaListInsert(SL* ps, int pos, SQDataType x)//随机插入
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

void SeaListErase(SL* ps, int pos)//随机删除
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
int SeaListFind(SL* ps, SQDataType x)//查找
{
	for (int i = 0;i <ps-> size;i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

void SeaListModity(SL* ps,int pos,SQDataType x)//改
{
	assert(pos < ps->size);
	ps->a[pos] = x;
}