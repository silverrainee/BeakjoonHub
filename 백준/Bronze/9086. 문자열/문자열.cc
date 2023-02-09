#include <iostream>
#include <string>

using namespace std;

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		cin >> str;
		cout << str[0] << str[str.length() - 1] << "\n";
	}
}