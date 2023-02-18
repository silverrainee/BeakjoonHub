#include <iostream>

using namespace std;

int main() {
	string str;
	cin >> str;

	int len = str.length();

	int dat[200] = {};

	for (int i = 0; i < len; i++) {
		dat[str[i]]++;
	}

	char max_Alpabet = 'A'; int max_cnt = 0; int max_Alpabet_cnt = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		int cnt = dat[i] + dat[i - 'A' + 'a'];
		if (cnt > max_cnt) {
			max_cnt = cnt; max_Alpabet_cnt = 1; max_Alpabet = i;
		}
		else if (cnt == max_cnt) {
			max_Alpabet_cnt++;
		}
	}

	if (max_Alpabet_cnt > 1) cout << "?";
	else cout << max_Alpabet;
}