//21011111 ������
#define PI 3.14
#include<stdio.h>
#include<windows.h>
int main()
{
	double r_mxy,h;
	printf("������Բ���İ뾶�͸�:\n",&r_mxy,&h);
	scanf("%lf %lf",&r_mxy,&h);
	printf("Բ���������:%lf,Բ���ı������:%lf\n",PI*r_mxy*r_mxy*h,2*PI*r_mxy*(h+r_mxy));
	system("pause");
	return 0;
}