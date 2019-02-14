#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001
int N;
int map[MAX][MAX];
int arr[MAX][MAX];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void DFS(int cur_y, int cur_x){
    arr[cur_y][cur_x] = 1;
    for(int i=0; i<4; ++i){
        int next_y = cur_y + direction[i][0];
        int next_x = cur_x + direction[i][1];
        if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
            continue;
        if(map[next_y][next_x] == map[cur_y][cur_x] + 1){
            if(!arr[next_y][next_x]){
                DFS(next_y, next_x);
            }
            arr[cur_y][cur_x] = std::max(arr[cur_y][cur_x], arr[next_y][next_x] + 1);
        }
    }
}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        scanf("%d", &N);
        memset(map, 0, sizeof(map));
        memset(arr, 0, sizeof(arr));

        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                scanf("%d", &map[i][j]);
            }
        }

        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(!arr[i][j])
                    DFS(i, j);
            }
        }
        int min_idx = MAX*MAX;
        int max = 0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(arr[i][j] > max){
                    max = arr[i][j];
                    min_idx = map[i][j];
                }else if(arr[i][j] == max){
                    if(map[i][j] < min_idx)
                        min_idx = map[i][j];
                }
            }
        }
        printf("#%d %d %d\n", tcn, min_idx, max);
    }
    return 0;
}