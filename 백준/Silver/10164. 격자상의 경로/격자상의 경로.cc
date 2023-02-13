#include <iostream>
#include <math.h>

using namespace std;

int N; // 맵의 높이
int M; // 맵의 길이
int circle_num; // 동그라미 숫자

int ans[16][16];
int dp(int y, int x) {
	if (ans[y][x]) return ans[y][x];

	if (y == 1 || x == 1) return ans[y][x] = 1;

	return ans[y][x] = dp(y - 1, x) + dp(y, x - 1);
}

int main() {
	cin >> N >> M >> circle_num;

	if (circle_num == 0) {
		cout << dp(N, M);

		return 0;
	}

	int n = (circle_num - 1) / M + 1;
	int m = (circle_num - 1) % M + 1;

	cout << dp(n, m) * dp(N - n + 1, M - m + 1);

	return 0;
}