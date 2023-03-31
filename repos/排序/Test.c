#include <stdio.h>
#include<stdlib.h>
#include "Stack.h"


//插入排序(假设都是升序)
//时间复杂度O(N^2)
void InsertSotr(int* a, int n)
{
	//[0,end]有序,end+1位置插入进去,使[0,end+1]有序
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

//希尔排序(直接插入排序的优化)
//1.先进行预排序,让数组接近有序
// 预排序:分组排
// 对多组间隔为gap的预排序,gap由大变小,gap越大,大的数可以越快的排到后面,小的数可以越快排到前面
//		gap越大,预排序越不接近有序
//		gap越小,预排序越接近有序
//		gap==1时就是直接插入排序'
// 
//2.时间复杂度O(N*logN)

void ShellSort(int *a,int n)
{
	

	int gap=n;
	while (gap > 1)
	{
		gap /= 2;
	//把间隔为gap的多组数据同时排
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

//堆排序
//堆的逻辑结构是一颗完全二叉树
//物理结构是一个数组
//通过下标父子节关系
//leftchild=parent*2+1;
//rightchile=parent*2+2;
//parent=(child-1)/2;
//有序性:任意节点的关键字是其子树所有节点的最大值(或最小值)
//最大堆(MaxHeap):也称"大顶堆":最大值
//最小堆(MinHeap):也称"小顶堆":最小值
//大堆要求:树中所有的父亲都大于等于孩子
//小堆要求:树中所有的父亲都小于等于孩子
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//小堆
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//左孩子
	while (child<n)
	{
		//选出左右孩子较小的
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
* 如果左右子树不是小堆,就不能直接向下调整算法了,就可以倒着从最后一颗子树开始调,再分析倒着走,叶子不需要调,从
* 倒数最后一个非叶子的子树开始调
*/
void HeapSort(int *a,int n)
{
	//建堆
	for (int i = (n - 2) / 2;i >= 0;--i)
	{
		AdjustDwon(a, n, i);
	}

	//排升序建大堆
	
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end - 1]);
		AdjustDwon(a, end, 0);
		--end;

	}



	
	//如果是建小堆,最小数在堆顶,已经被选出来了.那么在剩下的数中要建一个堆,但是剩下树结构都乱了,需要重新建堆才能
	//选出下一个数,建堆的时间复杂度是O(N),那么这样不是不可以,但是堆排序就没有效率优势了



}
//直接选择排序
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
			//如果beging跟maxi重叠,需要修正maxi的位置

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

//冒泡排序
void BubbleSort(int* a, int n)
{
	//排序(冒泡)
		//for (int i = 0;i < n - 1;i++)//趟数
		//{
		//	for (int j = 0;j < n - i - 1;j++)//每趟的次数
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

//三数取中
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




//快速排序
//时间复杂度O(N*logN)
//快排什么情况最坏?时间复杂度多少
//有序情况最坏				O(N^2)


//挖坑法
int ParstSort(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int begin = left, end = right;
	int pivot = begin;//坑
	int key = a[begin];
	while (begin < end)
	{
		//右边找小放到左边
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
		//,左边找大放右边
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;
	return pivot;
}
//左右指针法
int ParstSort2(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int begin = left, end = right;
	//int pivot = begin;//坑
	int keyi = begin;
	while (begin < end)
	{	
		//找小
		while (begin < end && a[end]>=a[keyi	])
		{
			--end;
		}
		//找大
		while (begin < end && a[begin] >= a[keyi])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);
	return keyi;

}
//前后指针法
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
	//int pivot = begin;//坑
	//int key = a[begin];
	//while (begin < end)
	//{
	//	//右边找小放到左边
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
	//	//,左边找大放右边
	//	a[pivot] = a[begin];
	//	pivot = begin;
	//}
	//pivot = begin;
	//a[pivot] = key;
	//小区间优化
	if (keyindex - 1 - left > 10)
		QuickSort(a, left, keyindex - 1);
	else
		InsertSotr(a + left, keyindex - 1 - right + 1);
	if(right- keyindex -1>10)
	QuickSort(a, keyindex +1, right );
	else 
		InsertSotr(a + keyindex +1, right- keyindex -1+1);
}

//归并排序
void _MergeSort(int* a, int left, int right,int* tmp)//子函数
{
	if (left >= right)
		return;
	int gap = 1;
	int mid = (left + right) >> 1;
	//假设[left,mid] [mid+1,right]有序,那么就可以归并了
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
	//考贝回去
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

//时间复杂度O(N*logN)
void MergSortNonR(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int )*n);
	int gap = 1;//每组数据的个数
	while (gap < n)
	{

		for (int i = 0;i < n;i += 2 * gap)
		{
			//[i+gap+i-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//归并过程中右半区间可能就不存在
			if (begin2 >= n)
				break;
			//归并过程中右半区间算多了

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

			//考贝回去
			for (int j = 0;j < n;++j)
			{
				a[j] = tmp[j];
			}
		
		gap *= 2;
	}	
	free(tmp);
	
}

//递归的缺陷:1.栈帧的深度太深,栈空间不够用,可能会栈溢出

//递归改非递归:1.直接改循环(简单),2.借助数据结构栈模拟递归过程(复杂一点)
//非递归
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