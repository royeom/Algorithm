#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 21

char matrix[MAX][MAX];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool alphabet[26] = {false, };
int R, C;
int maxVal = 1;

void DFS(int, int, int);

int main(){
    scanf("%d %d", &R, &C);
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            std::cin >> matrix[i][j];
        }
    }
    alphabet[matrix[0][0]-65] = true;
    DFS(0,0, maxVal);
    printf("%d\n", maxVal);
}

void DFS(int cur_y, int cur_x, int current_max){

    if(current_max > maxVal)
        maxVal = current_max;

    for(int i=0; i<4; ++i){
        int next_y = cur_y + direction[i][0];
        int next_x = cur_x + direction[i][1];        
        if(((next_y>=0 && next_y<R) && (next_x>=0 && next_x<C)) && !(alphabet[matrix[next_y][next_x]-65])){
            alphabet[matrix[next_y][next_x]-65] = true;
            DFS(next_y, next_x, current_max+1);
            alphabet[matrix[next_y][next_x]-65] = false;
        }
    }
}