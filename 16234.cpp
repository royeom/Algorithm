#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#define MAX 51

int map[MAX][MAX] = {0, };
bool check_visit[MAX][MAX] = {false, };
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int N, L, R;
std::vector<std::vector<std::pair<int, int> > > vec;
int move_count = 0;

void DFS(int cur_y, int cur_x, int count){
    for(int i=0; i<4; ++i){
        int next_y = cur_y + direction[i][0];
        int next_x = cur_x + direction[i][1];
        if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
            continue;
        if(check_visit[next_y][next_x])
            continue;
        int diff = abs(map[cur_y][cur_x] - map[next_y][next_x]);
        if(diff >= L && diff <= R){
            check_visit[next_y][next_x] = true;
            vec[count].push_back(std::make_pair(next_y, next_x));
            DFS(next_y, next_x, count);
        }
    }
}

void MOVE(){
    for(int i=0; i<vec.size(); ++i){
        int vec_size = vec[i].size();
        int sum = 0;
        for(int j=0; j<vec_size; ++j){
            sum += map[vec[i][j].first][vec[i][j].second];
        }
        sum = sum / vec_size;
        for(int j=0; j<vec_size; ++j){
            map[vec[i][j].first][vec[i][j].second] = sum;
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &L, &R);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &map[i][j]);
        }
    }
    while(1){
        int count = 0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(!check_visit[i][j]){
                    check_visit[i][j] = true;
                    std::vector<std::pair<int, int> > temp;
                    temp.push_back(std::make_pair(i, j));
                    vec.push_back(temp);
                    DFS(i, j, count);
                    count++;
                }
            }
        }
        if(count == N*N){
            printf("%d\n", move_count);
            break;
        }
        MOVE();
        // for(int k=0; k<count; ++k){
        //     printf("%d's contents : ", k);
        //     for(int l=0; l<vec[k].size(); ++l){
        //         printf("%d %d , ", vec[k][l].first , vec[k][l].second);
        //     }
        //     printf("\n");
        // }
        // for(int i=0; i<N; ++i){
        //     for(int j=0; j<N; ++j){
        //         printf("%d ", map[i][j]);
        //     }
        //     printf("\n");
        // }
        move_count++;
        vec.clear();
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                check_visit[i][j] = false;
            }
        }
        // printf("count : %d, move_count : %d\n", count, move_count);        
    }
}