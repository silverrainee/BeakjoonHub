#include <iostream>
#include <vector>
#define ll long long

using namespace std;


int main() {
	int K;
	int N;
	cin >> K >> N;

	ll left = 1; ll right = 0; ll ans = 0;
	vector<ll> arr(K);
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;

		ll cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += arr[i] / mid;
		}

		if (cnt >= N) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans;
}