#include <iostream>
#include <vector>

using namespace std;

int sol(vector<vector<int>>& sticker, vector<vector<int>>& ans, int y, int x) {
	if (ans[y][x] != -1) return ans[y][x];
	
	int ny;
	if (y == 0) ny = 1;
	else ny = 0;

	if (x == 0) return ans[y][x] = sticker[y][x];

	int ret1 = sol(sticker, ans, y, x - 1);
	int ret2 = sol(sticker, ans, ny, x - 1) + sticker[y][x];

	if (x == 1) return ans[y][x] = max(ret1, ret2);

	int ret3 = sol(sticker, ans, y, x - 2) + sticker[y][x];
	int ret4 = sol(sticker, ans, ny, x - 2) + sticker[y][x];

	return ans[y][x] = max(ret1, max(ret2, max(ret3, ret4)));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; // 테스트 케이스
	cin >> T;
	for (int t = 1; t <= T; t++) {

		int N; //스티커의 길이
		cin >> N;
		vector<vector<int>> sticker; // 스티커 배열
		vector<vector<int>> ans; // dp 저장 배열
		for (int i = 0; i < 2; i++) {
			vector<int> v(N + 2);
			vector<int> a(N + 2);
			for (int j = 0; j < N; j++) {
				cin >> v[j];
				a[j] = -1;
			}
			a[N] = -1; a[N + 1] = -1;
			sticker.push_back(v);
			ans.push_back(a);
		}

		cout << max(sol(sticker, ans, 0, N + 1), sol(sticker, ans, 1, N + 1)) << "\n";
	}
}