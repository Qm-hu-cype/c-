#pragma once
/**
	�κ�һ�Ŷ�������������:
	1.���ڵ�
	2,������
	3.������
	�����㷨:�ֶ���֮,������ֳ�����������,�������ٷֳ�������...
	ֱ�������ⲻ�ٷָ�
	������������:
				1.���涨�ڵ�Ĳ���Ϊ1,��һ�ŷǿն������ĵ�i�������2^(i-1)���ڵ�
				2.���κ�һ�Ŷ�����,�����Ϊ0��Ҷ�ڵ����Ϊ0,��Ϊ2�ķ�֧�ڵ����Ϊn2,����n0=n2+1;
				3..���涨�ڵ�Ĳ���Ϊ1,�����Ϊh�Ķ������ĵ����ڵ����Ϊ2^(h-1)
				4.���涨�ڵ�Ĳ���Ϊ1,����n���ڵ���������������,h=log2(n)
		ǰ��+���� ��ȷ������������
		����+���� ��ȷ������������
		ǰ��+���� ����ȷ������������



*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;
void PrevOrder(BTNode* root);//ǰ��(ȷ����)
void InOrder(BTNode* root);//����
void PosOrder(BTNode* root);//����
void TreeSize(BTNode* root,int* psize);//�ڵ����
int TreeLeafSize(BTNode* root);//Ҷ�ӽڵ�ĸ���
void LevelOrder(BTNode* root);//�������
void DestoryTree(BTNode** root);



