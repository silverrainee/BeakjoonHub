#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int y;
    int x;
    int cost;
};

bool operator < (Node A, Node B) {
    return A.cost > B.cost;
}

bool visited[500][500];
int dijk[500][500];
char map[500][501];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main(){
    int W, H;
    cin >> W >> H;
    for(int i=0; i<H; i++) {
        cin >> map[i];
    }

    priority_queue<Node> pq;
    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            if(map[y][x] == 'T'){
                pq.push({y,x,0});
            }
        }
    }

    while(!pq.empty()){
        Node now = pq.top(); pq.pop();

        if(visited[now.y][now.x]) continue;
        visited[now.y][now.x] = true;
        dijk[now.y][now.x] = now.cost;

        if(map[now.y][now.x] == 'E') {
            cout << dijk[now.y][now.x];
            return 0;
        }

        for(int i=0; i<4; i++){ // 방향
            Node next = now;
            int j = 1; // 거리
            while(true){
                int y = now.y + dy[i]*j;
                int x = now.x + dx[i]*j;
                j++;
                if(y<0 || x<0 || y >= H || x >= W) break;
                else if(map[y][x] == 'T') continue;
                else if(map[y][x] == 'R'){
                    if(!visited[next.y][next.x]){
                        pq.push(next);
                    }
                    break;
                }
                else if(map[y][x] == 'H') break;
                else if(map[y][x] == 'E'){
                    next.y = y; next.x = x;
                    if(!visited[next.y][next.x]){
                        pq.push(next);
                    }
                    break;
                }
                else{
                    next.y = y; next.x = x;
                    next.cost += (int)map[y][x] - (int)'0';
                    continue;
                }
            }
        }
    }

    cout << -1;
    
    return 0;
}