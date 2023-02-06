#include<iostream>

using namespace std;

int main() {
	while (true) {
		int A, B;
		cin >> A >> B;
		if (!A && !B) break;
		cout << A + B << "\n";
	}
}