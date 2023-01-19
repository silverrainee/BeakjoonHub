#include<iostream>
#include<vector>

using namespace std;

void sol(vector<int>& Aarr, vector<int>& Qarr, vector<vector<int>>& ansarr) {
	int len = Aarr.size();
	int Flag = 0;

	for (int offset = 0; offset < len; offset++) { // offset
		int flag = 0;
		for (int i = 0; i < len; i++) { // Aarr index
			int j = (i + offset) % len;
			if (Aarr[i] != Qarr[j]) {
				flag = 1; break;
			}
		}
		if (flag) continue;
		Flag = 1; break;
	}

	for (int offset = 0; offset < len; offset++) { // offset
		int flag = 0;
		for (int i = 0; i < len; i++) { // Aarr index
			int j = (-i + offset + len) % len;
			if (Aarr[i] != (Qarr[j] + 1) % 4 + 1) {
				flag = 1; break;
			}
		}
		if (flag) continue;
		Flag = 1; break;
	}

	if (Flag) {
		vector<int> ans;
		for (int i = 0; i < len; i++) {
			ans.push_back(Qarr[i]);
		}
		ansarr.push_back(ans);
	}
}

int main() {
	int len; // 모양수열의 길이
	cin >> len;

	vector<int> Aarr(len);
	for (int i = 0; i < len; i++) {
		cin >> Aarr[i];
	}

	int N; // 모양수열의 개수
	cin >> N;

	vector<vector<int>> Qarr;
	for (int i = 0; i < N; i++) {
		vector<int> Q(len);
		Qarr.push_back(Q);
		for (int j = 0; j < len; j++) {
			cin >> Qarr[i][j];
		}
	}

	vector<vector<int>> ansarr;
	for (int i = 0; i < N; i++) {
		sol(Aarr, Qarr[i], ansarr);
	}

	N = ansarr.size();
	cout << N << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < len; j++) {
			cout << ansarr[i][j] << " ";
		}
		cout << "\n";
	}
}