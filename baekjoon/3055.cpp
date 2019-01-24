#include <iostream>
#include <queue>
#include <vector>
#define MAX 51

int R, C;
std::pair<int, int> start;
char map[MAX][MAX] = {0, };
bool check_visit[MAX][MAX] = {false, };
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int count = 0;

bool BFS(){
    std::queue<std::pair<int, int> > myqueue;
    myqueue.push(start);
    check_visit[start.first][start.second] = true;

    while(!myqueue.empty()){

        bool check_flood[MAX][MAX] = {false, };
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(map[i][j] == '*'){
                    for(int k=0; k<4; ++k){
                        int next_i = i + direction[k][0];
                        int next_j = j + direction[k][1];
                        if(map[next_i][next_j] == '.' && !check_flood[i][j]){
                            map[next_i][next_j] = '*';
                            check_flood[next_i][next_j] = true;
                        }
                    }
                }
            }
        }
        // for(int i=0; i<R; ++i){
        //     for(int j=0; j<C; ++j){
        //         printf("%c", map[i][j]);
        //     }
        //     printf("\n");
        // }

        int Q_size = myqueue.size();
        while(Q_size--){
            int cur_y = myqueue.front().first;
            int cur_x = myqueue.front().second;
            // printf("cur_y = %d, cur_x = %d\n", cur_y, cur_x);
            myqueue.pop();
            if(map[cur_y][cur_x] == 'D')
                return true;

            for(int i=0; i<4; ++i){
                int next_y = cur_y + direction[i][0];
                int next_x = cur_x + direction[i][1];
                if(next_y < 0 || next_y >= R || next_x < 0 || next_x >= C)
                    continue;
                if(check_visit[next_y][next_x])
                    continue;
                if(map[next_y][next_x] == '.' || map[next_y][next_x] == 'D'){
                    myqueue.push(std::make_pair(next_y, next_x));
                    check_visit[next_y][next_x] = true;
                }
            }
        }
        count++;
    }
    return false;
}

int main(){
    scanf("%d %d", &R, &C);
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            std::cin >> map[i][j];
            if(map[i][j] == 'S'){
                start.first = i;
                start.second = j;
            }
        }
    }
    BFS() ? printf("%d\n", count) : printf("KAKTUS\n");
    return 0;
}