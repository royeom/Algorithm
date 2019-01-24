#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001

int tomato_box[MAX][MAX];
int check_day[MAX][MAX];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void BFS(int, int);

int main(){
    int size_x, size_y;
    scanf("%d %d", &size_x, &size_y);
    for(int i=0; i<size_y; ++i){
        for(int j=0; j<size_x; ++j){
            scanf("%d", &tomato_box[i][j]);
            check_day[i][j] = -1;
        }
    }
    BFS(size_x, size_y);
}

void BFS(int size_x, int size_y){
    std::queue<std::pair<int, int> > myqueue;

    for(int i=0; i<size_y; ++i){
        for(int j=0; j<size_x; ++j){
            if(tomato_box[i][j] == 1){
                myqueue.push(std::pair<int, int>(i, j));
                check_day[i][j] = 0;
            }
        }
    }

    while(!myqueue.empty()){
        int cur_y = myqueue.front().first;
        int cur_x = myqueue.front().second;
        myqueue.pop();
        for(int i=0; i<4; ++i){
            int next_y = cur_y + direction[i][0];
            int next_x = cur_x + direction[i][1];        
            if(((next_y>=0 && next_y<size_y) && (next_x>=0 && next_x<size_x)) && tomato_box[next_y][next_x] == 0 && check_day[next_y][next_x] == -1){
                check_day[next_y][next_x] = check_day[cur_y][cur_x] + 1;
                myqueue.push(std::pair<int, int>(next_y, next_x));
            }
        }
    }

    int day_count = 0;
    for(int i=0; i<size_y; ++i){
        for(int j=0; j<size_x; ++j){
            if(day_count < check_day[i][j])
                day_count = check_day[i][j];
        }
    }

    for(int i=0; i<size_y; ++i){
        for(int j=0; j<size_x; ++j){
            if(tomato_box[i][j] == 0 && check_day[i][j] == -1)
                day_count = -1;
        }
    }

    printf("%d\n", day_count);
}
