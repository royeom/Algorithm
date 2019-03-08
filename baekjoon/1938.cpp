#include <iostream>
#include <queue>
#define MAX 55
int N;
char map[MAX][MAX];
int check_visit[MAX][MAX][2] = {0, };

struct Oak{

    std::pair<int, int> area1, area2, area3;
    int state; // Vertical : 0, Horiziontal : 1
};

bool isFinished = false;
Oak oak, next_oak, cur_oak;

bool isGoal(){
    if(map[cur_oak.area1.first][cur_oak.area1.second] == 'E' && map[cur_oak.area2.first][cur_oak.area2.second] == 'E' && map[cur_oak.area3.first][cur_oak.area3.second] == 'E') 
        return true;
    else
        return false;
}

void BFS(){
    std::queue<Oak> myqueue;
    myqueue.push(oak);
    check_visit[oak.area2.first][oak.area2.second][oak.state] = 1;
    while(!myqueue.empty()){
        cur_oak = myqueue.front();
        // printf("cur_oak : %d %d , %d %d, %d %d, %d\n", cur_oak.area1.first, cur_oak.area1.second, cur_oak.area2.first, cur_oak.area2.second, cur_oak.area3.first, cur_oak.area3.second, cur_oak.state);
        if(isGoal()){
            isFinished = true;
            return;
        }
        myqueue.pop();
        for(int i=0; i<5; ++i){
            if(i==0){ // Operation U
                if(cur_oak.area1.first-1 < 0)
                    continue;
                if(map[cur_oak.area1.first-1][cur_oak.area1.second] == '1' || map[cur_oak.area2.first-1][cur_oak.area2.second] == '1' || map[cur_oak.area3.first-1][cur_oak.area3.second] == '1')
                    continue;
                next_oak.area1.first = cur_oak.area1.first - 1;
                next_oak.area1.second = cur_oak.area1.second;
                next_oak.area2.first = cur_oak.area2.first - 1;
                next_oak.area2.second = cur_oak.area2.second;
                next_oak.area3.first = cur_oak.area3.first - 1;
                next_oak.area3.second = cur_oak.area3.second;
                next_oak.state = cur_oak.state;
            }
            else if(i==1){ // Operation D
                if(cur_oak.area3.first + 1 >= N)
                    continue;
                if(map[cur_oak.area1.first+1][cur_oak.area1.second] == '1' || map[cur_oak.area2.first+1][cur_oak.area2.second] == '1' || map[cur_oak.area3.first+1][cur_oak.area3.second] == '1')
                    continue;
                next_oak.area1.first = cur_oak.area1.first + 1;
                next_oak.area1.second = cur_oak.area1.second;
                next_oak.area2.first = cur_oak.area2.first + 1;
                next_oak.area2.second = cur_oak.area2.second;
                next_oak.area3.first = cur_oak.area3.first + 1;
                next_oak.area3.second = cur_oak.area3.second;
                next_oak.state = cur_oak.state;
            }
            else if(i==2){ // Operation L
                if(cur_oak.area1.second - 1 < 0)
                    continue;
                if(map[cur_oak.area1.first][cur_oak.area1.second-1] == '1' || map[cur_oak.area2.first][cur_oak.area2.second-1] == '1' || map[cur_oak.area3.first][cur_oak.area3.second-1] == '1')
                    continue;
                next_oak.area1.first = cur_oak.area1.first;
                next_oak.area1.second = cur_oak.area1.second - 1;
                next_oak.area2.first = cur_oak.area2.first;
                next_oak.area2.second = cur_oak.area2.second - 1;
                next_oak.area3.first = cur_oak.area3.first;
                next_oak.area3.second = cur_oak.area3.second - 1;
                next_oak.state = cur_oak.state;
            }
            else if(i==3){ // Operation R
                if(cur_oak.area3.second + 1 >= N)
                    continue;
                if(map[cur_oak.area1.first][cur_oak.area1.second+1] == '1' || map[cur_oak.area2.first][cur_oak.area2.second+1] == '1' || map[cur_oak.area3.first][cur_oak.area3.second+1] == '1')
                    continue;
                next_oak.area1.first = cur_oak.area1.first;
                next_oak.area1.second = cur_oak.area1.second + 1;
                next_oak.area2.first = cur_oak.area2.first;
                next_oak.area2.second = cur_oak.area2.second + 1;
                next_oak.area3.first = cur_oak.area3.first;
                next_oak.area3.second = cur_oak.area3.second + 1;
                next_oak.state = cur_oak.state;
            }
            else if(i==4){
                if(cur_oak.state == 0){ // Vertical
                    if(cur_oak.area2.second == 0 || cur_oak.area2.second == N-1)
                        continue;
                    if(map[cur_oak.area1.first][cur_oak.area1.second-1] == '1' || map[cur_oak.area2.first][cur_oak.area2.second-1] == '1' || map[cur_oak.area3.first][cur_oak.area3.second-1] == '1' || map[cur_oak.area1.first][cur_oak.area1.second+1] == '1' || map[cur_oak.area2.first][cur_oak.area2.second+1] == '1' || map[cur_oak.area3.first][cur_oak.area3.second+1] == '1')
                        continue;
                    next_oak.area1.first = cur_oak.area1.first + 1;
                    next_oak.area1.second = cur_oak.area1.second - 1;
                    next_oak.area2.first = cur_oak.area2.first;
                    next_oak.area2.second = cur_oak.area2.second;
                    next_oak.area3.first = cur_oak.area3.first - 1;
                    next_oak.area3.second = cur_oak.area3.second + 1;
                    next_oak.state = 1;
                }
                else{ // Horizontal
                    if(cur_oak.area2.first == 0 || cur_oak.area2.first == N-1)
                        continue;
                    if(map[cur_oak.area1.first-1][cur_oak.area1.second] == '1' || map[cur_oak.area2.first-1][cur_oak.area2.second] == '1' || map[cur_oak.area3.first-1][cur_oak.area3.second] == '1' || map[cur_oak.area1.first+1][cur_oak.area1.second] == '1' || map[cur_oak.area2.first+1][cur_oak.area2.second] == '1' || map[cur_oak.area3.first+1][cur_oak.area3.second] == '1')
                        continue;
                    next_oak.area1.first = cur_oak.area1.first - 1;
                    next_oak.area1.second = cur_oak.area1.second + 1;
                    next_oak.area2.first = cur_oak.area2.first;
                    next_oak.area2.second = cur_oak.area2.second;
                    next_oak.area3.first = cur_oak.area3.first + 1;
                    next_oak.area3.second = cur_oak.area3.second - 1;
                    next_oak.state = 0;
                }
            }
            
            if(check_visit[next_oak.area2.first][next_oak.area2.second][next_oak.state])
                continue;
            myqueue.push(next_oak);
            check_visit[next_oak.area2.first][next_oak.area2.second][next_oak.state] = check_visit[cur_oak.area2.first][cur_oak.area2.second][cur_oak.state] + 1;
        }
    }
}

int main(){
    scanf("%d", &N);
    int oak_flag = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            std::cin >> map[i][j];
            if(map[i][j] == 'B'){
                if(oak_flag == 0){
                    oak.area1 = std::make_pair(i, j);
                    oak_flag = 1;
                    continue;
                }
                if(oak_flag == 1){
                    oak.area2 = std::make_pair(i, j);
                    oak_flag = 2;
                    continue;
                }
                if(oak_flag == 2){
                    oak.area3 = std::make_pair(i, j);
                    continue;
                }
            }
        }
    }
    oak.state = oak.area1.first < oak.area2.first ? 0 : 1;
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("oak area1 : %d, %d \n oak area2 : %d %d \n oak area3 : %d %d \n oak state : %d \n", oak.area1.first, oak.area1.second, oak.area2.first, oak.area2.second, oak.area3.first, oak.area3.second, oak.state);
    BFS();

    if(isFinished) printf("%d\n", check_visit[cur_oak.area2.first][cur_oak.area2.second][cur_oak.state] - 1);
    else printf("0\n");

    return 0;
}