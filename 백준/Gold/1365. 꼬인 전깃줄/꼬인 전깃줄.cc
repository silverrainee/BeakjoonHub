#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N; // 전봇대의 개수

    vector<int> v;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        if(v.empty()) v.push_back(a);
        else{
            if(v.back() < a){
                v.push_back(a);
            }
            else{
                for(int i=0; i<v.size(); i++){
                    if(v[i] > a){
                        v[i] = a;
                        break;
                    }
                }
            }
        }
    }

    cout << N - v.size();
}