#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int A, B; A = B = 0;
	for (int i = 0; i < 3; i++) {
		A *= 10; B *= 10;
		A += a % 10; B += b % 10;
		a /= 10; b /= 10;
	}

	cout << max(A, B);
}