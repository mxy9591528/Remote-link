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
{//��n������������
	int sum = 1, i;
	for (i = 2; i < n; i++)if (n%i == 0)sum = sum + i;
	return sum;
}
int jiecheng(int n)
{//��n�Ľ׳�
	int num = 1, i;
	for (i = 2; i <= n; i++)num *= i;
	return num;
}

//����ĵط�
int Prime(int n)
{//�ж�n�Ƿ�Ϊ����
	int i = 3;
	while (i <= sqrt(n))if (n%i++ == 0)return 0; //sqrt��ƽ��
	return 1;
}

void wanquanshu(int n)
{//��ȫ�� ǡ�õ������������֮�͵���
	int i, count = 0;
	printf("��ȫ����\n");
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
{//������ ��������������ÿ��ȫ������֮�͵��ڶԷ�
	int i, temp, count = 0;
	printf("��������\n");
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
{//ˮ�ɻ��� ˮ�ɻ�����ǡ�õ��������λ���������͵���
	int i, m = 3, sum, count = 0, temp;
	printf("ˮ�ɻ�����\n");
	for (i = 100; i <= n; i++)
	{
		if (999 < i&&i < 10000)m = 4;
		if (9999 < i&&i < 100000)m = 5;
		temp = i;
		sum = 0;
		while (temp)
		{
			sum += (int)pow(temp % 10, m);//pow x��y�η�����
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
{//�׳˺��� ��ǡ�õ��������λ���ֽ׳˵ĺ͵���
	int i, count = 0, temp, sum;
	printf("�׳˺�����\n");
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
{//������ ��ƽ����β���������������
	int i, count = 0, temp, t;
	long num;
	printf("��������\n");
	for (i = 0; i <= n; i++)
	{
		num = i;
		t = 10;
		temp = i / 10;
		while (temp)
		{
			t = 10; //�Ŵ�t10��
			temp /= 10; //��Сtemp10��
		}
		if (num%t == i) //��������i���ʱ�����i
		{
			printf("%-5d", i);
			if (++count % 5 == 0)printf("\n");
		}
	}
	if (count % 5 != 0)printf("\n");
}
void luanshengsushu(int n)
{//�������� ��2����������
	int i, count = 0;
	printf("����������\n");
	for (i = 3; i <= n - 2; i += 2)
	{
		if (Prime(i) && Prime(i + 2))
		{
			printf("(%d,%d)", i, i + 2);
			if (++count % 5 == 0)printf("\n"); //ÿ���5�����ֻ���
		}
	}
	if (count % 5 != 0)printf("\n"); //���һ�в�Ϊ5��������ʱ����
}
int main()
{
	int n, a;
	srand((unsigned)time(NULL));
	n = 1 + (int)(50000.0*rand() / (RAND_MAX + 1.0));
	printf("����n:%d\n", n);
	printf("\n1.�����ȫ��\n2.���������\n3.���ˮ�ɻ���\n4.����׳˺���\n5.���������\n6.�����������\n0.�˳�\n\n");
	for (;;)
	{
		printf("������ѡ��:");
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
	printf("����ƽ����:%.3lf,����������:%d\n", msum / (double)m, mfailed);
	printf("Ů��ƽ����:%.3lf,����������:%d", fsum / (double)f, ffailed);
	return 0;
}

