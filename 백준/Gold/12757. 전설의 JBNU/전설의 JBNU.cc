#include<iostream>
#include<map>

using namespace std;

int findKey(map<int,int>& m, int key){
    auto i = m.lower_bound(key);
    if(i == m.end()){
        i--;
    }
    else if(i == m.begin()){
    }
    else {
        auto j = i; j--;
        if(2*key == i->first + j->first) return -1;
        if(abs(j->first - key) < abs(i->first - key)) i = j;
    }

    return i->first;
}

int main() {
    int N; cin >> N; // 초기 데이터 개수
    int M; cin >> M; // 명령 개수
    int K; cin >> K; // 거리 제한

    map<int, int> m;
    for(int i=0; i<N; i++){
        int key, v; cin >> key >> v;
        m.insert({key,v});
    }

    for(int i=0; i<M; i++){
        int c; cin >> c; // 명령

        if(c == 1){ // 데이터 삽입
            int key, v; cin >> key >> v;
            m.insert({key, v});
        }
        if(c == 2){
            int key, v; cin >> key >> v;
            int temp_key = findKey(m, key);
            if(temp_key != -1 && abs(temp_key - key) <= K) m[temp_key] = v;
        }
        if(c == 3){
            int key; cin >> key;
            int temp_key = findKey(m, key);
            if(temp_key == -1) cout << "?\n";
            else if(abs(temp_key - key) > K) cout << "-1\n";
            else cout << m[temp_key] << "\n";
        }
    }
}