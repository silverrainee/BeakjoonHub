#include <iostream>

using namespace std;

bool dat[1000001];

int main() {
    for(int i=2; i<=1000000; i++) {
        dat[i] = 1;
    }

    for(int i=2; i<=1000; i++) {
        for(int j=i; j<1000000; j++) {
            if(i*j > 1000000) break;
            dat[i*j] = 0;
        }
    }

    int M,N;
    cin >> M >> N;
    for(int i=M; i<=N; i++) {
        if(dat[i]) cout << i << "\n";
    }
}