#include <iostream>
#define MAX 21
int map[MAX][MAX];
int copy_map[MAX][MAX];
int N;

void DFS(int count){
    for(int i=0; i<N; ++i){
        int num_memory = 0;
        for(int j=0; j<N; ++j){
            if(copy_map[i][j] != 0){
                num_memory = copy_map[i][j];
            }
            else if
        }
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &map[i][j]);
            copy_map[i][j] = map[i][j];
        }
    }
    DFS(0);
}