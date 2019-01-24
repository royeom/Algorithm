#include <iostream>
#include <queue>
#define MAX 1001
#define IN_MAX 987654321
int N, M;
int map[MAX][MAX] = {0, };
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int check_distance[MAX][MAX][2];


class Move{
public:
    int y, x;
    bool broken;
    Move(){};
    Move(int _y, int _x, int _broken){
        y = _y;
        x = _x;
        broken = _broken;
    }
};

void BFS(){
    std::queue<Move> myqueue;
    myqueue.push(Move(1, 1, false));
    check_distance[1][1][0] = 1;
    while(!myqueue.empty()){
        Move cur_m = myqueue.front();
        int cur_y = cur_m.y;
        int cur_x = cur_m.x;
        bool cur_broken = cur_m.broken;
        myqueue.pop();
        for(int i=0; i<4; ++i){
            int next_y = cur_y + direction[i][0];
            int next_x = cur_x + direction[i][1];
            if(next_y < 1 || next_y > N || next_x < 1 || next_x > M)
                continue;
            if(map[next_y][next_x] == 0 && (check_distance[cur_y][cur_x][cur_broken] + 1 < check_distance[next_y][next_x][cur_broken])){
                check_distance[next_y][next_x][cur_broken] = check_distance[cur_y][cur_x][cur_broken] + 1;
                myqueue.push(Move(next_y, next_x, cur_broken));
            }
            if(map[next_y][next_x] == 1 && !cur_broken && (check_distance[cur_y][cur_x][0] + 1 < check_distance[next_y][next_x][1])){
                check_distance[next_y][next_x][1] = check_distance[cur_y][cur_x][0] + 1;
                myqueue.push(Move(next_y, next_x, true));
            }
        }
    }
    if(check_distance[N][M][0] == IN_MAX && check_distance[N][M][1] == IN_MAX)
        printf("-1\n");
    else
        printf("%d\n", check_distance[N][M][0] < check_distance[N][M][1] ? check_distance[N][M][0] : check_distance[N][M][1]);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            for(int k=0; k<2; ++k){
                check_distance[i][j][k] = IN_MAX;
            }
        }
    }
    BFS();
}