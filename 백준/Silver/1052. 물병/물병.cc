#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main() {
	int N; // 물병의 개수
	int K; // 옮길 수 있는 물병의 개수
	cin >> N >> K;

	vector<int> arr;
	int i = 0;
	while (true) {
		if (N >> i == 0) break;
		int flag = (N >> i) & 1;
		if (flag) arr.push_back(i);
		i++;
	}

	int n = arr.size();

	if (n - K <= 0) {
		cout << 0;
		return 0;
	}

	int plus = 1 << arr[n - K];
	int minus = N & (plus - 1);

	cout << plus - minus;
}