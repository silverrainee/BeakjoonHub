#include<iostream>
#include<queue>

using namespace std;

struct Ball {
	int index;
	int color; // 색
	int size; // 크기
};

bool operator < (Ball A, Ball B) {
	if (A.size == B.size) return A.color > B.color;
	return A.size > B.size;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	priority_queue<Ball> ball;
	for (int i = 1; i <= N; i++) {
		int color, size;
		cin >> color >> size;
		ball.push({ i, color, size });
	}

	Ball pre = {0,0,0};
	int sum, temp_sum, temp_color_sum; // sum : 이전 크기 합, temp_sum : 같은 크기 합, temp_color_sum : 같은 크기 같은 색 합
	sum = temp_sum = temp_color_sum = 0;
	int sum_by_color[200001] = {};
	vector<int> ans(N + 1);
	while (!ball.empty()) {
		Ball now = ball.top(); ball.pop();
		if (now.size > pre.size) {
			sum += temp_sum;
			sum_by_color[pre.color] += temp_color_sum;
			ans[now.index] = sum - sum_by_color[now.color];
			temp_sum = temp_color_sum = now.size;
		}
		else {
			if (now.color > pre.color) {
				temp_sum += now.size;
				sum_by_color[pre.color] += temp_color_sum;
				ans[now.index] = sum - sum_by_color[now.color];
				temp_color_sum = now.size;
			}
			else {
				temp_sum += now.size;
				temp_color_sum += now.size;
				ans[now.index] = sum - sum_by_color[now.color];
			}
		}
		pre = now;
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
}