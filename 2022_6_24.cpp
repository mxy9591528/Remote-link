#include<iostream>
using namespace std;
template<typename T1,class T2>
void Tswap(T1&x, T2&y)
{
	T1 ret = x;
	x =(T1)y;
	y = (T2)ret;
}
int main()
{
	int a = 10, b = 20;
	double c = 3.1415926, d = 2.7141;
	cout << "a=" << a << ",c=" << c << endl;
	Tswap(a, c);
	cout << "a=" << a << ",c=" << c << endl;
	cout << "b=" << b << ",d=" << d << endl;
	Tswap<int,double>(b, d);
	cout << "b=" << b << ",d=" << d << endl;
	return 0;
}

#include<iostream>
using namespace std;
template<typename T>
void TSort(T*a,int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
			if (a[min] > a[j])
				min = j;
		if (min != i)
		{
			T ret = a[min];
			a[min] = a[i];
			a[i] = ret;
		}
	}
}
template<typename T>
void PrintArray(T*a, int len)
{
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int a[] = { 3,4,7,1,2,8,9,10,4,6 };
	char c[] = "qwerttyuiop";
	TSort(a,sizeof(a)/sizeof(a[0]));
	TSort(c, sizeof(c) / sizeof(c[0])-1);//'\0'不能参与排序
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	PrintArray(c, sizeof(c) / sizeof(c[0]));//'\0'要打印出来
	return 0;
}

#include<iostream>
using namespace std;
void Print(int a, int b)
{
	cout << "调用普通函数" << endl;
}
template<typename T>
void Print(T a, T b)
{
	cout << "调用函数模板" << endl;
}
template<typename T>
void Print(T a, T b, T c)
{
	cout << "调用重载的函数模板" << endl;
}
int main()
{
	int a = 10, b = 10;
	char c1 = 'a', c2 = 'b';
	Print(a, b);//调用普通函数
	Print<>(a, b);//调用函数模板
	Print(a, b, 100);//调用重载的函数模板
	Print(c1, c2);//调用函数模板
	return 0;
}

#include<iostream>
using namespace std;
class Person
{
public:
	int age;
	int money;
};
template<typename T>
T Add(T&a, T&b)
{
	return a + b;
}
Person&operator+(Person&a,Person&b)
{
	Person*temp = new Person;
	temp->age = a.age+b.age;
	temp->money = a.money + b.money;
	return *temp;
}
template<typename T>
bool compare(T&a, T&b)
{
	return a == b;
}
template<> bool compare(Person&a, Person&b)
{
	return a.age == b.age&&a.money == b.money;
}
int main()
{
	Person p1 = { 12,1 }, p2 = { 12,1 }, p3;
	if (compare(p1, p2))
		cout << "p1==p2" << endl;
	else
		cout << "p1!=p2" << endl;
	p3 = Add(p1, p2);
	cout << "age=" << p3.age <<endl<<"money=" << p3.money << endl;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
template<typename Name,typename Age=int>
class Person
{
public:
	Name m_name;
	Age m_age;
	Person(Name name, Age age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	void show()
	{
		cout << this->m_name << " "<< this->m_age << "岁" << endl;
	}
};
int main()
{
	Person<string, int>p( "齐天大圣", 1000 );
	Person<string>q("艾伦*耶格尔", 20);
	p.show();
	q.show();
	return 0;
}

#include<iostream>
using namespace std;
class A
{
public:
	void showA()
	{
		cout << "this is class A" << endl;
	}
};
class B
{
public:
	void showB()
	{
		cout << "this is class B" << endl;
	}
};
template<typename T>
class C
{
public:
	T obj;
	void show1()
	{
		obj.showA();
	}
	void show2()
	{
		obj.showB();
	}
};
int main()
{
	C<A>c1;
	c1.show1();
	C<B>c2;
	c2.show2();
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
template<typename Name,typename Age>
class Person
{
public:
	Name m_name;
	Age m_age;
	Person(Name name, Age age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void showinfo()
	{
		cout << "姓名：" << this->m_name << " 年龄：" << this->m_age << endl;
	}
};

//第一种:指定传入类型
void fun1(Person<string, int>&p)
{
	p.showinfo();
}
//第二种:参数模板化
template<typename T1,typename T2>
void fun2(Person<T1, T2>&p)
{
	p.showinfo();
	cout << typeid(T1).name() << endl << typeid(T2).name() << endl;
}
//第三种:整个类模板化
template<typename T>
void fun3(T&p)
{
	p.showinfo();
	cout << typeid(T).name() << endl;
}
int main()
{
	Person<string, int>p("艾伦*耶格尔", 21);
	fun1(p);
	fun2(p);
	fun3(p);
	return 0;
}

#include<iostream>
using namespace std;
template<typename T>
class A
{
public:
	T m;
};
class B :public A<int>
{

};
template<typename T1,typename T2>
class C :public A<T1>
{
public:
	T2 obj;
	void showname()
	{
		cout << typeid(T1).name() << endl << typeid(T2).name() << endl;
	}
};
int main()
{
	B b;
	C<int, char>c;
	c.showname();
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
template<typename T1,typename T2>
class Person
{
public:
	T1 name;
	T2 age;
	Person(T1 name, T2 age);
	void showinfo();
};
template<typename T1,typename T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->age = age;
	this->name = name;
}
template<typename T1, typename T2>
void Person<T1,T2>::showinfo()
{
	cout<<"姓名:" << this->name << " 年龄:" << this->age << endl;
}
int main()
{
	Person<string,int>p("艾伦*耶格尔", 21);
	p.showinfo();
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
template<typename T1, typename T2>
class Person;
template<typename T1, typename T2>
void showinfo2(Person<T1, T2>&p)
{
	cout << "类外实现——姓名:" << p.m_name << " 年龄" << p.m_age<<endl;
}

template<typename T1,typename T2>
class Person
{
	friend void showinfo1(Person<T1,T2>&p)
	{
		cout << "类内实现——姓名:" << p.m_name << " 年龄" << p.m_age << endl;;
	}
	friend void showinfo2<>(Person<T1, T2>&p);
public:
	Person(T1 name, T2 age)
	{
		this->m_age = age;
		this->m_name = name;
	}
private:
	T1 m_name;
	T2 m_age;
};
int main()
{
	Person<string, int>p("艾伦*耶格尔", 21);
	showinfo1(p);
	showinfo2(p);
	return 0;
}

