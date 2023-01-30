#include<iostream>
#include<queue>

using namespace std;

struct node {
	int w; // 횟수
	int cnt; // 자두 개수
};

bool operator < (node A, node B) {
	if (A.w == B.w) return A.cnt < B.cnt; // 횟수가 같으면 자두 개수가 큰 것이 top
	return A.w > B.w; // 횟수가 작은 것이 top
}

int main() {
	int T; // 시간의 길이
	int W; // 횟수 제한
	cin >> T >> W;
	
	vector<int> arr(T + 1);
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}

	vector<vector<priority_queue<node>>> Jadu;
	vector<priority_queue<node>> J(T + 1);
	for (int i = 0; i < 2; i++) {
		Jadu.push_back(J);
	}
	int flag0 = arr[0] == 1;
	int flag1 = arr[0] == 2;
	Jadu[0][0].push({ 0,flag0 });
	Jadu[1][0].push({ 1,flag1 });

	int maxCnt = 0;

	for (int i = 1; i <= T; i++) {
		priority_queue<node> temp0;
		priority_queue<node> temp1;
		int flag0 = arr[i] == 1; // 0번 줄에 자두가 떨어지면
		int flag1 = arr[i] == 2; // 1번 줄에 자두가 떨어지면

		while (!Jadu[0][i - 1].empty()) {
			node temp = Jadu[0][i - 1].top(); Jadu[0][i - 1].pop(); // 0번 줄에서 꺼낸 이전 node
			temp0.push({ temp.w, temp.cnt + flag0 });
			temp1.push({ temp.w + 1, temp.cnt + flag1 });
		}

		while (!Jadu[1][i - 1].empty()) {
			node temp = Jadu[1][i - 1].top(); Jadu[1][i - 1].pop();
			temp0.push({ temp.w + 1, temp.cnt + flag0 });
			temp1.push({ temp.w, temp.cnt + flag1 });
		}

		int cnt = -1;
		while (!temp0.empty()) {
			node temp = temp0.top(); temp0.pop();
			if (temp.cnt <= cnt) continue;
			if (temp.w > W) break;
			Jadu[0][i].push(temp);
			cnt = temp.cnt;
		}
		maxCnt = max(maxCnt, cnt);

		cnt = -1;
		while (!temp1.empty()) {
			node temp = temp1.top(); temp1.pop();
			if (temp.cnt <= cnt) continue;
			if (temp.w > W) break;
			Jadu[1][i].push(temp);
			cnt = temp.cnt;
		}
		maxCnt = max(maxCnt, cnt);
	}

	cout << maxCnt;
}