#pragma once
/**
	任何一颗二叉树的三部分:
	1.根节点
	2,左子树
	3.右子树
	分治算法:分而治之,大问题分成类似子问题,子问题再分成子问题...
	直到子问题不再分割
	二叉树的性质:
				1.若规定节点的层数为1,则一颗非空二叉树的第i层最多有2^(i-1)个节点
				2.对任何一颗二叉树,如果度为0其叶节点个数为0,度为2的分支节点个数为n2,则有n0=n2+1;
				3..若规定节点的层数为1,则深度为h的二叉树的的最大节点个数为2^(h-1)
				4.若规定节点的层数为1,具有n个节点的满二叉树的深读,h=log2(n)
		前序+中序 可确定二叉树序列
		后序+中序 可确定二叉树序列
		前序+后序 不可确定二叉树序列



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
void PrevOrder(BTNode* root);//前序(确定根)
void InOrder(BTNode* root);//中序
void PosOrder(BTNode* root);//后序
void TreeSize(BTNode* root,int* psize);//节点个数
int TreeLeafSize(BTNode* root);//叶子节点的个数
void LevelOrder(BTNode* root);//层序遍历
void DestoryTree(BTNode** root);



