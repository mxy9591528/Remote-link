#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Print(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	vTarget.resize(min(v1.size(), v2.size()));
	auto end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), end, Print);
	cout << endl;
}
void test02()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	auto end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), end, Print);
	cout << endl;
}
void test03()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	vTarget.resize(v1.size());
	auto end = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	cout << "v1与v2的差集:" << endl;
	for_each(vTarget.begin(), end, Print);
	cout << endl;
	vTarget.clear();
	vTarget.resize(v2.size());
	end = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	cout << "v2与v1的差集:" << endl;
	for_each(vTarget.begin(), end, Print);
	cout << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}