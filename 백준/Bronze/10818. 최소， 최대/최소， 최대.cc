#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;

	int max_num = -1000000; int min_num = 1000000;
	for (int i = 0; i < N; i++) {
		int A; cin >> A;
		max_num = max(max_num, A);
		min_num = min(min_num, A);
	}

	cout << min_num << " " << max_num;
}