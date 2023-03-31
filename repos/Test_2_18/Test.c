#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//int main()
//{
//	int score = 0;
//	scanf_s("%d",&score);
//	if (score < 0 || score>100)
//	{
//		printf("输入错误\n");
//		exit(-1);
//
//	}
//	int tmp = score / 10;
//	switch (tmp)
//	{
//		case 10:
//		case 9:
//			printf("优秀\n");
//			break;
//		case 8:
//			printf("良好\n");
//			break;
//		case 7:
//			printf("中等\n");
//			break;
//		case 6:
//			printf("及格\n");
//		default:
//			printf("不及格\n");
//			break;
//		
//	}
//	return 0;
//}
//
//int main()
//{
//	int score[50];
//	float average = 0;
//	int count = 0;
//	int sum = 0;
//	for (int i = 0;i < 50;++i)
//	{
//		scanf_s("%d ",&score[i]);
//		sum += score[i];
//	}
//	average = sum / 50.0;
//
//	
//	for (int i = 0;i < 50;++i)
//	{
//		if (score[i] < average)
//			count++;
//	}
//	printf("平均数为:%f\n低于平均数的人数为:%d",average,count);
//}
//void fun(char* head);
//int  main()
//{
//	char arr[] = "abcdef";
//	fun(arr);
//	printf("%s",arr);
//	return 0;
//	
//}
//void fun(char* head)
//{
//	char* tail=head;
//	
//	char tmp;
//	while ((*++tail != '\0'))
//	
//		;
//
//	tail--;
//	
//
//	while (head < tail)
//	{
//		tmp = *head;
//		*head = *tail;
//		*tail = tmp;
//		head++;
//		tail--;
//	}
//
//}
//
//int  palindromeStr(char nums[])
//{
//	int left = 0;
//	int sz = strlen(nums) - 1;
//	while (left < sz)
//	{
//		if (nums[left++] != nums[sz--])
//			return 0;
//	}
//	return 1;
//}

int mian()
{
	//选择
	int arr[] = { 3,8,2,9,10,47,21,1,78 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < sz - 1;++i)
	{
		for (int j = i + 1;j < sz;++j)
		{
			if (arr[i] > arr[j])
			{
				int tmp = arr[i];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	return 0;
}
int main()
{
	//冒泡
	int arr[] = { 3,8,2,9,10,47,21,1,78 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < sz;++i)
	{
		for (int j = 0;j < sz - i - 1;++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return 0;
}