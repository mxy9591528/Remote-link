//21011111 ������
#include<stdio.h>
#include<Windows.h>
int main()
{
	double x_mxy,y;
	printf("������x��ֵ\n");
	scanf("%lf",&x_mxy);
	if(x_mxy<0)
		y=2*x_mxy-1;
	else if(x_mxy<10)
		y=2*x_mxy+10;
	else if(x_mxy<100)
		y=2*x_mxy+100;
	else
		y=x_mxy*x_mxy;
	printf("y=%lf\n",y);
	system("pause");
	return 0;
}