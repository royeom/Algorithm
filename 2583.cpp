#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101

int square_map[MAX][MAX] = {0, };
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int result[MAX] = {0, };
int M, N, K;

void BFS();

int main(){
    scanf("%d %d %d", &M, &N, &K);
    for(int i=0; i<K; ++i){
        int x1,y1, x2,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int j=y1; j<y2; ++j){
            for(int k=x1; k<x2; ++k){
                square_map[j][k] = 1;
            }
        }
    }
    BFS();
}

void BFS(){
    bool check_visit[MAX][MAX] = {false, };
    std::queue<std::pair<int, int> > myqueue;
    int num = 0;
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            int count = 0;
            if(square_map[i][j] == 0 && !check_visit[i][j]){
                myqueue.push(std::pair<int, int>(i, j));
                check_visit[i][j] = true;
                while(!myqueue.empty()){
                    int cur_y = myqueue.front().first;
                    int cur_x = myqueue.front().second;
                    myqueue.pop();
                    count++;
                    for(int i=0; i<4; ++i){
                        int next_y = cur_y + direction[i][0];
                        int next_x = cur_x + direction[i][1];        
                        if(((next_y>=0 && next_y<M) && (next_x>=0 && next_x<N)) && square_map[next_y][next_x] == 0 && !check_visit[next_y][next_x]){
                            check_visit[next_y][next_x] = true;
                            myqueue.push(std::pair<int, int>(next_y, next_x));
                        }
                    }
                }
                result[num] = count;
                num++;
            }
        }
    }
    std::sort(result, result+num);
    printf("%d\n", num);
    for(int i=0; i<num; ++i){
        printf("%d ", result[i]);
    }
    printf("\n");
}