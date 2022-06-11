#include<iostream>
using namespace std;
int main()
{
	char s[100];
	cin >> s;
	int len = strlen(s);
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = 0; j < len - i; j++)
			printf("%c", s[i]);
	}
	return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct sheep
{
	string name;
	int id;
	int count;
}s;

bool cmp(s a, s b) {
	return a.count > b.count;
}

int main()
{
	s s[3] = { {"Ï²ÑòÑò",1,0},{"ÀÁÑóÑó",2,0},{"ÃÀÑòÑò",3,0} };
	int n;
	char ret;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ret;
		cout << ret << endl;
		if (ret == '1') {
			s[0].count++;
		}
		if (ret == '2') {
			s[1].count++;
		}
		if (ret == '3') {
			s[2].count++;
		}
	}
	sort(s, s + 3, cmp);
	for (int i = 0; i < 3; i++)
	{
		cout << s[i].id << " " << s[i].name << " " << s[i].count << endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
bool isprime(int n)
{
	if (n == 2)
		return true;
	if (n == 1 || n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i++)
		if (n%i == 0)
			return false;
	return true;
}
int rsum(int n)
{
	int sum = 0, count = 1, ret = n;
	while (ret /= 10)
	{
		count++;
	}
	while (n)
	{
		sum += n % 10 * pow(10, --count);
		n /= 10;
	}
	return sum;
}
bool ispalindrome(int n)
{
	if (isprime(n))
	{
		if (n == rsum(n))
			return true;
	}
	return false;
}
int main()
{
	int limit, count = 0;
	cin >> limit;
	for (int i = 11; i <= limit; i++)
		if (ispalindrome(i))
			count++;
	cout << count;
	return 0;
}



#include <iostream>
using namespace std;
class array
{
private:
	float a[10], b[10];
public:
	array(float t[10]);
	void process();
	void print();
};
array::array(float t[10])
{
	for (int i = 0; i < 10; i++)
	{
		a[i] = t[i];
	}
}
void array::process()
{
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			b[0] = (a[9] + a[0] + a[1]) / 3;
		}
		else if (i == 9)
		{
			b[9] = (a[8] + a[9] + a[0]) / 3;
		}
		else
			b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
	}
}
void array::print()
{
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << '\t';
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << b[i] << '\t';
	}
	cout << endl;
}
int main()
{
	float m[10] = { 0,3,6,9,12,15,18,21,24,27 };
	array arr(m);
	arr.process();
	arr.print();


	system("pause");
	return 0;

}