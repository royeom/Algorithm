#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 51

char map[MAX][MAX];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int Y, X;

int BFS(int y, int x){
    int visit_count[MAX][MAX] = {0, };
    int maxVal=0;

    std::queue<int> myqueue;
    visit_count[y][x] = 1;
    myqueue.push(10*y + x);

    while(!myqueue.empty()){
        int cur_y = myqueue.front() / 10;
        int cur_x = myqueue.front() % 10;
        myqueue.pop();

        if(visit_count[cur_y][cur_x] > maxVal)
            maxVal = visit_count[cur_y][cur_x];

        for(int i=0; i<4; ++i){
            int next_y = cur_y + direction[i][0];
            int next_x = cur_x + direction[i][1];
            if(next_y < 0 || next_y >= Y || next_x < 0 || next_x >= X)
                continue;
            if(map[next_y][next_x] == 'L' && visit_count[next_y][next_x] == 0){
                myqueue.push(10*next_y + next_x);
                visit_count[next_y][next_x] = visit_count[cur_y][cur_x] + 1;
            }
        }
    }

    return maxVal-1;
}

int main(){

    int result = 0;

    scanf("%d %d", &Y, &X);
    for(int i=0; i<Y; ++i){
        scanf("%s", map[i]);
    }
    for(int i=0; i<Y; ++i){
        for(int j=0; j<X; ++j){
            if(map[i][j] == 'L'){
                int temp;
                temp = BFS(i, j);
                if(temp > result)
                    result = temp;
            }
        }
    }

    printf("%d\n", result);
}