#include <iostream>

using namespace std;

int main() {
	int x, y, X, Y;
	cin >> x >> y >> X >> Y;

	cout << min(min(x, y), min(X - x, Y - y));
}