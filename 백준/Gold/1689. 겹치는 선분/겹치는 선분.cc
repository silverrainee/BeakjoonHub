#include<iostream>
#include<queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;

    priority_queue<int, vector<int>, greater<int>> s_pt;
    priority_queue<int, vector<int>, greater<int>> e_pt;
    for(int i=0; i<N; i++){
        int s,e; cin >> s >> e;
        s_pt.push(s);
        e_pt.push(e);
    }

    int cnt = 0; int max_cnt = 0; int i = 0;
    while(!s_pt.empty()){
        i = s_pt.top(); s_pt.pop();
        cnt++;
        while(!e_pt.empty()){
            if(i >= e_pt.top()){
                e_pt.pop();
                cnt--;
            }
            else break;
        }
        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt;
}