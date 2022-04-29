//21011111 马县杨
#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	double x1_mxy,y1,x2,y2;
	printf("请输入两点坐标：\n");
	scanf("%lf %lf %lf %lf",&x1_mxy,&y1,&x2,&y2);
	printf("两点距离为:%lf\n",sqrt((x1_mxy-x2)*(x1_mxy-x2)+(y1-y2)*(y1-y2)));
	system("pause");
	return 0;
}