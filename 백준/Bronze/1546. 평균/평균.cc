#include <iostream>

using namespace std;

float max(float A, float B) {
	if (A > B) return A;
	else return B;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;

	cin >> N;

	float max_score = 0; float avg_score = 0;

	float score_arr[1000];
	for (int i = 0; i < N; i++) {
		cin >> score_arr[i];
		max_score = max(max_score, score_arr[i]);
		avg_score += score_arr[i];
	}

	cout << (avg_score / max_score) * 100 / N;
}