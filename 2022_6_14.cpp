#include <iostream>
#include<stack>
using namespace std;
stack<char> s;
string str;
const int maxn = 250;
char ans[maxn];

int main() {
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '#': if (!s.empty()) s.pop(); break;
		case '@': while (!s.empty()) s.pop(); break;
		default: s.push(str[i]);
		}
	}
	int len = s.size();
	for (int i = 0; i < len; i++) {
		ans[i] = s.top();
		s.pop();
	}
	for (int i = len - 1; i >= 0; i--) cout << ans[i];
	return 0;
}