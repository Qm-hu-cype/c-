#include "Stack.h"

void StackInit(ST* ps)//初始化
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->top = 0;//初始top 给0表示top指向的是栈顶元素的下一个
				//初始top 给-1表示top指向的是栈顶元素
	ps->capacity = 4;
}
void StackDestory(ST* ps)//删除
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackPush(ST* ps, STDataType x)//入栈
{
	
	assert(ps);
	//满了就要扩容
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * (sizeof(STDataType)));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;

		}
	}

	ps->a[ps->top] = x;
	ps->top++;

}
void StackPop(ST* ps)//出栈
{
	assert(ps);
	assert(ps->top > 0);//栈空了,调用Pop,直接终止程序报错
	ps->top--;

}
STDataType StackTop(ST* ps)//返回栈顶元素
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)//数据个数
{
	return ps->top;
}
bool StackEmpty(ST* ps)//判断是否为空
{
	assert(ps);
	return ps->top == 0;
} 