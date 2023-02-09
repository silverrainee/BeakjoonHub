#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int cnt = 0;

	char str[1000001];
	while (scanf("%s", str) != EOF) {
		cnt++;
	}

	cout << cnt;
}