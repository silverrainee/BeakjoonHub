#include<iostream>

using namespace std;

int main() {
	char cat[4][20] = {
		"\\    /\\ ",
		" )  ( ')",
		"(  /  )",
		" \\(__)|"
	};

	for (int i = 0; i < 4; i++) {
		cout << cat[i] << "\n";
	}

	return 0;
}