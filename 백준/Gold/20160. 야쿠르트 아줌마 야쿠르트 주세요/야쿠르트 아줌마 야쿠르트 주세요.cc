// 14% 틀렸습니다.

#include<iostream>
#include<queue>
#define ll long long

using namespace std;

struct edge {int to_node; ll t;};

bool operator < (edge A, edge B){
    return A.t > B.t;
}

// from 에서 모든 노드까지의 최단 시간을 반환하는 함수
void dijk_all(vector<vector<edge>>& from_node, vector<ll>& dijk, int from_node_idx){
    priority_queue<edge> pq;
    pq.push({from_node_idx, 0});

    while(!pq.empty()){
        edge now = pq.top(); pq.pop();
        if(dijk[now.to_node] != -1) continue;
        dijk[now.to_node] = now.t;

        for(int i = 0; i < from_node[now.to_node].size(); i++){
            edge next = from_node[now.to_node][i];
            next.t += now.t;

            if(dijk[next.to_node] != -1) continue;
            pq.push(next);
        }
    }
}

// from 에서 to 까지의 최단 시간을 반환하는 함수
ll dijk_part(vector<vector<edge>>& from_node, int from_node_idx, int to_node_idx){
    vector<ll> dijk(from_node.size(), -1);
    
    priority_queue<edge> pq;
    pq.push({from_node_idx, 0});

    while(!pq.empty()){
        edge now = pq.top(); pq.pop();
        if(dijk[now.to_node] != -1) continue;
        dijk[now.to_node] = now.t;
        
        if(now.to_node == to_node_idx) return now.t;

        for(int i = 0; i < from_node[now.to_node].size(); i++){
            edge next = from_node[now.to_node][i];
            next.t += now.t;

            if(dijk[next.to_node] != -1) continue;
            pq.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int V; cin >> V; // 노드 개수 (1 ~ V)
    int E; cin >> E; // 간선 개수

    vector<vector<edge>> from_node(V + 1);
    for(int i=0; i<E; i++){
        int from_node_idx, to_node_idx; ll t;
        cin >> from_node_idx >> to_node_idx >> t;
        from_node[from_node_idx].push_back({to_node_idx, t});
        from_node[to_node_idx].push_back({from_node_idx, t});
    }

    int you[10] = {}; int I;
    for(int i=0; i<10; i++){
        cin >> you[i];
    }
    cin >> I;

    vector<ll> dijk_you(V + 1, -1);
    dijk_all(from_node, dijk_you, you[0]);
    vector<ll> dijk_I(V + 1, -1);
    dijk_all(from_node, dijk_I, I);

    vector<ll> t(10, -1);
    int from = 0; int to = 1;
    t[0] = 0;
    while(to < 10){
        if(dijk_you[you[to]] == -1){
            to++;
        }
        else {
            t[to] = t[from] + dijk_part(from_node, you[from], you[to]);
            from = to;
            to++;
        }
    }

    int ans = -1;
    for(int i=0; i<10; i++){
        if(dijk_you[you[i]] == -1 || dijk_I[you[i]] == -1) continue;
        if(t[i] < dijk_I[you[i]]) continue;
        if(ans == -1) ans = you[i];
        else ans = min(ans, you[i]);
    }

    cout << ans;
}