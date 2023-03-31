#pragma once

/*
*	�������������ʵ��(�������)
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{	
	STDataType *a;
	int top;//ջ��
	int capacity;


}ST;

void StackInit(ST* ps);//��ʼ��
void StackDestory(ST* ps);//ɾ��
void StackPush(ST* ps, STDataType x);//��ջ
void StackPop(ST* ps);//��ջ
STDataType StackTop(ST* ps);//����ջ��Ԫ��
int StackSize(ST* ps);//���ݸ���
bool StackEmpty(ST* ps);//�ж��Ƿ�Ϊ��


