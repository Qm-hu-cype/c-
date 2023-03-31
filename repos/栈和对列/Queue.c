#include "Queue.h"


void QueueInit(Queue* pq)//初始化
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

void QueuePush(Queue* pq, QDataType x)//入队(对尾入)
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
void QueuePop(Queue* pq)//出队(对头出)
{
	assert(pq);
	assert(pq->head);

	//一个节点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;

	}
	//多个节点
	else
	{
	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	
	}


}
QDataType QueueFront(Queue* pq)//取队头数据
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;

}
QDataType QueueBack(Queue* pq)//取队尾数据
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
int QueueSize(Queue* pq)//数据个数
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
bool QueueEmpty(Queue* pq)//判空
{
	assert(pq);
	return pq->head == NULL;

}