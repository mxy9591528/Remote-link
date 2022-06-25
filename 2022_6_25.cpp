#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Array
{
	T*base;
	int capacity;
	int size;
public:
	//构造函数
	Array(int n)
	{
		this->capacity = n;
		this->base = new T[this->capacity];
		this->size = 0;
	}
	//拷贝构造，注意深拷贝
	Array(const Array&a)
	{
		this->capacity = a.capacity;
		this->size = a.size;
		this->base = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->base[i] = a.base[i];
	}
	Array&operator=(const Array&a)
	{
		if (this->base)
		{
			delete[]this->base;
			this->base = NULL;
			this->capacity = 0;
			this->size = 0;
		}
		this->capacity = a.capacity;
		this->size = a.size;
		this->base = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->base[i] = a.base[i];
		return *this;
	}
	//尾插
	void Push_Back(const T&a)
	{
		if (this->capacity == this->size)
			return;
		this->base[this->size++] = a;
	}
	//尾删
	void Pop_Back()
	{
		if (this->size == 0)
			return;
		this->size--;
	}
	T&operator[](int index)
	{
		return this->base[index];
	}
	int Size()
	{
		return this->size;
	}
	int Capacity()
	{
		return this->capacity;
	}
	~Array()
	{
		if (this->base)
		{
			delete []base;
			base = NULL;
		}
	}
};
int main()
{
	Array<int>a(10);
	for (int i = 0; i < 10; i++)
		a.Push_Back(i);
	while (a.Size()>0)
	{
		cout << a[a.Size() - 1] << " ";
		a.Pop_Back();
	}
	cout << endl;
	Array<char>c(10);
	for (int i = 97; i < 107; i++)
		c.Push_Back(i);
	Array<char>cc(c);
	while (c.Size() > 0)
	{
		cout << c[c.Size() - 1] << " ";
		c.Pop_Back();
	}
	cout << endl;
	for (int i = 0; i < cc.Size(); i++)
		cout << cc[i] << " ";
	cout << endl;
}

#include<iostream>
#include<vector>//引用容器头文件
#include<algorithm>//算法头文件
using namespace std;
void Print(int n)
{
	cout << n << " ";
}
int main()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	//第一种遍历
	vector<int>::iterator begin = v.begin();
	vector<int>::iterator end = v.end();
	while (begin != end)
	{
		cout << *begin++ << " ";
	}
	cout << endl;
	//第二种遍历
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		cout << *i << " ";
	cout << endl;
	//第三种遍历
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Person
{
	friend int main();
	string name;
	int age;
public:
	Person(string name, int age)
	{
		this->age = age;
		this->name = name;
	}
};
int main()
{
	Person p[5] = { {"张三",10},{"李四",11},{"王五",12},{"赵六",13},{"钱七",14} };
	vector<Person>v1;
	vector<Person*>v2;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(p[i]);
		v2.push_back(&p[i]);
	}
	for (vector<Person>::iterator i = v1.begin(); i != v1.end(); i++)
		cout << "姓名:" << i->name << " 年龄:" << i->age << endl;
	for (vector<Person*>::iterator i = v2.begin(); i != v2.end(); i++)
		cout << "姓名:" << (*i)->name << " 年龄:" << (*i)->age << endl;
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v[5];
	vector<vector<int>>bv;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j <= 5; j++)
			v[i].push_back(i + j);
		bv.push_back(v[i]);
	}
	int count = 0;
	for (vector<vector<int>>::iterator i = bv.begin(); i != bv.end(); i++)
	{
		for (vector<int>::iterator j = v[count].begin(); j != v[count].end(); j++)
			cout << *j << " ";
		cout << endl;
		count++;
	}
	return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
using namespace std;
class student
{
public:
	int no()
	{
		return 2021 * 1000 + rand() % 900 + 100;
	}
	int age()
	{
		return rand() % 5 + 18;
	}
	string name()
	{
		string s[3] = { "张三","李四","王五" };
		return s[rand() % 3];
	}
	string gender()
	{
		string s[2] = {"男","女"};
		return s[rand() % 2];
	}
	string email()
	{
		char e[20];
		for (int i = 0; i < 20; i++)
		{
			e[i] = rand() % 30 + 97;
		}
		e[19] = '\0';
		e[10] = '@';
		return e;
	}
	long long phone()
	{
		return rand() % 90000000000 + 10000000000;
	}
	string address()
	{
		string s[3] = { "湖北","河南","天津" };
		return s[rand() % 3];
	}
	string clazz()
	{
		string s1 = "2021级", s2 = "班";
		s1.push_back(rand() % 10 + 1 + '0');
		return s1 + s2;
	}
};
int main()
{
	srand((unsigned int)time(NULL));
	student s;
	cout << s.age() << endl << s.clazz() << endl << s.email() << endl <<s.name()<<endl
		<< s.gender() << endl << s.no()<< endl << s.phone() << endl<<s.address();
}

#include<iostream>
#include<algorithm>
#include<time.h>
#include<string>
#include <iomanip>
using namespace std;
class student
{
public:
	void course()
	{
		float grade;
		string name[3] = { "数学","英语","C++" };
		for (int i = 0; i < 3; i++)
		{
			grade = (rand() % 9000 + 1000) / 100.0;
			cout << name[i] << " " <<fixed<< setprecision(2) << grade << endl;
		}
	}
};
int main()
{
	srand((unsigned int)time(NULL));
	student s;
	s.course();
	return 0;
}
