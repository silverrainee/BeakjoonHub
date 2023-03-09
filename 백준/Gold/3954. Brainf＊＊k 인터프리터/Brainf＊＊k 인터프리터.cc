#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

unsigned char memory[100001];
char code[4097];
char input[4097];
int bracket[4097];

int main() {
	int T; cin >> T; // 테스트 케이스의 개수
	for (int t = 0; t < T; t++) {
		int M, C, I;
		cin >> M >> C >> I;

		//초기화
		for (int i = 0; i < M; i++) { //memory 초기화
			memory[i] = 0;
		}
		cin >> code; //code 초기화
		cin >> input;

		//괄호 짝짓기
		vector<int> brac;
		for (int i = 0; i < C; i++) {
			if (code[i] == '[') {
				brac.push_back(i);
			}
			else if (code[i] == ']') {
				int j = brac.back(); brac.pop_back();
				bracket[i] = j;
				bracket[j] = i;
			}
		}

		int cnt = 0; //코드 실행 횟수
		int m = 0; //포인터 위치
		int c = 0; //코드 위치
		int i = 0; //인풋 위치
		int max_c = 0;
		while (cnt < 100000000 && c < C) {
			if (code[c] == '-') {
				if (memory[m] > 0) memory[m]--;
				else memory[m] = 255;
			}
			else if (code[c] == '+') {
				if (memory[m] < 255) memory[m]++;
				else memory[m] = 0;
			}
			else if (code[c] == '<') {
				if (m > 0) m--;
				else m = M - 1;
			}
			else if (code[c] == '>') {
				if (m < M - 1) m++;
				else m = 0;
			}
			else if (code[c] == '[') {
				if (memory[m] == 0) {
					c = bracket[c];
				}
				else brac.push_back(c);
			}
			else if (code[c] == ']') {
				if (memory[m] != 0) {
					if (cnt >= 50000000) max_c = max(max_c, c);
					c = bracket[c];
				}
				else brac.pop_back();
			}
			else if (code[c] == '.') {
				
			}
			else if (code[c] == ',') {
				if (input[i]=='\0') {
					memory[m] = 255;
				}
				else memory[m] = input[i++];
			}

			cnt++; c++;
		}
		vector<int> v;

		if (cnt >= 100000000) {
			cout << "Loops " << bracket[max_c] << " " << max_c;
		}
		else cout << "Terminates";
		cout << "\n";
	}
}