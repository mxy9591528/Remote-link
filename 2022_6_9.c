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
//	printf("����������ֵ\n");
//	scanf("%d %d", &x, &y);
//	printf("���ֵΪ:%d\n", GetMax(x, y));
//	printf("�������ӡ����\n");
//	scanf("%d", &n);
//	Print(n);
//	printf("�����������ε�����:\n");
//	scanf("%lf %lf %lf", &a, &b, &c);
//	s = Getsquare(a, b, c);
//	if (s)
//		printf("%lf\n", s);
//	else
//		printf("���벻�Ϸ�\n");
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
