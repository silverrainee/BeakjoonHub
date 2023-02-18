#include <iostream>

using namespace std;

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	int dat[42] = {}; int cnt = 0;
	for (int i = 0; i < 10; i++) {
		int a = arr[i] % 42;
		if (dat[a] == 0) cnt++;
		dat[a]++;
	}

	cout << cnt;
}