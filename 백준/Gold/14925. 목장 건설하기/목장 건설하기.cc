#include<iostream>

using namespace std;

struct node {int y; int x;};
int M,N;
int map[1000][1000];
node len[1000][1000];

int main(){
    cin >> M >> N;
    for(int y=0; y<M; y++){
        for(int x=0; x<N; x++){
            cin >> map[y][x];
        }
    }

    for(int y=0; y<M; y++){
        int len_x = 1;
        for(int x=0; x<N; x++){
            if(map[y][x]) {
                len_x = 1; continue;
            }
            len[y][x].x = len_x++;
        }
    }

    for(int x=0; x<N; x++){
        int len_y = 1;
        for(int y=0; y<M; y++){
            if(map[y][x]) {
                len_y = 1; continue;
            }
            len[y][x].y = len_y++;
        }
    }

    int max_len = 0;

    for(int y=0; y<M; y++){
        for(int x=0; x<N; x++){

            int i = 0; int min_len = 1000;
            while(true){
                min_len = min(min_len, min(len[y-i][x].x,len[y][x-i].y));
                if(min_len <= max_len) break;
                if(min_len < i) break;
                if((i+1) > max_len) max_len = i+1;
                if(i == y || i == x) break;

                i++;
            }
        }
    }

    cout << max_len;
}