#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 11
int N, M;
char matrix[MAX][MAX];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
std::pair<int, int> red, blue, goal;

void move(int direction){
    if(direction == 0){  // {1, 0}
        
    }
    if(direction == 1){  // {-1. 0}

    }
    if(direction == 2){  // {0, 1}

    }
    if(direction == 3){  // {0, -1}

    }
}

void BFS(){
    bool check_visit[MAX][MAX] = {false, };
    std::queue<std::pair<int, int> > red_queue;
    std::queue<std::pair<int, int> > blue_queue;
    red_queue.push(red);
    blue_queue.push(blue);

    while(!red_queue.empty()){
        std::pair<int, int> cur_red = red_queue.front();
        std::pair<int, int> cur_blue = blue_queue.front();

        for(int i=0; i<4; ++i){
            std::pair<int, int> next_red = std::make_pair(cur_red.first + direction[i][0] , cur_red.second + direction[i][1]);
            std::pair<int, int> next_blue = std::make_pair(cur_blue.first + direction[i][0] , cur_blue.second + direction[i][1]);
            if(next_red.first <=0 || next_red.first >= N-1 || next_red.second <= 0 || next_red.second >= M-1)
                continue;
            
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            std::cin >> matrix[i][j];
            if(matrix[i][j] == 'R')
                red = std::make_pair(i, j);
            if(matrix[i][j] == 'B')
                blue = std::make_pair(i, j);
            if(matrix[i][j] == 'O')
                goal = std::make_pair(i, j);
        }
    }
    BFS();
}