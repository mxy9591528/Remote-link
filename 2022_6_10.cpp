#include <iostream>
using namespace std;
using namespace std;
const int maxn = 100001;
int a[maxn];
int main() {
	int n, s, min = 2200, max = -2200, k;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) {
		if (a[i] > max) {
			s = i;
			max = a[i];
		}
	}
	for (int i = 1; i <= s; i++) {
		if (a[i] < min)
		{
			min = a[i];
			k = i;
		}
	}
	if (k < s)
		cout << max - min;
	else
		cout << min - max;
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	char buf[1024] = { 0 };
	int count = 0, i = 0, j;
	cin >> buf;
	char*s = buf;
	while (s[i])
	{
		if (s[i]== 'a')
		{
			char*p = s;
			j = i;
			while (p[j])
			{
				if (p[j++] == 'c')
				{
					count++;
					cout << "(" << i << "," << j-1 << ")" << " ";
				}
			}
		}
		i++;
	}
	cout<<endl<< count;
	return 0;
}
