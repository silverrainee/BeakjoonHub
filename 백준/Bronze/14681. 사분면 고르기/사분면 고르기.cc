#include<iostream>

using namespace std;

int main() {
	int arr[2][2] = {
		3,2,
		4,1
	};

	int x, y;
	cin >> x >> y;

	cout << arr[x >= 0][y >= 0];
}