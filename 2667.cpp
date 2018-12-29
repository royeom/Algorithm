#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 26

int house_map[MAX][MAX] = {0, };
int check_visit[MAX][MAX] = {0, };
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int result[MAX*MAX] = {0, };

void BFS(int);
void calculate_cluster(int, int);

int main(){
    int size;
    scanf("%d", &size);
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            scanf("%1d", &house_map[i][j]);
        }
    }
    BFS(size);
}

void BFS(int size){
    std::queue<std::pair<int, int> > myqueue;
    int cluster_num = 1;
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            if(house_map[i][j] == 1 && check_visit[i][j] == 0){
                myqueue.push(std::pair<int, int>(i, j));
                check_visit[i][j] = cluster_num;

                while(!myqueue.empty()){
                    int cur_y = myqueue.front().first;
                    int cur_x = myqueue.front().second;
                    myqueue.pop();
                    for(int i=0; i<4; ++i){
                        int next_y = cur_y + direction[i][0];
                        int next_x = cur_x + direction[i][1];        
                        if(((next_y>=0 && next_y<MAX) && (next_x>=0 && next_x<MAX)) && house_map[next_y][next_x] == 1 && check_visit[next_y][next_x] == 0){
                            check_visit[next_y][next_x] = cluster_num;
                            myqueue.push(std::pair<int, int>(next_y, next_x));
                        }
                    }
                }
                cluster_num++;
            }
        }
    }
    calculate_cluster(size, cluster_num);
}

void calculate_cluster(int size, int max_cluster_num){
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            if(check_visit[i][j] != 0)
                result[check_visit[i][j]]++;
        }
    }
    std::sort(result, result+max_cluster_num);
    printf("%d\n", max_cluster_num-1);
    for(int i=1; i<max_cluster_num; ++i){
        printf("%d\n", result[i]);
    }
}