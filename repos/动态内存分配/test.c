#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<windows.h>

//int main()
//{	//���ڴ�����10�����εĿռ�
//	int* p = (int*)malloc(10*sizeof(int));
//	if (p == NULL)
//	{
//		//��ӡ����ԭ���һ����ʽ
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
//		int i = 0;
//		for (i = 0;i < 10;i++) {
//			*(p + i) = i;
//		}
//		for (i = 0;i < 10;i++) {
//			printf("%d\n",*(p+i));
//		}
//	}//����̬�ڴ�����Ŀռ䲻��ʹ��ʱ 
//	//��Ӧ�û�������ϵͳ
//	free(p);
//	p = NULL;
//	
//	system("pause");
//	return 0;
//}



//calloc :���������num����СΪsize�ֽڵ��ڴ�ռ�,����ÿ��Ԫ�س�ʼ��Ϊ0




//realloc:������̬�����ڴ�ռ�Ĵ�С

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
//	//������ʹ��malloc���ٵ�20���ֽڵĿռ�
//	//��������,20���ֽڲ����������ǵ�ʹ��
//	//ϣ�������ܹ���40���ֽڵĿռ�
//	//�������ʹ��realloc��������̬���ٵ��ڴ�
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
//	//�ͷ��ڴ�
//	free(p);
// p=NULL;
//	system("pause");
//	return 0;
//}

//
//int main()
//{
//	int* p = (int)malloc(40);
//	//��һmallocʧ����,p����NULL
//	*p = 0;//err
//	int i = 0;
//	for (i=0;i<10;i++)
//	{
//		*(p + i) = i;
//	}
//	system("pause");
//	return 0;
//}


//2.�Զ�̬�ڴ濪�ٵ�Խ�����
    
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

//3.�ԷǶ�̬�ڴ��free
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//	return 0;
//}


//int main()
//{
//	//reallocҲ����ʵ��malloc�Ĺ���
//	int *p=realloc(NULL,40);//�ȼ���int *p=(int*)malloc(40)
//
//	return 0;
//}

//5.��ͬһ�ڴ�Ķ���ͷ�

//int main()
//{
//	int* p = (int*)melloc(40);
//	if(p=NULL)
//	{
//		return 0;
//	 }
//	//ʹ��
//	//�ͷ�
//	free(p);
//	p = NULL;
//
//	free(p);
//	return 0;
//}
    
//6.��̬�����ڴ������ͷ�
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
//    p = (char*)malloc(100);//�ڴ�й©
//
//}

/*
    str��ֵ���ݵ���ʽ����p
    p��GetMemory�������β�,ֻ���ں����ڲ���Ч
    ��GerMemory�������غ�̬�ڴ���δ�ͷ�,�����޷��ͷ�,���Ի�����ڴ�й©

*/
//void  Test(void)
//{
//    char* str = NULL;
//    GetMemory(str);
//    strcpy(str, "hello world");//�������,���ʿ�ָ��str
//    printf(str);
//
//}



//����1.
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

//����2.
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


//��������:�ṹ�����һ��Ԫ��������δ֪��С������,��ͽ���<��������>��Ա


//struct  S
//{
//    int n;
//    int arr[0];//δ֪��С��-���������Ա-�����С�ǿ��Ե�����
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


//��һ�ֶ�̬�ڴ濪�ٷ�ʽ
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
//    //������С
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
//    //�ͷ��ڴ�
//    free(ps->arr);
//    ps->arr = NULL;
//    free(ps);
//    ps = NULL;
//    return 0;
//}


//�ڶ��ֶ�̬�ڴ濪��
//struct S
//{
//    int n;
//    //char c;
//    int arr[0];
    //1. int arr[];//���������Ա
   // 2.int arr[0];//���������Ա

//};
//����������ص�:

//�ṹ�е����������Աǰ���������һ����Ա
//sizeof�����ڴ��С��������������Ĵ�С
//�������������Ա�Ľṹ����malloc()���������ڴ�Ķ�̬����,���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С,����Ӧ���������Ԥ��
//��С

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


//�Ƚ����ֶ�̬�ڴ濪�ٷ�ʽ,�ڶ��ֵĺô���:
                //1.�����ڴ��ͷ�
 //������ǵĴ���ʵ��һ���������õĺ�����,���������������ζ�̬�ڴ�Ŀ���,���������ṹ�巵�ظ��û�.
 // �û�����free�����ͷŽṹ��,�����û�����֪������ṹ���ԱҲ��Ҫfree,�����㲻��ָ���û������������
 // ����,������ǰѽṹ����ڴ��ԱҪ���ڴ�һ�η������,�����ظ��û�һ���ṹ��ָ��,�û���һ��free�Ϳ��԰����е�
 // �ڴ���ͷŵ�
 //                
                //2.�����ڷ����ٶ�(�ڴ������ʽϸ�)
//�������ڴ���������߷����ٶ�,Ҳ�����ڼ����ڴ���Ƭ(���ܲ���Ҫ��ƫ�����ļӷ���Ѱַ)

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
    //�ϲ���������
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