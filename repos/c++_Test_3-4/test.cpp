#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>


using namespace std;

int main()
{
	//字符数组的读取与输出
	//char str[100];
	//gets_s(str);  //可以读取空格,读取到回车(\r)结束
	//fgets(str,99,stdin);//可以读取空格
	// fgets()
	//cin >> str;//读取到空格结束
	//scanf("%s",str);//读取到空格结束
	//printf("%s",str);
	//cin.getline(str,10);
	//cout << str << endl;
	
	



	//字符串的读取与输出
	/*string str;
	getline(cin, str);
	cout << str;
	puts(str.c_str());
	
	printf("%s ", str.c_str());*/
	//string s1 = "abc", s2;
	//cout << s1.empty() << endl;//0    s1.empty--字符串判空,if空返回1(true),else返回0(false)
	//cout << s2.empty() << endl;//1
	//s1.size--求字符串的长度(时间复杂度(O(1)))


	//string s = "hello world";
	//加强for循环
	/*for (auto c : s)
	{
		cout << c<<endl;
	}*/

	//for (char & c : s)//引用, c是字符串的别名,因此改变c就改变了s
	//{
	//	c = 'a';

	//}
	//cout << s << endl;

	
	/*string s="123 yxc 321 1.123 fdjlsa jdflsa";
	int  a, b;
	string str;
	double c;
	stringstream ssin(s);
	ssin >> a>>str>> b>>c;
	cout << a << endl<<b<<endl<<c<<str<<endl;
	cout << str;*/




	



	return 0;
}