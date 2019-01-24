#include <iostream>
#include <queue>
#define MAX 101

int N;
int matrix[MAX][MAX] = {0, };
bool check_visit[MAX][MAX] = {false, };
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int number = 0;

void init(){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            check_visit[i][j] = false;
        }
    }
}

void DFS(int cur_y, int cur_x, int number){
    check_visit[cur_y][cur_x] = true;
    matrix[cur_y][cur_x] = number;

    for(int i=0; i<4; ++i){
        int next_y = cur_y + direction[i][0];
        int next_x = cur_x + direction[i][1];

        if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
            continue;
        if(matrix[next_y][next_x] == 1 && !check_visit[next_y][next_x])
            DFS(next_y, next_x, number);
    }
}

int BFS(int number){

    std::queue<int> myqueue;
    init();
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(matrix[i][j] == number){
                check_visit[i][j] = true;
                myqueue.push(10 * i + j);
            }
        }
    }

    int count = 0;
    while(!myqueue.empty()){
        int q_size = myqueue.size();
        for(int i=0; i<q_size; ++i){
            int cur_y = myqueue.front() / 10;
            int cur_x = myqueue.front() % 10;
            myqueue.pop();

            for(int j=0; j<4; ++j){
                int next_y = cur_y + direction[j][0];
                int next_x = cur_x + direction[j][1];

                if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
                    continue;
                if(matrix[next_y][next_x] != 0 && matrix[next_y][next_x] != number){
                    return count;
                }
                else if(matrix[next_y][next_x] == 0 && !check_visit[next_y][next_x]){
                    check_visit[next_y][next_x] = true;
                    myqueue.push(10 * next_y + next_x);
                }
            }
        }
        count++;
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(matrix[i][j] == 1 && !check_visit[i][j])
                DFS(i, j, ++number);
        }
    }
    
    int minVal = 987654321;
    for(int i=1; i<=number; ++i){
        int temp = BFS(i);
        if(minVal > temp)
            minVal = temp;
    }
 
    printf("%d\n", minVal);
}