#include <iostream>

using namespace std;

int sol(char arr[]) {
	int ret = 0;

	int i = 0; int j = 1;
	while (arr[i] != '\0') {
		if (arr[i] == 'O') {
			ret += j++;
		}
		else j = 1;

		i++;
	}

	return ret;
}

int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		char arr[100];
		cin >> arr;

		cout << sol(arr) << "\n";
	}
}