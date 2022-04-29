//21011111 马县杨
#include<stdio.h>
#include<windows.h>
int main()
{
	double l1_mxy,l2,h;
	printf("请输入梯形上底，下底，高：\n");
	scanf("%lf %lf %lf",&l1_mxy,&l2,&h);
	printf("梯形的面积为:%lf\n",(l1_mxy+l2)*h/2);
	system("pause");
	return 0;
}