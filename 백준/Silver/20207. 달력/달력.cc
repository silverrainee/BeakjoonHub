#include<iostream>
#include<queue>

using namespace std;

struct Schedule{
    int start;
    int end;
};

bool operator < (Schedule A, Schedule B){
    if (A.start == B.start) return A.end < B.end;
    return A.start > B.start;
}

bool calendar[366][1001];

int main() {
    int N; cin >> N; // 일정의 개수

    priority_queue<Schedule> pq;
    for(int i=0; i<N; i++){
        int start; cin >> start;
        int end; cin >> end;
        pq.push({start, end});
    }

    int sum = 0;
    int max_x = -1; int min_x = 366; int max_y = 0;
    for(int i=0; i<N; i++){
        int start = pq.top().start;
        int end = pq.top().end;
        pq.pop();

        bool flag = 0; int y = 0;
        for(y = 1; y <= 1000; y++){
            for(int x = start; x <= end; x++){
                if(calendar[x][y]) break;
                if(x == end) flag = true; 
            }
            if(flag) break;
        }

        for(int x = start; x <= end; x++){
            calendar[x][y] = true;
        }

        if(max_x < start - 1) {
            sum += (max_x - min_x + 1) * max_y;
            min_x = start; max_x = end; max_y = y;
        }
        else{
            max_x = max(max_x, end);
            max_y = max(max_y, y);
        }
    }

    sum += (max_x - min_x + 1) * max_y;

    cout << sum;
}