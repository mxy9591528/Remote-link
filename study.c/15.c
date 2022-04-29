//21011111 马县杨
#include<stdio.h>
#include<math.h>
#include<Windows.h>
double getY(double a,double b)
{
	double Y;
	if(a>0)
	{
		if(b>0)
			Y=cos(a)+cos(b);
	    else
			Y=sin(a)+sin(b);
	}
	else
	{
		if(b>0)
			Y=cos(a)+sin(b);
		else
			Y=sin(a)+cos(b);
	}
	return Y;
}
int main()
{
	double a_mxy,b,Y;
	printf("请输入a,b的值\n");
	scanf("%lf %lf",&a_mxy,&b);
	Y=getY(a_mxy,b);
	printf("Y的值为%lf\n",Y);
	system("pause");
	return 0;
}