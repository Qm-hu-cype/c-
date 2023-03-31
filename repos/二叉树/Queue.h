#pragma once


#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


typedef int QDataType;
 typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;

}QNode;

 typedef struct Queue
 {
	 QNode* head;
	 QNode* tail;
 }Queue;
 void QueueInit(Queue* pq);//��ʼ��
 void QueueDestory(Queue* pq);
 void QueuePush(Queue* pq,QDataType x);//���(��β��)
 void QueuePop(Queue* pq);//����(��ͷ��)
 QDataType QueueFront(Queue* pq);//ȡ��ͷ����
 QDataType QueueBack(Queue* pq);//ȡ��β����
 int QueueSize(Queue* pq);//���ݸ���
 bool QueueEmpty(Queue* pq);//�п�


