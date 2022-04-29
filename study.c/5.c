//21011111 马县杨
#define PI 3.14
#include<stdio.h>
#include<windows.h>
int main()
{
	double r_mxy,h;
	printf("请输入圆柱的半径和高:\n",&r_mxy,&h);
	scanf("%lf %lf",&r_mxy,&h);
	printf("圆柱的体积是:%lf,圆柱的表面积是:%lf\n",PI*r_mxy*r_mxy*h,2*PI*r_mxy*(h+r_mxy));
	system("pause");
	return 0;
}