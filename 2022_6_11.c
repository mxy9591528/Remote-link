#include<stdio.h>
int main()
{
	int n, i = 1, ret = 2, flag = 1;
	double sum = 0;
	scanf("%d", &n);
	while (n)
	{
		sum += ((double)ret /(double) i)*flag;
		flag *= -1;
		int temp = i;
		i = ret;
		ret += temp;;
		n--;
	}
	printf("%lf", sum);
}

#include <stdio.h>              //1
#include <math.h>               //2

int judge(int n);

int main()                      //12
{                               //13
	int count=0, i;               //14
	for (i = 101; i < 1000; i = i + 2)    //15
		if (judge(i))           //16
		{                       //17
			printf("%5d", i);   //18
			count++;		//19
			if (count % 5 == 0)          //21
				printf("\n");           //22
		}                        //20
	return 0;                    //23
}                      

int judge(int n)                //3
{
	if (n == 2)//4
		return 1;
	int i, k;                   //5
	k = (int)sqrt(n);           //6
	for (i = 3; i <= k; i++)    //7
		if (!(n % i))           //8
			return 0;          //9
	return 1;        //10
}              
