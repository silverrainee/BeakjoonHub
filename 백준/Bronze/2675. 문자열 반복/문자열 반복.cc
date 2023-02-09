#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int R; cin >> R;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < R; j++) {
				cout << str[i];
			}
		}
		cout << "\n";
	}
}