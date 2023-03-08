#include<iostream>
#include<vector>

using namespace std;

struct node {int y; int x;};

int map[1000][1000];
int size_arr[1000];
int id[1000][1000];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N,M;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    int id_num = 1;
    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            if(map[y][x] == 0) continue;
            if(id[y][x]) continue;

            vector<node> v;

            v.push_back({y,x});
            id[y][x] = id_num;
            for(int i=0; i<v.size(); i++) {
                for(int j=0; j<4; j++) {
                    int ny = v[i].y + dy[j];
                    int nx = v[i].x + dx[j];
                    if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                    if(map[ny][nx] == 0) continue;
                    if(id[ny][nx]) continue;

                    v.push_back({ny, nx});
                    id[ny][nx] = id_num;
                }
            }

            size_arr[id_num] = v.size();
            id_num++;
        }
    }

    int max_size = 0;

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){

            int now_size = 0;
            vector<int> id_list;
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(map[ny][nx] == 0) continue;

                int flag = -1;
                for(int j=0; j<id_list.size(); j++){
                    if(id_list[j] == id[ny][nx]) flag = j;
                }
                if(flag == -1){
                    id_list.push_back(id[ny][nx]);
                    now_size += size_arr[id[ny][nx]];
                }
            }

            max_size = max(max_size, now_size);
        }
    }

    cout << max_size + 1;
}