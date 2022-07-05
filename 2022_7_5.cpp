#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	auto pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
		cout << "找到了:" << *pos << endl;
	else
		cout << "没找到" << endl;
}
class Person
{
public:
	string m_name;
	int m_age;
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	bool operator==(const Person&p)
	{
		if (this->m_age == p.m_age&&this->m_name == p.m_name)
			return true;
		else
			return false;
	}
};
void test02()
{
	vector<Person>v;
	Person p[4] = { {"a",11},{"b",22},{"c",33},{"d",44} };
	for (int i = 0; i < 4; i++)
		v.push_back(p[i]);
	auto pos = find(v.begin(), v.end(), p[1]);
	if (pos != v.end())
		cout << "找到了,姓名:" << pos->m_name << " 年龄:" << pos->m_age << endl;
	else
		cout << "没找到" << endl;
}
int main()
{
	test01();
	test02();
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Five
{
public:
	bool operator()(int n)
	{
		return n > 5;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	auto pos = find_if(v.begin(), v.end(), Five());
	if (pos != v.end())
		cout << "找到了:" << *pos << endl;
	else
		cout << "没找到" << endl;
}
class Person
{
public:
	string m_name;
	int m_age;
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
};
class Twenty
{
public:
	bool operator()(const Person&p)
	{
		return p.m_age > 20;
	}
};
void test02()
{
	vector<Person>v;
	Person p[4] = { {"aaa",10},{"bbb",20},{"ccc",30},{"ddd",40} };
	for (int i = 0; i < 4; i++)
		v.push_back(p[i]);
	auto pos = find_if(v.begin(), v.end(), Twenty());
	if (pos != v.end())
		cout << "找到了,姓名:" << pos->m_name << " 年龄:" << pos->m_age << endl;
	else
		cout << "没找到" << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void test01()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);
	auto pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
		cout << "为找到相邻元素" << endl;
	else
		cout << "找到相邻重复元素:" << *pos << endl;
}
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	bool ret = binary_search(v.begin(), v.end(), 7);
	if (ret)
		cout << "找到了" << endl;
	else
		cout << "没找到" << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void test01()
{
	vector<int>v;
	for (int i = 0; i <= 573; i++)
		v.push_back(i);
	v.push_back(33);
	v.push_back(33);
	v.push_back(7);
	int n1 = count(v.begin(), v.end(), 1),
		n2 = count(v.begin(), v.end(), 7),
		n3 = count(v.begin(), v.end(), 33);
	cout << "1的个数:" << n1 << endl
		<< "7的个数:" << n2 << endl
		<< "33的个数:" << n3 << endl;
}
class Person
{
public:
	int m_age;
	string m_name;
	Person(int age, string name)
	{
		this->m_age = age;
		this->m_name = name;
	}
	bool operator==(const Person&p)
	{
		return this->m_age == p.m_age;
	}
};
void test02()
{
	vector<Person>v;
	Person p[5] =
	{
	{10,"猪猪侠"},
	{10,"Tom and Jerry"},
	{10,"光头强"},
	{20,"星游记"},
	{30,"快乐星猫"}
	};
	for (int i = 0; i < 5; i++)
		v.push_back(p[i]);
	Person s(10, "喜羊羊");
	int num = count(v.begin(), v.end(), s);
	cout << "和喜羊羊同岁数的人员个数为:" << num << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Person
{
public:
	int m_age;
	string m_name;
	Person(int age, string name)
	{
		this->m_age = age;
		this->m_name = name;
	}
};
class cmp1
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
class cmp2
{
public:
	bool operator()(const Person&p)
	{
		return p.m_age > 10;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	int n1 = count_if(v.begin(), v.end(), cmp1());
	cout << "大于5的值的个数:" << n1;
	cout << endl;
	vector<Person>vp;
	Person p[5] =
	{
	{10,"猪猪侠"},
	{10,"Tom and Jerry"},
	{10,"光头强"},
	{20,"星游记"},
	{30,"快乐星猫"}
	};
	for (int i = 0; i < 5; i++)
		vp.push_back(p[i]);
	int n2 = count_if(vp.begin(), vp.end(), cmp2());
	cout << "年龄大于10的人员个数为:" << n2 << endl;
}
int main()
{
	test01();
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void Print(int val)
{
	cout << val << " ";
}
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
	for (int i = 0; i < 5; i++)
		v.push_back(i);
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), Print);
	cout << endl;
	sort(v.begin(), v.end(), cmp());
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}
#include<time.h>
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}
void test03()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i*i);
	}
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), Print);
}
void test04()
{
	vector<int>v;
	for (int i = 10; i < 100; i += 10)
		v.push_back(i);
	cout << "反转前:" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;
	cout << "反转后:" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}
int main()
{
	srand((unsigned int)time(NULL));
	//test01();
	//test02();
	//test03();
	test04();
}