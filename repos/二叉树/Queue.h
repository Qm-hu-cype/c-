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
 void QueueInit(Queue* pq);//初始化
 void QueueDestory(Queue* pq);
 void QueuePush(Queue* pq,QDataType x);//入队(对尾入)
 void QueuePop(Queue* pq);//出队(对头出)
 QDataType QueueFront(Queue* pq);//取队头数据
 QDataType QueueBack(Queue* pq);//取队尾数据
 int QueueSize(Queue* pq);//数据个数
 bool QueueEmpty(Queue* pq);//判空


