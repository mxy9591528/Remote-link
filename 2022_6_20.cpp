#include<iostream>
using namespace std;
int a, b, c;
const int i = 1, j = 2;
static int k = 3, l = 4;
int main()
{
	int b, e, f;
	const int g = 1, h = 2;
	cout << "ȫ�ֱ�����ַ:\n" << &a << endl
		<< &b << endl
		<< &c << endl;
	cout << "ȫ��const���γ�����ַ:\n" << &i << endl
		<< &j << endl;
	cout << "static��̬������ַ:\n" << &k <<
		endl << &l << endl;
	cout << "�ֲ�������ַ:\n" << &b << endl
		<< &e << endl
		<< &f << endl;
	cout << "�ֲ�const���γ�����ַ:\n" << &g <<
		endl << &h << endl;
	return 0;
}

#include<iostream>
using namespace std;
void swap(int&a, int &b)
{
	int ret = a;
	a = b;
	b = ret;
}
int&test()
{
	int a = 100;
	return a;
}
int main()
{
	int a = 10, b = 20, c = 30;
	int &d = a;
	cout << "d=" << d << endl;
	a = 11;
	cout << "d=" << d << endl;
	d = 12;
	cout << "a=" << a << endl;

	cout << "b=" << b << endl << "c=" << c << endl;
	swap(b, c);
	cout << "b=" << b << endl << "c=" << c << endl;

	int&f = test();
	cout << "f=" << f << endl;
	cout << "f=" << f << endl;
}

#include<iostream>
using namespace std;
void fun1(int a = 1, int b = 2, int c = 3)
{
	cout << a + b + c << endl;
}
void fun2(int a, int)
{
	cout << "this is a function a=" << a << endl;
}
void fun3(int a, int b);
void fun4(int a = 10, int b = 10);
int main()
{
	fun1();
	fun1(10);
	fun1(10, 20);
	fun2(999, 1);
	fun3(1, 2);
	fun4();
	return 0;
}
void fun3(int a = 10, int b = 10)
{
	cout << a + b << endl;
}
void fun4(int a, int b)
{
	cout << a + b << endl;
}

#include<iostream>
using namespace std;
void fun(int a, double b = 10)
{
	cout << "fun(int a,double b=10)" << endl;
}void fun(double a, int b = 10)
{
	cout << "fun(double a, int b=10)" << endl;
}


void fun(char&a)
{
	cout << "fun(char&a)" << endl;
}
void fun(const char&a)
{
	cout << "fun(const char&a)" << endl;
}

int main()
{
	fun(1);
	fun(1.1);
	fun(1, 2.0);
	fun(3.14, 1);
	char a = 'c';
	fun('c');
	fun(a);
	return 0;
}
