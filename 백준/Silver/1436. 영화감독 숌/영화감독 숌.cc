#include <iostream>
#include <string>

using namespace std;

bool sol(int i) {
	string str = to_string(i);

	int a = str.find("666");
	return a != -1;
}

int main() {
	int N; cin >> N;

	int cnt = 0; int i = 666;
	while (cnt != N) {
		cnt += sol(i);
		i++;
	}

	cout << i - 1;
}