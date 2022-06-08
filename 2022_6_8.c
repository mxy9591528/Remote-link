int fun(int x, int y)
{
	int max = x > y ? x : y, min = x < y ? x : y;
	int i, count = 0;
	for (i= min; i < max; i++)
	{
		if (i % 7 == 2)
			count++;
	}
	return count;
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int fun(int n)
{//求n的所有因数和
	int sum = 1, i;
	for (i = 2; i < n; i++)if (n%i == 0)sum = sum + i;
	return sum;
}
int jiecheng(int n)
{//求n的阶乘
	int num = 1, i;
	for (i = 2; i <= n; i++)num *= i;
	return num;
}

//错误的地方
int Prime(int n)
{//判断n是否为素数
	int i = 3;
	while (i <= sqrt(n))if (n%i++ == 0)return 0; //sqrt开平方
	return 1;
}

void wanquanshu(int n)
{//完全数 恰好等于自身的因子之和的数
	int i, count = 0;
	printf("完全数：\n");
	for (i = 0; i <= n; i++)
	{
		if (i == fun(i))
		{
			printf("%-5d", i);
			if (++count % 5 == 0)printf("\n");
		}
	}
	if (count % 5 != 0)printf("\n");
}
void qinmishu(int n)
{//亲密数 是两个正整数，每个全部因子之和等于对方
	int i, temp, count = 0;
	printf("亲密数：\n");
	for (i = 0; i <= n; i++)
	{
		temp = fun(i);
		if (temp > i&&i == fun(temp))
		{
			printf("(%d,%d)", i, temp);
			if (++count % 5 == 0)printf("\n");
		}
	}
	if (count % 5 != 0)printf("\n");
}
void shuixianhuashu(int n)
{//水仙花数 水仙花数是恰好等于自身各位数字立方和的数
	int i, m = 3, sum, count = 0, temp;
	printf("水仙花数：\n");
	for (i = 100; i <= n; i++)
	{
		if (999 < i&&i < 10000)m = 4;
		if (9999 < i&&i < 100000)m = 5;
		temp = i;
		sum = 0;
		while (temp)
		{
			sum += (int)pow(temp % 10, m);//pow x的y次方函数
			temp /= 10;
		}
		if (sum == i)
		{
			printf("%-5d", i);
			if (++count % 5 == 0)printf("\n");
		}
	}
	if (count % 5 != 0)printf("\n");
}
void jiechengheshu(int n)
{//阶乘和数 是恰好等于自身各位数字阶乘的和的数
	int i, count = 0, temp, sum;
	printf("阶乘和数：\n");
	for (i = 0; i <= n; i++)
	{
		sum = 0;
		if (i == 0)sum = jiecheng(i);
		else
		{
			temp = i;
			while (temp)
			{
				sum += jiecheng(temp % 10);
				temp /= 10;
			}
		}
		if (sum == i)
		{
			printf("%-5d", i);
			if (++count % 5 == 0)printf("\n");
		}
	}
	if (count % 5 != 0)printf("\n");
}
void zishoushu(int n)
{//自守数 是平方后尾部数字是自身的数
	int i, count = 0, temp, t;
	long num;
	printf("自守数：\n");
	for (i = 0; i <= n; i++)
	{
		num = i;
		t = 10;
		temp = i / 10;
		while (temp)
		{
			t = 10; //放大t10倍
			temp /= 10; //缩小temp10倍
		}
		if (num%t == i) //当余数和i相等时，输出i
		{
			printf("%-5d", i);
			if (++count % 5 == 0)printf("\n");
		}
	}
	if (count % 5 != 0)printf("\n");
}
void luanshengsushu(int n)
{//孪生素数 差2的两个素数
	int i, count = 0;
	printf("孪生素数：\n");
	for (i = 3; i <= n - 2; i += 2)
	{
		if (Prime(i) && Prime(i + 2))
		{
			printf("(%d,%d)", i, i + 2);
			if (++count % 5 == 0)printf("\n"); //每输出5对数字换行
		}
	}
	if (count % 5 != 0)printf("\n"); //最后一行不为5的整数个时换行
}
int main()
{
	int n, a;
	srand((unsigned)time(NULL));
	n = 1 + (int)(50000.0*rand() / (RAND_MAX + 1.0));
	printf("输入n:%d\n", n);
	printf("\n1.输出完全数\n2.输出亲密数\n3.输出水仙花数\n4.输出阶乘和数\n5.输出自守数\n6.输出孪生素数\n0.退出\n\n");
	for (;;)
	{
		printf("请输入选择:");
		scanf("%d", &a);
		switch (a)
		{
		case 0:exit(EXIT_SUCCESS);
		case 1:wanquanshu(n); break;
		case 2:qinmishu(n); break;
		case 3:shuixianhuashu(n); break;
		case 4:jiechengheshu(n); break;
		case 5:zishoushu(n); break;
		case 6:luanshengsushu(n); break;
		}
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char a[20];
	gets(a);
	_strlwr(a);
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] == ' ')
			printf("\n");
		else
			printf("%c", a[i]);
	}
	return 0;
}

#include<stdio.h>
struct Stu
{
	int id;
	char  name[10];
	char sex;
	int grade;
}s[7];
int main()
{
	int i;
	int msum = 0, fsum = 0, mfailed = 0, ffailed = 0, m = 0, f = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%d %s %c %d", &s[i].id, s[i].name, &s[i].sex, &s[i].grade);
		if (s[i].sex == 'm')
		{
			msum += s[i].grade;
			if (s[i].grade < 60)
				mfailed++;
			m++;

		}
		if (s[i].sex == 'f')
		{
			fsum += s[i].grade;
			if (s[i].grade < 60)
				ffailed++;
			f++;
		}
	}
	printf("男生平均分:%.3lf,不及格人数:%d\n", msum / (double)m, mfailed);
	printf("女生平均分:%.3lf,不及格人数:%d", fsum / (double)f, ffailed);
	return 0;
}

