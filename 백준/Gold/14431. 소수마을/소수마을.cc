#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct Node { int y; int x; };
struct Edge { int to_node; int dist; };

bool operator < (Edge A, Edge B) {
    return A.dist > B.dist;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // 에라토스테네스의 체
    bool prime_num[10000];
    for (int i = 2; i < 10000; i++) prime_num[i] = true;
    for (int i = 2; i < 10000; i++) {
        if (prime_num[i] == false) continue;
        for (int j = i; i * j < 10000; j++) {
            prime_num[i * j] = false;
        }
    }

    Node A, B;
    cin >> A.x >> A.y >> B.x >> B.y;

    int N; cin >> N;
    vector<Node> node(N + 2);
    node[0] = A; node[N + 1] = B;
    for (int i = 1; i <= N; i++) {
        cin >> node[i].x >> node[i].y;
    }

    vector<vector<Edge>> tree(N + 2);
    for (int i = 0; i <= N + 1; i++) {
        for (int j = i + 1; j <= N + 1; j++) {
            int dist = sqrt(pow(node[i].x - node[j].x, 2) + pow(node[i].y - node[j].y, 2));
            if (prime_num[dist]) {
                tree[i].push_back({ j, dist });
                if (i == 0) continue;
                tree[j].push_back({ i, dist });
            }
        }
    }

    vector<bool> visited(N + 2);
    vector<int> dijk(N + 2);
    priority_queue<Edge> pq;
    pq.push({ 0,0 });

    while (!pq.empty()) {
        Edge now = pq.top(); pq.pop();
        if (visited[now.to_node]) continue;
        dijk[now.to_node] = now.dist;
        visited[now.to_node] = true;
        for (int i = 0; i < tree[now.to_node].size(); i++) {
            Edge next = tree[now.to_node][i]; next.dist += now.dist;
            if (visited[next.to_node]) continue;
            pq.push(next);
        }
    }

    if (visited[N + 1]) cout << dijk[N + 1];
    else cout << -1;
}