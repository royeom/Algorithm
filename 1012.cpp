#include <iostream>
#include <queue>
#define MAX 51

int farm[MAX][MAX];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int width, height, num;
int result[MAX] = {0, };

void BFS(int);

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=0; i<test_case_num; ++i){
        scanf("%d %d %d", &width, &height, &num);
        for(int k=0; k<height; ++k){
            for(int l=0; l<width; ++l){
                farm[k][l] = 0;
            }
        }
        for(int j=0; j<num; ++j){
            int x, y;
            scanf("%d %d", &x, &y);
            farm[y][x] = 1;
        }
        BFS(i);
    }
    for(int i=0; i<test_case_num; ++i)
        printf("%d\n", result[i]);
}

void BFS(int case_num){
    bool check_visit[MAX][MAX] = {false, };
    std::queue<std::pair<int, int> > myqueue;
    int count = 0;
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            if(farm[i][j] == 1 && !check_visit[i][j]){
                myqueue.push(std::pair<int, int>(i, j));
                check_visit[i][j] = true;
                while(!myqueue.empty()){
                    int cur_y = myqueue.front().first;
                    int cur_x = myqueue.front().second;
                    myqueue.pop();
                    for(int i=0; i<4; ++i){
                        int next_y = cur_y + direction[i][0];
                        int next_x = cur_x + direction[i][1];        
                        if(((next_y>=0 && next_y<height) && (next_x>=0 && next_x<width)) && farm[next_y][next_x] == 1 && !check_visit[next_y][next_x]){
                            check_visit[next_y][next_x] = true;
                            myqueue.push(std::pair<int, int>(next_y, next_x));
                        }
                    }
                }
                count++;
            }
        }
    }
    result[case_num] = count;
}