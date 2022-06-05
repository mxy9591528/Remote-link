#include<iostream>
using namespace std;
bool judge(int  n)
{
	int count[10] = { 0 };
	int t_n = n * n;
	int num = 0;
	while (t_n)
	{
		count[t_n % 10]++;
		t_n /= 10;
		num++;
	}
	if (num != 7)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (count[i] > 1)
			return false;
	}
	return true;
}
int main()
{
	for (int i = 1000; i < 3335; i++)
	{
		if (judge(i))
			cout << i * i << endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
long long gbs(long long n, long long m)
{
	if (m > n) gbs(m, n);
	else
	{
		if (n%m == 0) return m;
		else return gbs(m, n%m);
	}
}
int main()
{
	long long m, n, g, y;
	printf("输入m和n ");
	scanf_s("%lld %lld", &m, &n);
	g = gbs(n, m);    //g代表最大公约数
	y = m * n / g;       //y代表最小公倍数
	printf("%lld", y);
	return 0;
}


#include<iostream>
using namespace std;
void stringconnection(char* str1, char* str2)
{
	int i = 0;
	int k = 0;
	while (str1[i] != '\0')
	{
		i++;
	}
	while (str2[k] != '\0')
	{
		k++;
	}
	k = 0;
	while (str2[k] != '\0')
	{
		str1[i] = str2[k];
		i++;
		k++;
	}
	str1[i] = '\0';
}
int main()
{
	char str1[20] = "birthday!";
	char str2[20] = "happy";
	stringconnection(str2, str1);
	cout << str2;
}

#include<iostream>
using namespace std;
class Point
{
public:
	Point(int x, int y)
	{
		this->m_x = x;
		this->m_y = y;
	}
	void move()
	{
		this->m_x += 3;
		this->m_y += 4;
		cout << "(" << this->m_x << "," << this->m_y << ")" << endl;
	}
private:
	int m_x;
	int m_y;
};
int main()
{
	Point p(3, 3);
	p.move();
	return 0;
}