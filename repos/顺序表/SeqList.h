//��������
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#define N 10

typedef int SQDataType;
//��̬˳���
//����:�����˲�����,�������ò����˷�,����������

//��̬��
typedef struct SeqList
{
	SQDataType* a;//ָ��̬���ٵ�����
	int size;//��Ч���ݵĸ���
	int capacity;//����

}SL;

//typedef struct SeqList SL;

//��ɾ��ĵȽӿں���
 void SeqListInit(SL* ps);
 void SeqListPrint(SL* ps);

 void SeqListPushBack(SL* ps, SQDataType x);//β��
 void SeqListPushFront(SL* ps, SQDataType x);//ͷ��
 void SeqListPopBack(SL* ps);//βɾ
 void SeqListPopBack(SL* ps);//ͷɾ
 void SeaListInsert(SL* ps, int pos, SQDataType x);//�������
 void SeaListErase(SL* ps, int pos, SQDataType x);//���ɾ��

 void SeqListDestory(SL* ps);//�ռ�����

 int SeaListFind(SL* ps, SQDataType x);//����

 void  SeaListModity(SL* ps,int pos, SQDataType x);//��
