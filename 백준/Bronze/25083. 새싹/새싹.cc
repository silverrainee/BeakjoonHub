#include<iostream>

using namespace std;

int main() {
	char sprout[6][30] = {
		"         ,r'\"7 ",
		"r`-_   ,'  ,/ ",
		" \\. \". L_r' ",
		"   `~\\/ ",
		"      | ",
		"      | "
	};

	for (int i = 0; i < 6; i++) {
		cout << sprout[i] << "\n";
	}

	return 0;
}