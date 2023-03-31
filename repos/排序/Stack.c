#include "Stack.h"

void StackInit(ST* ps)//��ʼ��
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->top = 0;//��ʼtop ��0��ʾtopָ�����ջ��Ԫ�ص���һ��
				//��ʼtop ��-1��ʾtopָ�����ջ��Ԫ��
	ps->capacity = 4;
}
void StackDestory(ST* ps)//ɾ��
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackPush(ST* ps, STDataType x)//��ջ
{
	
	assert(ps);
	//���˾�Ҫ����
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
void StackPop(ST* ps)//��ջ
{
	assert(ps);
	assert(ps->top > 0);//ջ����,����Pop,ֱ����ֹ���򱨴�
	ps->top--;

}
STDataType StackTop(ST* ps)//����ջ��Ԫ��
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)//���ݸ���
{
	return ps->top;
}
bool StackEmpty(ST* ps)//�ж��Ƿ�Ϊ��
{
	assert(ps);
	return ps->top == 0;
} 