//#include<stdio.h>
//#include<math.h>
//int GetMax(int x, int y)
//{
//	return x > y ? x : y;
//}
//void Print(int n)
//{
//	while (n--)
//	{
//		printf("*");
//	}
//	printf("\n");
//}
//double Getsquare(double a, double b, double c)
//{
//	if (a + b > c&&b + c > a&&a + c > b)
//	{
//		double p = (a + b + c) / 2;
//		return sqrt(p*(p - a)*(p - b)*(p - c));
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int x, y, n;
//	double a, b, c, s;
//	printf("请输入两个值\n");
//	scanf("%d %d", &x, &y);
//	printf("最大值为:%d\n", GetMax(x, y));
//	printf("请输入打印数量\n");
//	scanf("%d", &n);
//	Print(n);
//	printf("请输入三角形的三边:\n");
//	scanf("%lf %lf %lf", &a, &b, &c);
//	s = Getsquare(a, b, c);
//	if (s)
//		printf("%lf\n", s);
//	else
//		printf("输入不合法\n");
//}
 
 
#include <stdio.h>
int primer(int n)
{
    int i;
    if (n == 1)
        return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int m, n, i;
    scanf("%d %d", &m, &n);
    for (i = m; i <= n; i++)
        if (primer(i))
            printf("%d ", i);
    return 0;
}
