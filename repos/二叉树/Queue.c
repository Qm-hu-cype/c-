#include "Queue.h"


void QueueInit(Queue* pq)//��ʼ��
{
	assert(pq);
	pq->head = pq->tail = NULL;



}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	cur = NULL;
	pq->head = pq->tail = NULL;


}

void QueuePush(Queue* pq, QDataType x)//���(��β��)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
			exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail=newnode;

	}

}
void QueuePop(Queue* pq)//����(��ͷ��)
{
	assert(pq);
	assert(pq->head);

	//һ���ڵ�
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;

	}
	//����ڵ�
	else
	{
	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	
	}


}
QDataType QueueFront(Queue* pq)//ȡ��ͷ����
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;

}
QDataType QueueBack(Queue* pq)//ȡ��β����
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
int QueueSize(Queue* pq)//���ݸ���
{
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;

	}
	return size;
}
bool QueueEmpty(Queue* pq)//�п�
{
	assert(pq);
	return pq->head == NULL;

}