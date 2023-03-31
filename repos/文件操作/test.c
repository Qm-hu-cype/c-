#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt","wb");//w:写,b:二进制
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//	folose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//int main()
//{
//
//	//打开文件test.txt
//	// 相对路径
//	// . 表示当前目录
//	// ..表示上一级目录
//	// fopen("../test.txt","r");
//	//fopen("test.txt","wb");
//	
//	//打开文件test.txt
//	//绝对路径
//	//fopen("D:\\Users\\Huqm\\source\\repos\\文件操作\\test.txt","r");
//	FILE* pf=fopen("text.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//打开成功
//	//读文件
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//
//	
//	//写文件
//	/*fputc('b',pf);
//	fputc('i',pf);
//	fputc('t', pf);
//	fputc('!', pf);*/
//
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//从键盘输入
//输出到屏幕
//键盘&屏幕都是外部设备
//键盘-标准输入设备
//屏幕-标准输出设备
//是一个程序默认打开的两个设备
//stdin(FILE*)标准输入流-键盘
// stdout(FILE*)标准输出流-屏幕
// stderr(FILE*)标准错误流-屏幕
// 
//
//int main()
//{
//	int ch = fgetc(stdin);
//	fputc(ch,stdout);
//	return 0;
//
//
//}


//int main()
//{
//	FILE* pf=fopen("test.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputc('b', pf);
//	fputc('i',pf);
//	fputc('t',pf);
//
//
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c",ch);
//	ch = fgetc(pf);
//	printf("%c",ch);
//	ch = fgetc(pf);
//	printf("%c",ch);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char buf[1024];
//	FILE* pf = fopen("test.txt","w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	////读文件
//	//fgets(buf,1024,pf);
//	////printf("%s",buf);
//	//puts(buf);
//	//fgets(buf, 1024, pf);
//	////printf("%s", buf);
//	// puts(buf);
//	 
//	//写文件
//	fputs("hello",pf);//没有换行
//	fputs("world\n", pf);//有换行
// 
//	//关闭文件
//	fclose(pf);
//	pf=NULL;
//	return 0;
//}


//int main()
//{
//	//从键盘读取一行文件信息
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);//从标准输入流读取(键盘)
//	fputs(buf,stdout);//输出到标准输出流(屏幕)
//
//
//	gets(buf);
//	puts(buf);
//
//	return 0;
//}



//格式化文件读写函数 fscanf()和fprintf()

//struct S
//{
//	int n ;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//格式化的形式写文件
//	fprintf(pf,"%d %f %s",s.n,s.score,s.arr);
//
//
//	格式化的输入数据
//	(pf,"%d%f%s",&(s.n),&(s.score),(s.arr));
//	printf("%d %f %s", s.n, s.score, s.arr);
//
//	int f=fscanf(stdin, "%d %f %s", &(s.n), &(s.score), (s.arr));
//	fprintf(stdout,"%d %f %s",s.n,s.score,s.arr);
//	//printf("%d %f %s", s.n, s.score, s.arr);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//struct  S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 10,3.14f,"abcdef" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//	sprintf(buf,"%d %f %s",s.n,s.score,s.arr);
//
//	//printf("%s\n",buf);
//	int f=sscanf(buf,"%d %f %s",&(tmp.n),&(tmp.score),tmp.arr);
//	printf("%d %f %s",tmp.n,tmp.score,tmp.arr);
//	return 0;
//}


//二进制读写
struct S {
	char arr[10];
	int num;
	float sc;
};
int main()
{
	struct S s = { "abcdef",10,5.5f };
	//二进制形式写
	FILE* pf = fopen("test.txt","w");
	if (NULL == pf)
	{
		perror("fopen");
	}
	//写文件
	fwrite(&s,sizeof(struct S),1,pf);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}