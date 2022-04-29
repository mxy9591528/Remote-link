//21011111 马县杨
#include<stdio.h>
#include<Windows.h>
int main()
{
	int dB_mxy;
	printf("请输入分贝的值:\n");
	scanf("%d",&dB_mxy);
	if(dB_mxy<=50)
		printf("安静\n");
	else if(dB_mxy<=70)
		printf("吵闹，有损神经\n");
	else if(dB_mxy<=90)
		printf("很吵，神经细胞受到破坏\n");
	else if(dB_mxy<=100)
		printf("吵闹加剧，听力受损\n");
	else if(dB_mxy<=120)
		printf("难以忍受，带一分钟即暂时致聋\n");
	else
		printf("极度聋或全聋\n");
	system("pause");
	return 0;
}