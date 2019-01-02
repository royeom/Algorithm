#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 101

int normal_map[MAX][MAX] = {0, }; // R->0, G->1, B->2
int blind_map[MAX][MAX] = {0, };  // R,G->0 , B->2
bool normal_check[MAX][MAX] = {false, };
bool blind_check[MAX][MAX] = {false, };
int N;
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void BFS(){
    std::queue<std::pair<int, int> > normal_queue; // color, y*10 + x
    std::queue<std::pair<int, int> > blind_queue;
    int normal_count = 0;
    int blind_count = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(normal_check[i][j] == false){
                normal_queue.push(std::make_pair(normal_map[i][j], 10*i + j));
                normal_check[i][j] = true;
                while(!normal_queue.empty()){
                    int cur_color = normal_queue.front().first;
                    int cur_y = normal_queue.front().second / 10 ;
                    int cur_x = normal_queue.front().second % 10 ;
                    normal_queue.pop();
                    for(int k=0; k<4; ++k){
                        int next_y = cur_y + direction[k][0];
                        int next_x = cur_x + direction[k][1];
                        if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
                            continue;
                        if(!normal_check[next_y][next_x] && normal_map[next_y][next_x] == cur_color){
                            normal_check[next_y][next_x] = true;
                            normal_queue.push(std::make_pair(cur_color, 10*next_y + next_x));
                        }
                    }
                }
                normal_count++;
            }
            if(blind_check[i][j] == false){
                blind_queue.push(std::make_pair(blind_map[i][j], 10*i + j));
                blind_check[i][j] = true;
                while(!blind_queue.empty()){
                    int cur_color = blind_queue.front().first;
                    int cur_y = blind_queue.front().second / 10 ;
                    int cur_x = blind_queue.front().second % 10 ;
                    blind_queue.pop();
                    for(int k=0; k<4; ++k){
                        int next_y = cur_y + direction[k][0];
                        int next_x = cur_x + direction[k][1];
                        if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
                            continue;
                        if(!blind_check[next_y][next_x] && blind_map[next_y][next_x] == cur_color){
                            blind_check[next_y][next_x] = true;
                            blind_queue.push(std::make_pair(cur_color, 10*next_y + next_x));
                        }
                    }
                }
                blind_count++;
            }
        }
    }
    printf("%d %d\n", normal_count, blind_count);
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            char temp;
            std::cin >> temp;
            if(temp == 'G')
                normal_map[i][j] = 1;
            else if(temp == 'B'){
                normal_map[i][j] = 2;
                blind_map[i][j] = 2;
            }
        }
    }

    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         printf("%d", normal_map[i][j]);
    //     }
    //     printf("\n");
    // }

    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         printf("%d", blind_map[i][j]);
    //     }
    //     printf("\n");
    // }

    BFS();
}