
#include "BinTree.h"

void PrevOrder(BTNode* root)//ǰ��
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);


}
void InOrder(BTNode* root)//����
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);

}
void PosOrder(BTNode* root)//����
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PosOrder(root->left);
	PosOrder(root->right);
	printf("%c ", root->data);

}

void TreeSize(BTNode* root,int *psize)//�ڵ����
{
	if (root == NULL)
	{
		return;
	}
	else
	{

		++(*psize);
	}
	TreeSize(root->left,psize);
	TreeSize(root->right,psize);
}
/*	�ڵ��������:
* int TreeSize(BTNode* root)
* {
*	return root==NULL?0:TreeSize(root->left+TreeSize(root->right)+1;
* 
* }
	
*/

int TreeLeafSize(BTNode* root)//Ҷ�ӽڵ�ĸ���
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);

}

//�������
//����: ��һ�����һ��

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{	
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
		printf("\n");
	}

}
void DestoryTree(BTNode** root)
{
	if (root != NULL)
	{
		return;

	}
	DestoryTree((*root)->left);
	DestoryTree((*root)->right);
	free(*root);
	*root = NULL;



}


