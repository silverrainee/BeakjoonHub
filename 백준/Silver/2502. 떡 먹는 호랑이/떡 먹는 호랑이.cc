#include <iostream>
#include <vector>

using namespace std;

int main() {
    int D; cin >> D; // 할머니가 넘어온 날
    int K; cin >> K; // D일 째의 떡의 개수

    vector<int> fibonacci(D);
    fibonacci[1] = fibonacci[2] = 1;
    for(int i=3; i<D; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    // K = a * fibonacci[D-2] + b * fibonacci[D-1]
    int a,b;
    for(a = 1; K > a*fibonacci[D-2]; a++){
        b = (K - a*fibonacci[D-2])/fibonacci[D-1];
        if((K - a*fibonacci[D-2])%fibonacci[D-1] == 0) break;
    }

    cout << a << "\n" << b;
}