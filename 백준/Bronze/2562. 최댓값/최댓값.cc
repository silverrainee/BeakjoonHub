#include <iostream>

using namespace std;

int main() {
	int arr[10];
	for (int i = 1; i <= 9; i++) {
		cin >> arr[i];
	}

	int max_nu, max_id;
	max_nu = max_id = 0;
	for (int i = 1; i <= 9; i++) {
		if (arr[i] > max_nu) {
			max_nu = arr[i];
			max_id = i;
		}
	}

	cout << max_nu << "\n" << max_id;
}