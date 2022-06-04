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
void stringConnection(char* str1, char* str2)
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
	char str1[20] = "Birthday!";
	char str2[20] = "Happy";
	stringConnection(str2, str1);
	cout << str2;
}
