#include <stdio.h>


//#define MAX 1000 //���Ա������
//
//typedef  struct staffAndWorkers  //һ��ְ��,�ṹ����������д
//{
//	int id; //ְ�����
//	double salary;//ְ������,���ֿ�����
//
//}SAW; //ʹ��typedef ��һ��ְ������������ΪSAW
//
//int main()
//{
//	SAW saws[MAX]; //�����ṹ������,��Ŷ���ְ����Ϣ
//
//	//1.����ְ����Ϣ
//	int count = 0;//��ְԱ������
//	while (~scanf_s("%d %lf", &saws[count++].id, &saws[count++].salary));
//
//	count -= 2; //��while()��,count��ֵ�����2
//
//	//2.�����ʽ�������(ð��)����
//	for (int i = 0;i < count;++i)
//	{
//		for (int j =0;j < count-i-1;++j)
//		{
//			if (saws[j].salary < saws[j + 1].salary)
//			{
//				double t = saws[j].salary;
//				//����
//				saws[j].salary = saws[j + 1].salary;
//				saws[j + 1].salary = t;
//				//��������ͬʱ����ְ�����
//				int tmp = saws[j].id;
//				saws[j].id = saws[j + 1].id;
//				saws[j + 1].id = tmp;
//
//			}
//		}
//	}
//
//	//3.��ӡ���
//	for (int i = 0;i < count;++i)
//	{
//		printf("Ա�����:%d ����%lf\n",saws[i].id,saws[i].salary);
//	}
//
//
//
//	return 0;
//}


#define ROW 7
#define COL 50

int main(int argc, char** argv)
{
    /*char feature[ROW][COL] = {
        "1. ���Լ�࣬ʹ�÷������",
        "2. ����ֲ�Ժ�",
        "3. �������ǿ",
        "4. ��﷽ʽ���",
        "5. �ɽ��нṹ���������",
        "6. ����ֱ�Ӳ��������Ӳ��",
        "7. ���ɵ�Ŀ�����������" };

    printf("********** C�����ص� **********\n");
    int i = 0;
    while (i < ROW) {
        printf("%s\n",feature[i++]);
   }

    printf("*******************************\n");
    printf("�ڶ��ִ�ӡ����\n");
    for (int i = 0;i < ROW;++i)
    {
        for (int j = 0;feature[i][j] != '\0';++j)
        {
            printf("%c",feature[i][j]);
        }
        printf("\n");
    }
    printf("�����ִ�ӡ����\n");
    for (int i = 0;i < ROW;++i)
        printf("%s\n",feature[i]);*/
    char ch = getchar();
    if (ch >= 'A' && ch <= 'Z')
        putchar(ch + 32);
    return 0;
}