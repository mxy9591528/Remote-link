#include<iostream>
using namespace std;
bool isLeap(int n)
{
	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
		return true;
	return false;
}
int main()
{
	long seconds = 100000000, minutes, hours, days = 1;
	minutes = seconds / 60;
	seconds %= 60;
	hours = minutes / 60;
	minutes %= 60;
	days = hours / 24;
	hours %= 24;
	int start = 2022;
	while (days > 0)
	{
		if (isLeap(start + 1))
			days -= 366;
		else
			days -= 365;
		start++;
	}
	if (isLeap(start))
		days += 366;
	else
		days += 365;
	start--;
	int monthlist[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int m = 0;
	do
	{
		if (m == 1)
		{
			if (isLeap(start))
				days -= monthlist[m];
			else
				days -= 28;
		}
		else
			days -= monthlist[m];
		m++;
	} while (days > 0);
	m--;
	if (m == 1)
	{
		if (isLeap(start))
			days += 29;
		else
			days += 28;
	}
	else
		days += monthlist[m];
	cout << "��2022��1��1��0��0ʱ0��0����1����Ϊ" << start << "��" << m + 1 << "��" << days + 1 << "��" << hours << "ʱ" << minutes << "��" << seconds << "��";
}