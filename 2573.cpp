#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 301

int matrix[MAX][MAX] = {0, };
int copy[MAX][MAX] = {0, };
int N, M;
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int year = 0;

int area_count(){
    bool check_visit[MAX][MAX] = {false, };
    std::queue<std::pair<int, int> > myqueue;
    int count = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(matrix[i][j] >= 1 && !check_visit[i][j]){
                myqueue.push(std::pair<int, int>(i, j));
                check_visit[i][j] = true;
                while(!myqueue.empty()){
                    int cur_y = myqueue.front().first;
                    int cur_x = myqueue.front().second;
                    myqueue.pop();
                    for(int i=0; i<4; ++i){
                        int next_y = cur_y + direction[i][0];
                        int next_x = cur_x + direction[i][1];        
                        if(((next_y>=0 && next_y<N) && (next_x>=0 && next_x<M)) && matrix[next_y][next_x] >= 1 && !check_visit[next_y][next_x]){
                            check_visit[next_y][next_x] = true;
                            myqueue.push(std::pair<int, int>(next_y, next_x));
                        }
                    }
                }
                count++;
            }
        }
    }
    return count;
}

void melt(){
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(matrix[i][j] >= 1){
                for(int k=0; k<4; ++k){
                    int next_y = i + direction[k][0];
                    int next_x = j + direction[k][1];        
                    if(((next_y>=0 && next_y<N) && (next_x>=0 && next_x<M)) && copy[next_y][next_x] == 0){
                        if(matrix[i][j] == 0)
                            continue;
                        else   
                            matrix[i][j]--;
                    }
                }
            }
        }
    }
    year++;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            copy[i][j] = matrix[i][j];
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            int temp;
            scanf("%d", &temp);
            matrix[i][j] = copy[i][j] = temp;
        }
    }
    
    while(1){
        int number_area = area_count();
        if(number_area == 0){
            printf("0\n");
            break;
        }
        else if(number_area == 1)
            melt();
        else if(number_area > 1){
            printf("%d\n", year);
            break;
        }
    }
    
    return 0;
}