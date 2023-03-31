#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>//scanf printf 所需要的头文件
#include <iostream>//cin cout 
#include <cmath>
#include<algorithm>//swap(),reverse
#include <bits.h>//bits/stdc++.h  万能头文件
#include<string>
#include<cstring>
using namespace std;
int main()
{

	//int a, b,c,d;
	//cin >> a >> b>> c >> d;  // 输入
	//cout << "DIFERENCA=" << a*b-c*d << endl;	// 输出
	//printf("DIFERENCA=%d\n",a*b-c*d);
	//double score1, score2;
	//cin >> score1 >> score2;
	////cout << (score1 * 3.5 + score2 * 7.5) / 11 << endl;
	//double avger = (score1 * 3.5 + score2 * 7.5) / 11;
	//printf("MEDIA=%.5lf\n",avger);


	/*		钞票
	int n;
	cin >> n;
	cout << n << endl;
	printf("%d nota(s) R$ 100,00\n",n/100);
	n %= 100;
	printf("%d nota(s) R$ 50,00\n",n/50);
	n %= 50;
	printf("%d nota(s) R$ 20,00\n", n / 20);
	n %= 20;
	printf("%d nota(s) R$ 10,00\n", n / 10);
	n %= 10;
	printf("%d nota(s) R$ 5,00\n", n / 5);
	n %= 5;
	printf("%d nota(s) R$ 2,00\n", n / 2);
	n %= 2;
	printf("%d nota(s) R$ 1,00\n", n );
	*/
	/*
	两数求最大值
	max(a, b)=(a+b+abs(a-b))/2
	int a,b ,c;
	cin >> a >> b >> c;
	cout << ((a + b + abs(a - b)) / 2+c+abs((a + b + abs(a - b)) / 2 -c))/2<< endl;

	*/


	/*
		钞票和硬币(精度问题)
	double m;
	cin >> m;
	int n = (int)(m * 100);// (规避精度问题)
	printf("NOTAS\n");
	printf("%dnota(s)deR$ 100.00\n",n/10000);
	n %= 10000;
	printf("%dnota(s)deR$ 50.00\n", n / 5000);
	n %= 5000;
	printf("%dnota(s)deR$ 20.00\n", n / 2000);
	n %= 2000;
	printf("%dnota(s)deR$ 10.00\n", n / 1000);
	n %= 1000;
	printf("%dnota(s)deR$ 5.00\n", n / 500);
	n %= 500;
	printf("%dnota(s)deR$ 1.00\n", n / 100);
	n %= 100;
	printf("MOEDAS\n");
	printf("%dnota(s)deR$ 0.50\n", n / 50);
	n %= 50;
	printf("%dnota(s)deR$ 0.25\n", n / 25);
	n %= 25;
	printf("%dnota(s)deR$ 0.05\n", n /5);
	n %= 5;
	printf("%dnota(s)deR$ 0.01\n", n );

	*/

	/*

		天数转换
	int n;
	cin >> n;
	printf("年:%d\n",n/365);
	n %= 365;
	printf("月:%d\n", n / 30);
	n %= 30;
	printf("天:%d\n",n);
	*/

	/*

		零食
	int x, y;
	float money=0;//price
	cin >> x >> y;
	if (x == 1)money = 4.0;
	else if (x == 2)money = 4.5;
	else if (x == 3)money = 5.0;
	else if (x == 4)money = 2.0;
	else if (x == 5)money = 1.5;
	else cout << "编号有误!!!" << endl;


	printf("Total:R$%.2f",money*y);
	*/
	/*double a, b, c;
	cin >> a >> b >> c;
	if (a + b > c && a + c > b && b + c > a)

	{
		cout << "可以构成三角形,面积为:" << endl;

		cout << a + b + c;
	}

	else
	{
		cout << "以a,b为底c为高的梯形面积为:" << endl;
		cout << (a + b) * c / 2 << endl;
}
		*/
		/*int a, b;
		cin >> a >> b;
		if (b>a)cout << b-a << endl;
		else if (a == b)cout << "24" << endl;
		else cout << 24 - a + b << endl;*/
		/*float money = 0.0;
		cin >> money;
		if (money <= 400.0 && money > 0)printf("%.2f,涨薪幅度为15%%",money*1.15);
		else if (money > 400.0 && money <800.0)printf("%.2f,涨薪幅度为12%%", money * 1.12);
		else if (money <= 1200.0 && money > 800.0)printf("%.2f,涨薪幅度为10%%", money * 1.10);
		else if (money > 1200.0 && money <=2000.0)printf("%.2f,涨薪幅度为7%%", money * 1.07);
		else  printf("%.2f,涨薪幅度为4%%", money * 1.04);*/

		/*int a, b, c, d;
		cin >> a >> b >> c >> d;
		int stact = a * 60 + b;
		int end = c * 60 + d;
		int spent_time = end - stact;
		if (spent_time <= 0) spent_time += 1440;
		printf("时:%d 分:%d\n",spent_time/60,spent_time%60);*/

		/*
			三角形类型
		double a, b, c,tmp;
		cin >> a >> b >> c;
		if (a < b)
		{
			tmp = b;
			b = a;
			a = tmp;
			if (a < c)
			{
				tmp = a;
				a = c;
				c = tmp;

			}

		}
		else
		{
			if (a < c)
			{
				tmp=a;
				a = c;
				c = tmp;

			}

		}
		if (b < c)
		{
			tmp = c;
			c = b;
			b = tmp;
		}
		if (a >= b + c)
		{
			cout << "NAO TORMA TRLANGULO" << endl;
		}
		else
		{
			if (a*a == b * b + c * c)cout << "TRIAGULO RETAGULO" << endl;
			 if (a * a > b * b + c * c)cout << "TRIAGULO OBTUSANGULO" << endl;
			if (a * a < b * b + c * c)cout << "TRIAGULO ACUTANGULO" << endl;
			if (a == b && b == c) cout << "等边三角形" << endl;
			else if ((a == b && b != c) || (b == c && a != b)) cout << "等腰三角形" << endl;

		}
		*/

		/*
			税收
		double money;
		cin >> money;
		if (money <= 2000.0)cout << "lsento" << endl;
		else
		{
			if (money > 2000.0 && money <= 3000.0)cout << (money - 2000) * 0.08 << endl;
			else if (money > 3000.0 && money <= 4500.0) cout << 1000 * 0.08 + (money - 3000) * 0.18 << endl;
			else if (money > 4500.0 && money <= 5000.0) cout << 1000 * 0.08 + 1500 * 0.18 + (money - 4500) * 0.28 << endl;
		}
		*/
		/*float n1, n2, n3, n4,sum=0.0,avg=0;
		cin >> n1 >> n2 >> n3 >> n4;
		sum = n1 * 2 + n2 * 3 + n3 * 4 + n4;
		avg = sum / 10;
		printf("Media=%.1f",avg);
		if (avg >= 7.0) cout << "Aluno apronado" << endl;
		else if (avg < 5.0) cout << "Aluno reprovado" << endl;
		else if (avg >= 5.0 && avg <= 6.9)
		{
			int y;
			cin >> y;
			printf("Aluno aprovado\nNota do exame:%d",y);
			avg = (avg + y) / 2;
			if (avg >= 5.0) cout << "Aluno aprovado" << endl;
			else cout << "Aluno reprovado" << endl;
		}*/

		/*int a = 1, b = 1, c=1;
		int n;
		cin >> n;
		for (int i = 3;i <=n;++i)
		{
			c = a + b;
			a = b;
			b = c;
		}
		printf("F(%d)=%d\n",n,c);*/

		//int n;
		//cin >> n;
		//for (int i = 1;i <= n;i += 2)
		//{
		//	for (int j = n - 1;j >= i;--j )
		//	{
		//		printf(" ");
		//	}
		//	for (int j = 1;j <= i;++j)
		//	{
		//		printf("* ");
		//	}
		//	printf("\n");
		//	
		//}
		//for (int i = 1;i <n;i += 2)
		//{
		//	for (int j =0;j <= i;++j)
		//	{
		//		printf(" ");
		//	}
		//	for (int j = n - 2;j >= i;--j)
		//	{
		//		printf("* ");
		//	}
		//	printf("\n");
		//}
		/*
			  *
			* * *
		  * * * * *
		* * * * * * *
	  * * * * * * * * *
	* * * * * * * * * * *
	  * * * * * * * * *
		* * * * * * *
		  * * * * *
			* * *
			  *
		*/

		/*
			打印菱形
				曼哈顿距离--|x1-x2|+|y1-y2|
			int n;
			cin >> n;
			int cx = n / 2, cy = n / 2;
			for (int i = 0;i < n;++i)
			{
				for (int j = 0;j < n;++j)
				{
					if (abs(cx - i) + abs(cy - j) <= n / 2)
						cout << "*";
					else
						cout << " ";
				}
				cout << endl;
			}
		*/

		/*
			求最大数,并记录其位置
		int max_value;
		int position;
		for (int i = 0;i < 100;++i)
		{
			int value;
			cin >> value;
			if (value > max_value)
			{
				max_value = value;
				position = i + 1;
			}
		}
		cout << max_value <<endl<< position << endl;
		*/
		/*int x;
		while (true)
		{
			cin >> x;
			if (!x) break;
			for (int i = 1;i <= x;++i)
			{
				cout << i << " ";

			}
			cout << endl;
		}*/

		/*
			连续整数求和
		int a, n;
		cin >> a;
		int sum = a;
		while (cin >> n, n <= 0);
		for (int i = 1;i < n;++i)
		{
			sum += a + i;
		}
		cout << sum << endl;

		*/
		//int row, col;// 行,列
		//cin >> row >> col;
		//int k = 1;
		//for (int i = 1;i <= row;++i)
		//{
		//	for (int j = 1;j <= col-1;++j)
		//	{
		//		/*++k;
		//		if (j == col) cout << "PUM";
		//		else cout << k << " ";*/
		//		cout << k << " ";
		//		++k;
		//	}
		//	//printf("\n");
		//	cout << "PUM" << endl;
		//	++k;
		//}


		//输出x之后的六个奇数,如果x是奇数,x也在六个奇数中
		//int x;
		//cout << x;
		//if (x % 2==0)
		//{
		//	x++;
		//}
		//for (int i = 0;i < 6;++i)
		//{
		//	cout << x + i * 2 << endl;
		//}
	//int n;
	//cin >> n;
	//int c = 0, r = 0, f = 0;
	//
	//for (int i = 0;i <n;++i)
	//{
	//	char ret;
	//	int a;
	//	cin >> a>>ret;
	//	if (ret == 'C') c += a;
	//	else if (ret == 'R') r += a;
	//	else f += a;
	//}
	//int sum = c + r + f;
	//double c_b, r_b, f_b;
	//c_b = c *1.0/ sum;
	//r_b = r *1.0/ sum;
	//f_b = f *1.0/ sum;
	//printf("总数:%d\t其中兔子有%d只\t老鼠%d只\t青蛙%d只\t\n",sum,c,r,f);
	//printf("兔子占比%.2lf\t老鼠占比%.2lf\t青蛙占比%.2lf",c_b,r_b,f_b);
	//
	/*
		数字序列和他的和

	int n, m;
	while (cin >> n >> m, n > 0 && m > 0)
	{
		if (n > m) swap(n, m);
		int sum = 0;
		for (int i = n;i <= m;++i)
		{
			cout << i << " ";
			sum += i;
		}
		cout << "sum=" << sum << endl;
	}
	*/

	/*
		完全数
	int n;
	for (int i = 0;i < n;++i)
	{
		int ret;
		cin >> ret;
		int sum = 0;
		//优化
		for (int i = 1;i * i <= ret;++i)
		{
			if (ret %i == 0)
			{
				if (i < ret) sum += i;
				if (i != ret / i && ret / i < ret)	sum += ret / i;
			}
		}
	/*	for (int j = 1;j < ret;j++)
		{
			if(ret%j==0)
			sum += i;
		if (sum == ret) printf("%d is perfect\n", ret);
		else printf("%d is not perfect\n",ret);
		}*/
	/*
		旋转数组
	int arr[100];
	int n, k;
	cin >> n >> k;
	for (int i = 0;i < n;++i)
	{
		cin >> arr[i];
	}
	while (k--)
	{
		int t = arr[n - 1];
		for (int i = n - 2;i >= 0;--i)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = t;

	}
	for (int i = 0;i < n;++i)
	{
		cout << arr[i]<<" ";
	}
	*/
//法二:三步翻转法
/*
	1.反转整个数组
	2.反转前k个
	3.翻转后k个
int arr[100];
int n, k;
cin >> n >> k;
for (int i = 0;i < n;++i) cin >> arr[i];

reverse(arr, arr + n);
reverse(arr, arr + k);
reverse(arr + k, arr + n);
for (int i = 0;i < n;++i) cout << arr[i] << ' ';
*/

/*
	用数组计算a^x(高指数),long型也不够
	高精度2的n次方--妙

	const int N = 1000;
	int n;
	int a[N] = { 1 };
	cin >> n;
	int m = 1;
	for (int i = 0;i < n;i++)
	{
		int t = 0;//进位
		for (int j = 0;j < m;++j)
		{
			t += a[j] * 2;
			a[j] = t % 10;
			t /= 10;
		}
		if (t) a[m++] = 1;
	}
	for (int i = m - 1;i >= 0;i--)
	{
		cout << a[i];

	}
	cout << endl;
	*/
//memset(数组名,要初始化的值,初始化的大小(单位:字节))//把每个Byte赋值(1Byte=8bit),不是把每个数赋值
//memset(a,0,sizeof(a));\
//memcpy(b,a,sizeof(a));//把a中sizeof(a)字节复制到目标数组b中



/*
	数组替换
	
int a[10];
for (int i = 0;i < 10;++i)
{
	cin >> a[i];
	if (a[i] < 0) a[i] = 1;
	printf("X[%d]=%d\n",i,a[i]);
}

*/
/*
	738.数组填充
	int v;
	cin >> v;
	int a[10];
	a[0] = v;
	printf("N[%d]=%d\n",0,a[0]);
	for (int i = 1;i < 10;++i)
	{
		//a[i] = v<<i;
		a[i] = a[i - 1] * 2;
		printf("N[%d]=%d\n",i,a[i]);
}
*/


/*
	数组选择
float  a[100];
for (int i = 0;i < 100;++i)
{
	cin >> a[i];
	if (a[i] <= 10) printf("A[%d]=%.1f\n",i,a[i]);
}
*/
/*
	数组中的行(求二维数组特定行元素的和与平均值)
double arr[12][12];
int L;
cin >> L;
double sum = 0;
double avg;
char ret;
cin >> ret;
for (int i = 0;i < 12;++i)
{
	for (int j = 0;j < 12;++j)
	{
		cin >> arr[i][j];
	}
}
for (int j = 0;j < 12;++J)
{
	sum += arr[L][j];
	
}
avg = sum / 12;
if (ret == 'S')printf("%.1lf\n", sum);
else printf("%.1lf\n",avg);
*/

/*
	数组右上部分求和

double a[12][12];
double sum = 0;
double avg;
int count = 0;
for (int i = 0;i < 12;++i)
{
	for (int j = 0;j < 12;++j)
	{
		cin >> a[i][j];
		if (j > i)
		{
		sum += a[i][j];
		++count;
		}
	}
}
avg = sum / count;
printf("%sum=.1lf,avg=%.1lf\n",sum,avg);
*/

/*
	数组左上部分求和
double a[12][12];
double sum = 0;
double avg;
int count = 0;
for (int i = 0;i < 12;++i)
{
	for (int j = 0;j < 12;++j)
	{
		cin >> a[i][j];
		if (i+j<=10)
		{
			sum += a[i][j];
			++count;
		}
	}
}
*/
/*
	数组对角线的四分之一区域(上方)
	* * * * * * * * * *
	* * * * * * * *
	* * * * * *
	* * * *
	* *

	double a[12][12];
	char t;
	cin >> t;
	for (int i = 0;i < 12;++i)
	{
		for (int j = 0;j < 12;++j)
		{
			cin >> a[i][j];
		}
	}
	double s = 0;
	double c = 0;

	for (int i = 0;i < 5;++i) {

		for (int j = i + 1;j <= 10 - i;)
		{
			s += a[i][j];
			++c;
		}
	}

	for (int i = 0;i < 5;++i)
	{
		for (int j = i + 1;j <= 10 - i;++j)
		{
			printf("* ");
		}
		printf("\n");
	}
	*/


/*
	字符串
*/
int s[100];//字符数组
//scanf("%s", s + 1);// 从下标为1的开始读取,读到空格会结束
//cin >> s + 2;读到空格会结束
//fgets(s,最大读取数,流(stdin))
//cin.getline(s, 100);
//puts()自带换行符
//字符串
string arr;
//getline(cin, arr);//读取字符串
char s1[]= "abcde";
char s2[] = "abcdg";
//strlen();求字符串长度不包括'\0'
int ret=strcmp(s1, s2);//字符串比较s1=s2,返回0,s1<s2返回-1,s1>s2返回1
cout << ret;
















	return 0;
}

