#include <iostream>
#define MAX 51

int matrix[MAX][MAX] = {0, };
int direction[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int back_direction[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}};
int N, M;
int cur_y, cur_x, cur_dir;
int count = 0;

void DFS(int cur_y, int cur_x, int cur_dir){
    if(matrix[cur_y][cur_x] == 1)
        return;
    if(matrix[cur_y][cur_x] == 0){
        matrix[cur_y][cur_x] = 2;
        count++;
    }

    for(int i=0; i<4; ++i){
        int next_dir;
        if(cur_dir == 0) next_dir = 3;
        else if(cur_dir == 1) next_dir = 0;
        else if(cur_dir == 2) next_dir = 1;
        else if(cur_dir == 3) next_dir = 2;

        int next_y = cur_y + direction[next_dir][0];
        int next_x = cur_x + direction[next_dir][1];

        if(matrix[next_y][next_x] == 0){
            DFS(next_y, next_x, next_dir);
            return;
        }
        else{
            cur_dir = next_dir;
        }
    }
    int next_y = cur_y + back_direction[cur_dir][0];
    int next_x = cur_x + back_direction[cur_dir][1];
    DFS(next_y, next_x, cur_dir);
}

int main(){
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &cur_y, &cur_x, &cur_dir);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    DFS(cur_y, cur_x, cur_dir);
    printf("%d\n", count);
}