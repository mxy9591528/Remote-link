//21011111 ������
#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	double x1_mxy,y1,x2,y2;
	printf("�������������꣺\n");
	scanf("%lf %lf %lf %lf",&x1_mxy,&y1,&x2,&y2);
	printf("�������Ϊ:%lf\n",sqrt((x1_mxy-x2)*(x1_mxy-x2)+(y1-y2)*(y1-y2)));
	system("pause");
	return 0;
}