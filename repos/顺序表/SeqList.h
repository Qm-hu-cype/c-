//函数声明
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#define N 10

typedef int SQDataType;
//静态顺序表
//问题:给少了不够用,给多了用不完浪费,不能灵活控制

//动态的
typedef struct SeqList
{
	SQDataType* a;//指向动态开辟的数组
	int size;//有效数据的个数
	int capacity;//容量

}SL;

//typedef struct SeqList SL;

//增删查改等接口函数
 void SeqListInit(SL* ps);
 void SeqListPrint(SL* ps);

 void SeqListPushBack(SL* ps, SQDataType x);//尾插
 void SeqListPushFront(SL* ps, SQDataType x);//头插
 void SeqListPopBack(SL* ps);//尾删
 void SeqListPopBack(SL* ps);//头删
 void SeaListInsert(SL* ps, int pos, SQDataType x);//随机插入
 void SeaListErase(SL* ps, int pos, SQDataType x);//随机删除

 void SeqListDestory(SL* ps);//空间销毁

 int SeaListFind(SL* ps, SQDataType x);//查找

 void  SeaListModity(SL* ps,int pos, SQDataType x);//改
