#include <iostream>

using namespace std;

int main() {
	while (true) {
		string str;
		cin >> str;
		if (str == "0") break;

		int len = str.length(); bool flag = false;
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len - 1 - i]) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "no\n";
		else cout << "yes\n";
	}
}