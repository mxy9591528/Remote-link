#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void menu()
{
	printf("  ħ����\n");
	printf("****************************\n");
	printf("1.������ħ����\n");
	printf("2.����ħ����\n");
	printf("0.�˳�\n");
	printf("****************************\n");
}

void odd()
{
	int n = 0;
	while (n % 2 == 0)
	{
		printf("����������������");
		printf("\n");
		scanf("%d", &n);
	}
	int **a = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		a[i] = (int*)calloc(n, sizeof(int));
	a[0][n / 2] = 1;//1���ڵ�һ���м�
	int row = 0;//��ǰ���±�
	int col = n / 2;//��ǰ���±�
	for (int i = 2; i <= n * n; i++) //һ��һ������ȥ�� �����±� ���ǰ�������
	{
		//��һ�к�һ��
		row = (row - 1 + n) % n;   //���δ���
		col = (col + 1) % n;
		//��ǰλ��������������
		if (a[row][col] != 0)
		{
			row = (row + 2) % n;
			col = (col - 1 + n) % n;
		}
		a[row][col] = i;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				sum += a[i][j];
			printf("%d\t", a[i][j]);
		}
		printf("\n\n\n");
	}
	printf("���С��м��������Խ�����ȵĺ�Ϊ��\t%d\n", sum);
}
int sushu(int n)
{
	int i;
	if (n == 1) return 1;
	for (i = 2; i <= n; i++)
		if (n%i == 0) break;
	if (n == i) return 1;
	else return 0;
}
int wunai(int t, int b, int c, int d, int e, int f, int g, int h, int p)
{
	int a[9];
	int i, j;
	a[0] = t; a[1] = b; a[2] = c; a[3] = d; a[4] = e; a[5] = f; a[6] = g; a[7] = h; a[8] = p;
	for (i = 0; i < 9; i++)
		for (j = i + 1; j < 9; j++)
			if (a[i] == a[j]) return 0;
	for (i = 0; i < 9; i++)
		if (sushu(a[i]) != 1) return 0;
	return 1;
}
bool isPrime(int n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i += 2)//����ż��
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
void prime()
{
	int k;
	printf("���������ħ�����������Χ��С��100����");
	printf("\n");
	scanf("%d", &k);
	int i, i1, i2;
	static int j = 0, n = 0;
	int a, b, c, d, z;
	int ar[100];
	for (i = 1; i < k; i++)
		if (sushu(i) == 1) { ar[j] = i; j++; }
	for (i = 0; i < j; i++)
	{
		a = ar[i];
		for (i1 = 0; i1 < j; i1++)
		{
			b = ar[i1];
			for (i2 = 0; i2 < j; i2++)
			{
				d = ar[i2];
				c = (a + 2 * b + d) / 4;
				if ((a != b && b != d) && ((a + 2 * b + d) % 4 == 0) && sushu(c) == 1)
				{
					z = 3 * c;
					if (wunai(a, b, c, d, z - a - b, z - c - d, z - b - c, z - a - c, z - b - d))
						if ((z - a - b) > 0 && (z - c - d) > 0 && (z - b - c) > 0 && (z - a - c) > 0 && (z - b - d) > 0)
						{
							if ((z - a - b) < k && (z - c - d) < k && (z - b - c) < k && (z - a - c) < k && (z - b - d) < k)
							{
								printf("%d ", z - a - b);
								printf("%d ", a);
								printf("%d\n", b);
								printf("%d ", z - c - d);
								printf("%d ", c);
								printf("%d\n", d);
								printf("%d ", z - b - c);
								printf("%d ", z - a - c);
								printf("%d\n", z - b - d);
								printf("\n\n");
								n++;
								//if (n == 8) return ;
							}
						}
				}
			}
		}
	}

}
void exit()
{
	exit(0);
}
int main()
{
	menu();
	int choice;
	printf("������ѡ�\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		odd();
		break;
	case 2:
		prime();
		break;
	case 0:
		exit();
		break;
	default:
		printf("������Ч\n");
		break;
	}
}


#include<iostream>
using namespace std;
int main()
{
	long long ret = 1, sum = 0;
	for (int i = 60; i >= 1; i--)
	{
		ret = ret * 2 + 1;
		sum += ret;
	}
	cout << sum << endl;
	return 0;
}