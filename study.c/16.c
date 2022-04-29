//21011111 马县杨
#include<stdio.h>
#include<Windows.h>
int main()
{
	double p_mxy,w,s,d,f;
	printf("请输入基本运费，货物重量，距离:\n");
	scanf("%lf %lf %lf",&p_mxy,&w,&s);
	if(s<250)
		d=0;
	else if(s<500)
		d=0.02;
	else if(s<1000)
		d=0.05;
	else if(s<2000)
		d=0.08;
	else if(s<3000)
		d=0.1;
	else
		d=0.15;
	f=p_mxy*w*s*(1-d);
	printf("总运费是%lf\n",f);
	system("pause");
	return 0;
}