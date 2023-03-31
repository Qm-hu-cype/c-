#pragma once

/*
*	可用数组和链表实现(数组更优)
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{	
	STDataType *a;
	int top;//栈顶
	int capacity;


}ST;

void StackInit(ST* ps);//初始化
void StackDestory(ST* ps);//删除
void StackPush(ST* ps, STDataType x);//入栈
void StackPop(ST* ps);//出栈
STDataType StackTop(ST* ps);//返回栈顶元素
int StackSize(ST* ps);//数据个数
bool StackEmpty(ST* ps);//判断是否为空


