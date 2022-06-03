#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <tchar.h>
#include <wchar.h>
#pragma comment(lib, "winmm.lib") // 使用音乐播放库
int main()
{
	mciSendString("open 烟袋斜街.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
void BubbleSort(int*c, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int flag = 1;
		for (int j = 1; j < n - i; ++j)
		{
			if (c[j - 1] > c[j])
			{
				int ret = c[j - 1];
				c[j - 1] = c[j];
				c[j] = ret;
				flag = 0;
			}
		}
		if (flag)//未交换直接返回
			return;
	}
}
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	BubbleSort(a, n);
	int d = a[1] - a[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] - a[i] != d)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
#include<iostream>
using namespace std;
class Cuboid
{
public:
	void setvalue(float a, float b, float c)
	{
		this->length = a;
		this->width = b;
		this->height = c;
	}
	void countarea()
	{
		this->area = 2 * (this->height*this->length + this->height*this->width + this->length*this->width);
	}
	void countvolume()
	{
		this->volume = this->height*this->length*this->width;
	}
	void show()
	{
		cout << "area=" << this->area << "," << "volume=" << this->volume;
	}
private:
	float length;
	float width;
	float height;
	float area;
	float volume;
};
int main()
{
	Cuboid cc; float a, b, c;
	cin >> a >> b >> c;
	cc.setvalue(a, b, c);
	cc.countarea();
	cc.countvolume();
	cc.show();
	return 0;
}
