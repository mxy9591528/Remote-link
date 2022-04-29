//21011111 马县杨
#include<stdio.h>
#include<Windows.h>
int main()
{
	float B_mxy,S,P,T;
	printf("请输入基本工资，本月基本营业额，营业额提成的比例：\n");
	scanf("%f %f %f",&B_mxy,&S,&P);
	T=B_mxy+S*P;
	printf("实发工资为：%f\n",T);
	system("pause");
	return 0;
}