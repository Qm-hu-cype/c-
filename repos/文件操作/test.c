#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt","wb");//w:д,b:������
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
//	folose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//int main()
//{
//
//	//���ļ�test.txt
//	// ���·��
//	// . ��ʾ��ǰĿ¼
//	// ..��ʾ��һ��Ŀ¼
//	// fopen("../test.txt","r");
//	//fopen("test.txt","wb");
//	
//	//���ļ�test.txt
//	//����·��
//	//fopen("D:\\Users\\Huqm\\source\\repos\\�ļ�����\\test.txt","r");
//	FILE* pf=fopen("text.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//�򿪳ɹ�
//	//���ļ�
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//
//	
//	//д�ļ�
//	/*fputc('b',pf);
//	fputc('i',pf);
//	fputc('t', pf);
//	fputc('!', pf);*/
//
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//�Ӽ�������
//�������Ļ
//����&��Ļ�����ⲿ�豸
//����-��׼�����豸
//��Ļ-��׼����豸
//��һ������Ĭ�ϴ򿪵������豸
//stdin(FILE*)��׼������-����
// stdout(FILE*)��׼�����-��Ļ
// stderr(FILE*)��׼������-��Ļ
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
//	//д�ļ�
//	fputc('b', pf);
//	fputc('i',pf);
//	fputc('t',pf);
//
//
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c",ch);
//	ch = fgetc(pf);
//	printf("%c",ch);
//	ch = fgetc(pf);
//	printf("%c",ch);
//
//	//�ر��ļ�
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
//	////���ļ�
//	//fgets(buf,1024,pf);
//	////printf("%s",buf);
//	//puts(buf);
//	//fgets(buf, 1024, pf);
//	////printf("%s", buf);
//	// puts(buf);
//	 
//	//д�ļ�
//	fputs("hello",pf);//û�л���
//	fputs("world\n", pf);//�л���
// 
//	//�ر��ļ�
//	fclose(pf);
//	pf=NULL;
//	return 0;
//}


//int main()
//{
//	//�Ӽ��̶�ȡһ���ļ���Ϣ
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ(����)
//	fputs(buf,stdout);//�������׼�����(��Ļ)
//
//
//	gets(buf);
//	puts(buf);
//
//	return 0;
//}



//��ʽ���ļ���д���� fscanf()��fprintf()

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
//	//��ʽ������ʽд�ļ�
//	fprintf(pf,"%d %f %s",s.n,s.score,s.arr);
//
//
//	��ʽ������������
//	(pf,"%d%f%s",&(s.n),&(s.score),(s.arr));
//	printf("%d %f %s", s.n, s.score, s.arr);
//
//	int f=fscanf(stdin, "%d %f %s", &(s.n), &(s.score), (s.arr));
//	fprintf(stdout,"%d %f %s",s.n,s.score,s.arr);
//	//printf("%d %f %s", s.n, s.score, s.arr);
//	//�ر��ļ�
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


//�����ƶ�д
struct S {
	char arr[10];
	int num;
	float sc;
};
int main()
{
	struct S s = { "abcdef",10,5.5f };
	//��������ʽд
	FILE* pf = fopen("test.txt","w");
	if (NULL == pf)
	{
		perror("fopen");
	}
	//д�ļ�
	fwrite(&s,sizeof(struct S),1,pf);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}