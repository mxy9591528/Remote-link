//21011111 ������
#include<stdio.h>
#include<Windows.h>
int getprice(int a,int b)
{
	int tnum,sump=0;
	if(a&&b)
	{
		if(a>b)
		{
			tnum=b;
			if(tnum<50)
				sump+=tnum*90+(a-tnum)*60;
			else
				sump+=tnum*80+(a-tnum)*60;
		}
		else
		{
			tnum=a;
			if(tnum<50)
				sump+=tnum*90+(b-tnum)*45;
			else
				sump+=tnum*80+(b-tnum)*45;
		}
	}
	else
	{
		if(a)
			sump=a*60;
		else
			sump=b*60;
	}
	return sump;
}
int main()
{
	int a_mxy,b;
	printf("�����빺�������������������\n");
	scanf("%d %d",&a_mxy,&b);
	printf("�տ��ܶ���%d\n",getprice(a_mxy,b));
	system("pause");
	return 0;
}