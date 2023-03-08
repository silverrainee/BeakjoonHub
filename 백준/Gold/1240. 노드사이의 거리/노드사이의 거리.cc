#include <iostream>
#include <vector>

using namespace std;

struct edge {int node; int d;};

int flag;
void dfs(vector<vector<edge>>& tree, int visited[], int from, int to, int now, int d) {
    if(now == to) {
        cout << d << "\n";
        flag = 1;
        return;
    }

    visited[now] = 1; int size = tree[now].size();
    for(int i=0; i<size; i++) {
        edge next = tree[now][i];
        if(visited[next.node]) continue;
        dfs(tree, visited, from, to, next.node, d + next.d);
        if(flag) return;
    }
}

int main() {
    int N; cin >> N; // 노드의 개수 (양방향 트리)
    int M; cin >> M; // 문제의 개수

    vector<vector<edge>> tree(N+1);
    for(int i=0; i<N-1; i++) {
        int A, B, d; cin >> A >> B >> d;
        tree[A].push_back({B, d});
        tree[B].push_back({A, d});
    }

    for(int i=0; i<M; i++) {
        int from, to; cin >> from >> to;
        int visited[1001] = {};
        int now = from; int d = 0; flag = 0;
        dfs(tree, visited, from, to, now, d);
    }
}