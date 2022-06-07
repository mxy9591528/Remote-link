#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 3
struct mail {
	char name[10][n];
	int number[10];
}mai;

void input(struct mail *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个学生的姓名\n", i + 1);
		scanf("%s",p->name[i]);
		printf("请输入第%d个学生的号码\n", i + 1);
		scanf("%d", &p->number[i]);
	}
}

void search(struct mail *p, char name1[])
{
	int i, k;
	for (i = 0; i < n; i++)
	{
		if (strcmp(p->name[i], name1) == 0)
		{
			k = i;
			printf("%s\t%s\n", "name", "number");
			printf("%s\t%d\n", p->name[k], p->number[k]);
		}
		else if (*name1 == ' ' || *name1 == '\n')
		{
			printf("%s\t%s\n", "name", "number");
			for (i = 0; i < n; i++)
			{
				printf("%s\t%d\n", p->name[i], p->number[i]);
			}
		}
	}
}

int main()
{
	struct mail *s = malloc(sizeof(struct mail));
	input(s, 8);
	char name[10];
	scanf("%s",name);
	search(s, name);
}
#include<stdio.h>
#include<string.h>
int quest1(int n)
{
	if (n == 0)
		return 1;
	return n % 10 * quest1(n / 10);
}
int quest2(int n)
{
	if (n == 1 || n == 2)
		return n;
	else
		return quest2(n - 1) + quest2(n - 2);
}
void quest3(char*a1, char*a2)
{
	int len = strlen(a1);
	int ret = len;
	while (len--)
	{
		a2[ret - len - 1] = a1[len];
	}
	a2[ret] = '\0';
}
int main()
{
	int n, i, sum = 0;
	scanf("%d", &n);
	printf("%d\n", quest1(n));
	for (i = 1; i <= 15; i++)
	{
		printf("%d ", quest2(i));
		if (i % 5 == 0)
			printf("\n");
		sum += quest2(i);
	}
	printf("%d\n", sum);
	char a[15];
	quest3("hellow world!", a);
	printf("%s", a);
	return 0;
}

#include<stdio.h>
int fun(int*s,double*b)
{
	int sum = 0, i, count = 0;
	double ave;
	for (i = 0; i < 10; i++)
		sum += s[i];
	ave = sum / 10.0;
	for (i = 0; i < 10; i++)
	{
		if (s[i] < ave)
		{
			b[count++] = s[i];
		}
	}
	return count;
}
void main()

{

	float score[10], below[10]; int num; int i;

	for (i = 0; i < 10; i++)

		scanf("%f", &score[i]);

	num = fun(score, below);

	printf("%d:", num);

	for (i = 0; i < num; i++)

		printf("%.2f ", below[i]);

}
#include<stdio.h>
void quest3(char*a1, char*a2, int n)
{
	int len = n;
	int ret = n;
	while (len--)
	{
		a2[ret - len - 1] = a1[len];
	}
	a2[ret] = '\0';
}
int main()
{
	int n;
	char a[30];
	char key[30];
	printf("请输入字符串\n");
	scanf("%s", key);
	printf("请输入字符串的节点：\n");
	scanf("%d", &n);
	quest3(key, a, n);
	printf("%s", a);
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void fun(char*s, char*s1, char*s2)
{
	int len = strlen(s), i, j=0, k=0;
	for (i = 0; i < len; i++)
	{
		if (isdigit(s[i]))
			s1[j++] = s[i];
		if (isalpha(s[i]))
			s2[k++] = s[i];
	}
	s1[j] = '\0';
	s2[k] = '\0';
}
int main()
{
	char s1[20], s2[20], s[20];
	scanf("%s", s);
	fun(s,s1,s2);
	printf("%s\n%s", s1, s2);
	return 0;
}
