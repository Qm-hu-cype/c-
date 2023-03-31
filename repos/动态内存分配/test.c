#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<windows.h>

//int main()
//{	//想内存申请10个整形的空间
//	int* p = (int*)malloc(10*sizeof(int));
//	if (p == NULL)
//	{
//		//打印错误原因的一个方式
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0;i < 10;i++) {
//			*(p + i) = i;
//		}
//		for (i = 0;i < 10;i++) {
//			printf("%d\n",*(p+i));
//		}
//	}//当动态内存申请的空间不在使用时 
//	//就应该还给操作系统
//	free(p);
//	p = NULL;
//	
//	system("pause");
//	return 0;
//}



//calloc :向堆区申请num个大小为size字节的内存空间,并将每个元素初始化为0




//realloc:调整动态开辟内存空间的大小

//int main()
//{
//	int* p = (int*)malloc(20);
//	if (p==NULL)
//	{
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0;i < 5;i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	//就是再使用malloc开辟的20个字节的空间
//	//假设这里,20个字节不能满足我们的使用
//	//希望我们能够有40个字节的空间
//	//这里可以使用realloc来调整动态开辟的内存
//	int *ptr=(int*)realloc(p,40);
//	if (ptr != NULL)
//	{
//		p = ptr;
//
//		for (int i = 0;i < 10;i++)
//		{
//			*(p + i) = i;
//		}
//		for (int i = 0;i < 10;i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//释放内存
//	free(p);
// p=NULL;
//	system("pause");
//	return 0;
//}

//
//int main()
//{
//	int* p = (int)malloc(40);
//	//万一malloc失败了,p就是NULL
//	*p = 0;//err
//	int i = 0;
//	for (i=0;i<10;i++)
//	{
//		*(p + i) = i;
//	}
//	system("pause");
//	return 0;
//}


//2.对动态内存开辟的越界访问
    
//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//	if(p==NULL)
//	{
//		return 0;
//	 }
//	else
//	{
//		int i = 0;
//		for (i=0;i<10;i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	system("pause");
//	return 0;
//}

//3.对非动态内存的free
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//	return 0;
//}


//int main()
//{
//	//realloc也可以实现malloc的功能
//	int *p=realloc(NULL,40);//等价与int *p=(int*)malloc(40)
//
//	return 0;
//}

//5.对同一内存的多次释放

//int main()
//{
//	int* p = (int*)melloc(40);
//	if(p=NULL)
//	{
//		return 0;
//	 }
//	//使用
//	//释放
//	free(p);
//	p = NULL;
//
//	free(p);
//	return 0;
//}
    
//6.动态开辟内存忘记释放
    /*	int main()
        {
            while (1)
            {
                malloc(40);
                Sleep(1000);
            }

            return 0;
        }*/




//void GetMemory(char* p)
//{
//    p = (char*)malloc(100);//内存泄漏
//
//}

/*
    str以值传递的形式传给p
    p是GetMemory函数的形参,只能在函数内部有效
    等GerMemory函数返回后动态内存尚未释放,并且无法释放,所以会造成内存泄漏

*/
//void  Test(void)
//{
//    char* str = NULL;
//    GetMemory(str);
//    strcpy(str, "hello world");//程序崩溃,访问空指针str
//    printf(str);
//
//}



//改正1.
//void GetMemory(char* *p)
//{
//    *p = (char*)malloc(100);
//
//}
//void  Test(void)
//{
//    char* str = NULL;
//    GetMemory(&str);
//    strcpy(str, "hello world");
//    printf(str);
//    free(str);
//    str = NULL;
//
//}
//
//int main()
//{
//    Test();
//    return 0;
//}

//修正2.
//char* GetMemory(char* p)
//{
//    p = (char*)malloc(100);
//
//}
//void  Test(void)
//{
//    char* str = NULL;
//   str= GetMemory(str);
//    strcpy(str, "hello world");
//    printf(str);
//    free(str);
//    str = NULL;
//
//}
//
//int main()
//{
//    Test();
//    return 0;
//}


//柔性数组:结构中最后一个元素允许是未知大小的数组,这就叫做<柔性数组>成员


//struct  S
//{
//    int n;
//    int arr[0];//未知大小的-柔性数组成员-数组大小是可以调整的
//
//};
//
//int main()
//{
//  // struct S s;
//    //printf("%d\n",sizeof(s));
//    struct S* ps = (struct S*)malloc(5 * sizeof(int) + (sizeof(struct S)));
//    ps->n = 100;
//    int i = 0;
//    for (i = 0;i < 5;i++)
//    {
//        ps->arr[i] = i;
//    }
//    struct S* ptr = realloc(ps, 44);
//    if (ptr != NULL)
//    {
//        ps = ptr;
//    }
//    for (i = 5;i < 10;i++)
//    {
//        ps->arr[i] = i;
//    }
//    free(ps);ps = NULL;
//    return 0;
//}


//第一种动态内存开辟方式
//struct S
//{
//    int n;
//    int* arr;
//
//};
//int main()
//{
//    struct S* ps = (struct S*)malloc(sizeof(struct S));
//    ps->n = 100;
//    ps->arr = (int *)malloc(5 * sizeof(int));
//    int i = 0;
//    for (i = 0;i < 5;i++)
//    {
//        ps->arr[i] = i;
//    }
//    for (i = 0;i < 5;i++)
//    {
//        printf("%d",ps->arr[i]);
//    }
//    //调整大小
//    int* ptr = realloc(ps->arr, 10 * sizeof(int));
//    if (ptr != NULL)
//    {
//        ps->arr = ptr;
//    }
//    for (i = 5;i < 10;i++)
//    {
//        ps->arr[i] = i;
//    }
//    for (i = 0;i < 10;i++)
//    {
//        printf("%d ",ps->arr[i]);
//
//    }
//    //释放内存
//    free(ps->arr);
//    ps->arr = NULL;
//    free(ps);
//    ps = NULL;
//    return 0;
//}


//第二种动态内存开辟
//struct S
//{
//    int n;
//    //char c;
//    int arr[0];
    //1. int arr[];//柔性数组成员
   // 2.int arr[0];//柔性数组成员

//};
//柔性数组的特点:

//结构中的柔性数组成员前面必须至少一个成员
//sizeof返回内存大小不包括柔性数组的大小
//包含柔性数组成员的结构体用malloc()函数进行内存的动态分配,并且分配的内存应该大于结构的大小,以适应柔性数组的预期
//大小

//int main()
//{
//    struct S s;
//    struct S* p = (struct S*)malloc(sizeof(s)+10*sizeof(int));
//    p->n = 100;
//    int i = 0;
//    for (i = 0;i < 10;i++)
//    {
//        p->arr[i] = i;
//    }
//    for (i = 0;i < 10;i++)
//    {
//        printf("%d ",p->arr[i]);
//    }
//    free(p);
//    p = NULL;
//   // printf("%d\n",sizeof(s));
//    system("pause");
//    return 0;
//}


//比较两种动态内存开辟方式,第二种的好处是:
                //1.方便内存释放
 //如果我们的代码实在一个给别人用的函数中,你在里面做了两次动态内存的开辟,并把整个结构体返回给用户.
 // 用户调用free可以释放结构体,但是用户并不知道这个结构体成员也需要free,所以你不能指望用户来发现这个事
 // 所以,如果我们把结构体的内存成员要的内存一次分配好了,并返回给用户一个结构体指针,用户做一次free就可以把所有的
 // 内存给释放掉
 //                
                //2.有利于访问速度(内存利用率较高)
//连续的内存有益于提高访问速度,也有益于减少内存碎片(还跑不了要做偏移量的加法来寻址)

int main()
{
    int n = 0;
    int m = 0;
    int arr1[100] = { 0 };
    int arr2[100] = { 0 };
    int arr3[100] = { 0 };
    scanf("%d %d", &n, &m);
    int i = 0;
    for (i = 0;i < n;i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0;i < m;i++)
    {
        scanf("%d", &arr2[i]);
    }
    //合并有序序列
    i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
            // printf("%d ",arr1[i]);
            // i++;
        }
        else {
            arr3[k++] = arr2[j++];
            //  printf("%d ",arr2[j]);
             // j++;
        }
    }
    if (i == n)
    {

        for (;j < m;j++)
        {
            arr3[k++] = arr2[j];
            // printf("%d ",arr2[j]);

        }
    }

    else
    {
        for (;i < n;i++)
        {
            arr3[k++] = arr1[i];
            //printf("%d ",arr1[i]);

        }
    }

    for (i = 0;i < k;i++)
    {
        printf("%d ", arr3[i]);
    }
    strcpy




    return 0;
}