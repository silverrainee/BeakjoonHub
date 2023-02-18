#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int cross = A * B * C;

	int dat[10] = {};
	while (cross) {
		dat[cross % 10]++;
		cross /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << dat[i] << "\n";
	}
}