#include <iostream>
#include <queue>
#include <algorithm>

int n, m, ret;
int map[8][8];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void BFS(){
    std::queue<int> myqueue;
    int backup[8][8]; // 카피본
    int visited[8][8] = {0, };
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            backup[y][x] = map[y][x];
            if(backup[y][x] == 2){
                myqueue.push(y * 10 + x); // 10으로 나눈 것의 몫이 y, 나머지가 x 
                visited[y][x] = 1;
            }
        }
    }

    while(!myqueue.empty()){
        int cur = myqueue.front(); 
        myqueue.pop();
        int cur_y = cur / 10;
        int cur_x = cur % 10;
        backup[cur_y][cur_x] = 2;

        for(int i=0; i<4; ++i){
            int next_y = cur_y + direction[i][0];
            int next_x = cur_x + direction[i][1];        
            if(((next_y>=0 && next_y<n) && (next_x>=0 && next_x<m)) && backup[next_y][next_x] == 0 && visited[next_y][next_x] == 0){
                visited[next_y][next_x] = 1;
                myqueue.push(next_y * 10 + next_x);
            }
        }
    }

    int candidate = 0;
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            if(backup[y][x] == 0){
                ++candidate;
            }
        }
    }

    if(ret < candidate){
        ret = candidate;
    }
}

void DFS(int count, int starty, int startx){
    if(count == 3){
        BFS();
        return;
    }

    for(int y=starty; y<n; ++y){
        for(int x=startx; x<m; ++x){
            if(map[y][x] == 0){
                map[y][x] = 1;
                DFS(count+1, y, x);
                map[y][x] = 0;
            }
        }
        startx = 0;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            scanf("%d", &map[y][x]);
        }
    }

    DFS(0, 0, 0); // 현재 내가 추가한 기둥의 개수, 시작점 y, 시작점 x
    printf("%d\n", ret);
    return 0;
}