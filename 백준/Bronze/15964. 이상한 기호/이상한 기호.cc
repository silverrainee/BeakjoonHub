#include <iostream>

using namespace std;

long long sol(long long A, long long B) {
	return (A + B) * (A - B);
}

int main() {
	long long A, B;
	cin >> A >> B;
	cout << sol(A, B);
}