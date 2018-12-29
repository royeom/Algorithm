#include <iostream>
#include <algorithm>
#include <queue>

int maze_map[101][101] = {0, };
int N, M;
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int BFS();

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf("%1d", &maze_map[i][j]); // 문자 한 개씩 받는 방법
        }
    }
    printf("%d\n", BFS());
}

int BFS(){
    int check_visit[101][101] = {0, };
    std::queue<std::pair<int, int> > myqueue;
    int cur_y=0, cur_x=0;
    myqueue.push(std::pair<int, int>(cur_y, cur_x));
    check_visit[cur_y][cur_x] = 1;
    while(!myqueue.empty()){
        cur_y = myqueue.front().first;
        cur_x = myqueue.front().second;
        myqueue.pop();

        if(cur_y == N-1 && cur_x == M-1)
            return check_visit[cur_y][cur_x];
        
        for(int i=0; i<4; ++i){
            int next_y = cur_y + direction[i][0];
            int next_x = cur_x + direction[i][1];        
            if(((next_y>=0 && next_y<N) && (next_x>=0 && next_x<M)) && maze_map[next_y][next_x] == 1 && check_visit[next_y][next_x] == 0){
                check_visit[next_y][next_x] = check_visit[cur_y][cur_x] + 1;
                myqueue.push(std::pair<int, int>(next_y, next_x));
            }
        }
    }
    
}