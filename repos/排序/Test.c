#include <stdio.h>
#include<stdlib.h>
#include "Stack.h"


//��������(���趼������)
//ʱ�临�Ӷ�O(N^2)
void InsertSotr(int* a, int n)
{
	//[0,end]����,end+1λ�ò����ȥ,ʹ[0,end+1]����
	for (int i = 0;i < n - 1;++i)
	{
	 int end=i;
	 int tmp = a[end + 1];
	 while (end >= 0)
	{
		if (a[end] > tmp)
		{
			a[end + 1] = a[end];
			--end;

		}
		else
			break;
	}
	a[end + 1] = tmp;
	}

}

//ϣ������(ֱ�Ӳ���������Ż�)
//1.�Ƚ���Ԥ����,������ӽ�����
// Ԥ����:������
// �Զ�����Ϊgap��Ԥ����,gap�ɴ��С,gapԽ��,���������Խ����ŵ�����,С��������Խ���ŵ�ǰ��
//		gapԽ��,Ԥ����Խ���ӽ�����
//		gapԽС,Ԥ����Խ�ӽ�����
//		gap==1ʱ����ֱ�Ӳ�������'
// 
//2.ʱ�临�Ӷ�O(N*logN)

void ShellSort(int *a,int n)
{
	

	int gap=n;
	while (gap > 1)
	{
		gap /= 2;
	//�Ѽ��Ϊgap�Ķ�������ͬʱ��
	for (int i = 0;i < n - gap;++i)
	{
	int end=i;
	int tmp = a[end + gap];
	while (end >= 0)
	{
		if (a[end] > tmp)
		{
			a[end + gap] = a[end];
			end -= gap;
		}
		else
			break;
	}
	a[end + gap] = tmp;

	}
	}
}

//������
//�ѵ��߼��ṹ��һ����ȫ������
//����ṹ��һ������
//ͨ���±길�ӽڹ�ϵ
//leftchild=parent*2+1;
//rightchile=parent*2+2;
//parent=(child-1)/2;
//������:����ڵ�Ĺؼ��������������нڵ�����ֵ(����Сֵ)
//����(MaxHeap):Ҳ��"�󶥶�":���ֵ
//��С��(MinHeap):Ҳ��"С����":��Сֵ
//���Ҫ��:�������еĸ��׶����ڵ��ں���
//С��Ҫ��:�������еĸ��׶�С�ڵ��ں���
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//С��
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//����
	while (child<n)
	{
		//ѡ�����Һ��ӽ�С��
		if (a[child + 1] < a[child]&&child+1<n)
		{
			child += 1;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]); 
			parent = child;
			child = parent * 2 + 1;

		}
		else
			break;
	}

}
/*
* ���������������С��,�Ͳ���ֱ�����µ����㷨��,�Ϳ��Ե��Ŵ����һ��������ʼ��,�ٷ���������,Ҷ�Ӳ���Ҫ��,��
* �������һ����Ҷ�ӵ�������ʼ��
*/
void HeapSort(int *a,int n)
{
	//����
	for (int i = (n - 2) / 2;i >= 0;--i)
	{
		AdjustDwon(a, n, i);
	}

	//�����򽨴��
	
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end - 1]);
		AdjustDwon(a, end, 0);
		--end;

	}



	
	//����ǽ�С��,��С���ڶѶ�,�Ѿ���ѡ������.��ô��ʣ�µ�����Ҫ��һ����,����ʣ�����ṹ������,��Ҫ���½��Ѳ���
	//ѡ����һ����,���ѵ�ʱ�临�Ӷ���O(N),��ô�������ǲ�����,���Ƕ������û��Ч��������



}
//ֱ��ѡ������
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin;i <= end;++i)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i] > maxi)
			{
				maxi = i;
			}
			//���beging��maxi�ص�,��Ҫ����maxi��λ��

			if (begin == maxi)
			{
				maxi = mini;
			}
			Swap(&a[begin], &a[mini]);
			Swap(&a[end], &a[maxi]);
			++begin;
			--end;

		}
	}
}

//ð������
void BubbleSort(int* a, int n)
{
	//����(ð��)
		//for (int i = 0;i < n - 1;i++)//����
		//{
		//	for (int j = 0;j < n - i - 1;j++)//ÿ�˵Ĵ���
		//	{

		//		if (a[j] > a[j + 1])
		//		{

		//			int tmp = a[j + 1];
		//			a[j + 1] = a[j];
		//			a[j] = tmp;
		//		}
		//	}
		//}
	for (int j = 0;j < n;++j)
	{	
		int exchange = 0;
	for (int i = 1;i < n-j;++i)
	{
		if (a[i - 1] > a[i])
		{
			Swap(&a[i - 1], &a[i]);
		}
		if (exchange == 0)
		{
			break;
		}
	}
 }
	/*
	int end=n;
	while(end)
	{
	for(int i=1;i<n;++i)
	{
	if(a[i-1]>a[i])
	Swap(&a[i-1,&a[i]);
	}
	--end;
	}
	*/
}

//����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
			return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}




//��������
//ʱ�临�Ӷ�O(N*logN)
//����ʲô����?ʱ�临�Ӷȶ���
//��������				O(N^2)


//�ڿӷ�
int ParstSort(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int begin = left, end = right;
	int pivot = begin;//��
	int key = a[begin];
	while (begin < end)
	{
		//�ұ���С�ŵ����
		while (a[end] >= key && begin < end)
		{
			--end;

		}
		a[pivot] = a[end];
		pivot = end;
		while (a[begin] <= key && begin < end)
		{
			++begin;

		}
		//,����Ҵ���ұ�
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;
	return pivot;
}
//����ָ�뷨
int ParstSort2(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int begin = left, end = right;
	//int pivot = begin;//��
	int keyi = begin;
	while (begin < end)
	{	
		//��С
		while (begin < end && a[end]>=a[keyi	])
		{
			--end;
		}
		//�Ҵ�
		while (begin < end && a[begin] >= a[keyi])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);
	return keyi;

}
//ǰ��ָ�뷨
int ParstSort3(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int keyi = left;
	int prev = left, cur = left + 1;
	while(cur <= right)
	{
		if (a[cur] < a[keyi])
		{
			++prev;
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}


void QuickSort(int* a, int left,int right)
{

	if (left >= right)
		return;
	int keyindex = ParstSort(a, left, right);
	Swap(&a[left], &a[keyindex]);
	//int begin = left, end = right;
	//int pivot = begin;//��
	//int key = a[begin];
	//while (begin < end)
	//{
	//	//�ұ���С�ŵ����
	//	while (a[end] >= key&&begin<end)
	//	{
	//		--end;

	//	}
	//	a[pivot] = a[end];
	//	pivot = end;
	//	while (a[begin ]<= key&&begin<end)
	//	{
	//		++begin;

	//	}
	//	//,����Ҵ���ұ�
	//	a[pivot] = a[begin];
	//	pivot = begin;
	//}
	//pivot = begin;
	//a[pivot] = key;
	//С�����Ż�
	if (keyindex - 1 - left > 10)
		QuickSort(a, left, keyindex - 1);
	else
		InsertSotr(a + left, keyindex - 1 - right + 1);
	if(right- keyindex -1>10)
	QuickSort(a, keyindex +1, right );
	else 
		InsertSotr(a + keyindex +1, right- keyindex -1+1);
}

//�鲢����
void _MergeSort(int* a, int left, int right,int* tmp)//�Ӻ���
{
	if (left >= right)
		return;
	int gap = 1;
	int mid = (left + right) >> 1;
	//����[left,mid] [mid+1,right]����,��ô�Ϳ��Թ鲢��
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid+1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}

		

	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//������ȥ
	for (int i = left;i <= right;++i)
	{
		a[i] = tmp[i];
	}


	gap *= 2;
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//ʱ�临�Ӷ�O(N*logN)
void MergSortNonR(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int )*n);
	int gap = 1;//ÿ�����ݵĸ���
	while (gap < n)
	{

		for (int i = 0;i < n;i += 2 * gap)
		{
			//[i+gap+i-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//�鲢�������Ұ�������ܾͲ�����
			if (begin2 >= n)
				break;
			//�鲢�������Ұ����������

			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
		}

			//������ȥ
			for (int j = 0;j < n;++j)
			{
				a[j] = tmp[j];
			}
		
		gap *= 2;
	}	
	free(tmp);
	
}

//�ݹ��ȱ��:1.ջ֡�����̫��,ջ�ռ䲻����,���ܻ�ջ���

//�ݹ�ķǵݹ�:1.ֱ�Ӹ�ѭ��(��),2.�������ݽṹջģ��ݹ����(����һ��)
//�ǵݹ�
void QuickSortNonR(int* a, int n)
{
	ST st;
	StackInit(&st);
	StackPush(&st,n-1);
	StackPush(&st, 0);
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int keyIndex = ParstSort3(a, left, right);
		//[left,keyIndex-1] keyIndex [keyIndex+1,right]

		if (keyIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyIndex+1);
		}
		if (left < keyIndex - 1)
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}
	}
	StackDestory(&st);


}

void PrintArray(int *a,int n)
{
	for (int i = 0;i < n;++i)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
		//InsertSotr(a, 10);
	//ShellSort(a, 10);
	//HeapSort(a, 10);
	//QuickSort(a,0,9);
	//MergeSort(a, 10);
	MergSortNonR(a, 10);
		PrintArray(a, 10);

	return 0;
}