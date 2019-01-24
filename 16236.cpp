#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 21

int shark = 2;
int N, init_y, init_x;
int map[MAX][MAX] = {0, };
bool check_visit[MAX][MAX] = {false, };
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int haveEaten = 0;

class FISH{
public:
    int y, x, time;
    FISH(){}
    FISH(int _y, int _x, int _time){
        y=_y; x=_x; time=_time;
    }
};

bool compare(FISH a, FISH b){
    if (a.time <= b.time) {
        if (a.time == b.time) {
            // 가장 위 
            if (a.y <= b.y) {
                if (a.y == b.y) {
                    // 가장 왼쪽
                    if (a.x < b.x) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

std::vector<FISH> fishes;

int BFS(){
    int result = 0;
    while(1){
        std::queue<FISH> myqueue;
        myqueue.push(FISH(init_y, init_x, 0));
        check_visit[init_y][init_x] = true;
        while(!myqueue.empty()){
            int cur_y = myqueue.front().y;
            int cur_x = myqueue.front().x;
            int cur_time = myqueue.front().time;
            myqueue.pop();
            for(int i=0; i<4; ++i){
                int next_y = cur_y + direction[i][0];
                int next_x = cur_x + direction[i][1];
                if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
                    continue;
                if(check_visit[next_y][next_x])
                    continue;
                if(map[next_y][next_x] == 0 || map[next_y][next_x] == shark){
                    check_visit[next_y][next_x] = true;
                    myqueue.push(FISH(next_y, next_x, cur_time+1));
                }
                else if(map[next_y][next_x] < shark){
                    check_visit[next_y][next_x] = true;
                    fishes.push_back(FISH(next_y, next_x, cur_time+1));
                }
            }    
        }

        if(fishes.empty()) break;
        sort(fishes.begin(), fishes.end(), compare);
        init_y = fishes[0].y;
        init_x = fishes[0].x;
        result += fishes[0].time;
        haveEaten++;
        if(shark == haveEaten){
            haveEaten = 0;
            shark++;
        }
        map[init_y][init_x] = 0;
        fishes.clear();
        memset(check_visit, false, sizeof(check_visit));
    }
    return result;
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                init_y = i;
                init_x = j;
                map[i][j] = 0;
            }
        }
    }
    printf("%d\n", BFS());
}