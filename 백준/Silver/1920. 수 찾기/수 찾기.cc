#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Target {
    int index;
    long long num;
};

bool operator < (Target A, Target B){
    return A.num < B.num;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<long long> arr(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int M; cin >> M;
    vector<Target> target(M);
    for(int i=0; i<M; i++) {
        target[i].index = i;
        cin >> target[i].num;
    }

    sort(arr.begin(), arr.end());
    sort(target.begin(), target.end());

    vector<bool> ans(M);
    int i=0; int j=0;
    while ((i < N) && (j < M)) {
        if (arr[i] == target[j].num) {
            ans[target[j].index] = true; j++;
        }
        else if (arr[i] > target[j].num) j++;
        else if (arr[i] < target[j].num) i++;
    }

    for(int i=0; i<M; i++){
        if(ans[i]) cout << "1\n";
        else cout << "0\n";
    }
}