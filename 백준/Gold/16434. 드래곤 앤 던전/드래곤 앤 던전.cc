#include<iostream>
#include<vector>
#define ll long long

using namespace std;

struct node{
    int type;
    ll a; // 공격력
    ll h; // 생명력
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; ll atk;
    cin >> N >> atk;
    vector<node> rooms(N+1);
    for(int i=0; i<N; i++){
        node& room = rooms[i];
        cin >> room.type >> room.a >> room.h;
        if(room.type == 2) atk += room.a;
    }

    ll maxHP, HP, minHP;
    maxHP = HP = minHP = 1;
    for(int i=N-1; i>=0; i--){
        node& room = rooms[i];
        if(room.type == 1){
            ll a_cnt = room.h/atk;
            if(room.h%atk == 0) a_cnt--;
            HP += room.a * a_cnt;
            maxHP = max(maxHP, HP);
        }
        else {
            atk -= room.a;
            HP -= room.h;
            HP = max(HP, minHP);
        }
    }

    cout << maxHP;
}