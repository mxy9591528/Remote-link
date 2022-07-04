#include<iostream>
#include<string>
using namespace std;
class Add
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
void test01()
{
	Add add;
	cout << add(10, 20) << endl;
}
class Print
{
public:
	void operator()(string str)
	{
		cout << str << endl;
		this->count++;
	}
	int count = 0;
};
void test02()
{
	Print print;
	print("Hello world!");
	print("Hello world!");
	print("Hello world!");
	cout << "print调用次数:" << print.count << endl;
}
void doPrint(Print&p, string str)
{
	p(str);
}
void test03()
{
	Print print;
	doPrint(print, "Hello world!");
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class mfive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	vector<int>::iterator i = find_if(v.begin(), v.end(), mfive());
	if (i == v.end())
		cout << "未找到" << endl;
	else cout << "找到了大于5的数字为:" << *i << endl;
}
class Cmp
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	sort(v.begin(), v.end());
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	cout << "---------------------------" << endl;
	sort(v.begin(), v.end(), Cmp());
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}
int main()
{
	//test01();
	test02();
}

#include<iostream>
#include<functional>
using namespace std;
void test01()
{
	negate<int>n;
	cout << n(50) << endl;
}
void test02()
{
	plus<int>p;
	cout << p(10, 20) << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
class cmp
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	//sort(v.begin(), v.end(), cmp());
	sort(v.begin(), v.end(), greater<int>());
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}
int main()
{
	test01();
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void test01()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	for (auto i : v1)
		cout << i << " ";
	cout << endl;
	vector<bool>v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (auto i : v2)
		cout << i << " ";
	cout << endl;

}
int main()
{
	test01();
	return 0;
}