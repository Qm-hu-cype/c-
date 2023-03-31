#include <stdio.h>


//#define MAX 1000 //最大员工数量
//
//typedef  struct staffAndWorkers  //一个职工,结构体名可任意写
//{
//	int id; //职工序号
//	double salary;//职工工资,名字可任意
//
//}SAW; //使用typedef 将一个职工变量重命名为SAW
//
//int main()
//{
//	SAW saws[MAX]; //创建结构体数组,存放多名职工信息
//
//	//1.输入职工信息
//	int count = 0;//在职员工数量
//	while (~scanf_s("%d %lf", &saws[count++].id, &saws[count++].salary));
//
//	count -= 2; //在while()中,count的值多加了2
//
//	//2.按工资进行排序(冒泡)降序
//	for (int i = 0;i < count;++i)
//	{
//		for (int j =0;j < count-i-1;++j)
//		{
//			if (saws[j].salary < saws[j + 1].salary)
//			{
//				double t = saws[j].salary;
//				//交换
//				saws[j].salary = saws[j + 1].salary;
//				saws[j + 1].salary = t;
//				//交换工资同时交换职工序号
//				int tmp = saws[j].id;
//				saws[j].id = saws[j + 1].id;
//				saws[j + 1].id = tmp;
//
//			}
//		}
//	}
//
//	//3.打印输出
//	for (int i = 0;i < count;++i)
//	{
//		printf("员工序号:%d 工资%lf\n",saws[i].id,saws[i].salary);
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
        "1. 语言简洁，使用方便灵活",
        "2. 可移植性好",
        "3. 表达能力强",
        "4. 表达方式灵活",
        "5. 可进行结构化程序设计",
        "6. 可以直接操作计算机硬件",
        "7. 生成的目标代码质量高" };

    printf("********** C语言特点 **********\n");
    int i = 0;
    while (i < ROW) {
        printf("%s\n",feature[i++]);
   }

    printf("*******************************\n");
    printf("第二种打印方法\n");
    for (int i = 0;i < ROW;++i)
    {
        for (int j = 0;feature[i][j] != '\0';++j)
        {
            printf("%c",feature[i][j]);
        }
        printf("\n");
    }
    printf("第三种打印方法\n");
    for (int i = 0;i < ROW;++i)
        printf("%s\n",feature[i]);*/
    char ch = getchar();
    if (ch >= 'A' && ch <= 'Z')
        putchar(ch + 32);
    return 0;
}