//21011111 马县杨
#include<stdio.h>
#include<windows.h>
int main()
{
	double lenth_mxy,width,x;
	printf("请输入矩形草坪的长和宽，以及修剪草坪的速度x:\n");
	scanf("%lf %lf %lf",&lenth_mxy,&width,&x);
	printf("修剪草坪所需时间为：%lf\n",lenth_mxy*width/x);
	system("pause");
	return 0;
}