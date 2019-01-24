#include <iostream>
#include <algorithm>
#define MAX 501

int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int N, M;
int map[MAX][MAX];
int answer = 0;

void BFS(int y1, int x1, int y2, int x2, int y3, int x3){
    bool check_visit[MAX][MAX] = {false, };
    int sum = map[y1][x1] + map[y2][x2] + map[y3][x3];
    check_visit[y1][x1] = check_visit[y2][x2] = check_visit[y3][x3] = true;
    for(int i=0; i<4; ++i){
        int next_y1 = y1 + direction[i][0];
        int next_x1 = x1 + direction[i][1];
        int next_y2 = y2 + direction[i][0];
        int next_x2 = x2 + direction[i][1];
        int next_y3 = y3 + direction[i][0];
        int next_x3 = x3 + direction[i][1];
        if(next_y1>=0 && next_y1<N && next_x1>=0 && next_x1<M){
            if(!check_visit[next_y1][next_x1]){
                sum += map[next_y1][next_x1];
                check_visit[next_y1][next_x1] = true;
                answer = std::max(answer, sum);
                sum -= map[next_y1][next_x1];
            }
        }
        if(next_y2>=0 && next_y2<N && next_x2>=0 && next_x2<M){
            if(!check_visit[next_y2][next_x2]){
                sum += map[next_y2][next_x2];
                check_visit[next_y2][next_x2] = true;
                answer = std::max(answer, sum);
                sum -= map[next_y2][next_x2];
            }
        }
        if(next_y3>=0 && next_y3<N && next_x3>=0 && next_x3<M){
            if(!check_visit[next_y3][next_x3]){
                sum += map[next_y3][next_x3];
                check_visit[next_y3][next_x3] = true;
                answer = std::max(answer, sum);
                sum -= map[next_y3][next_x3];
            }
        }
    }
}

void tetromino(int y, int x, int count){ // ㅣ , ㅡ, ㄱ, ㄴ 에서 한칸 더 나가는 것만 확인하면 됨.
    if(y+2 < N && x+2 < N){
        BFS(y, x, y+1, x, y+2, x);
        BFS(y, x, y, x+1, y, x+2);
        BFS(y, x, y+1, x, y+1, x+1);
        BFS(y, x, y, x+1, y+1, x+1);
    }
    else if(y+2 >= N && x+2 < N){
        BFS(y, x, y, x+1, y, x+2);
        BFS(y, x, y+1, x, y+1, x+1);
        BFS(y, x, y, x+1, y+1, x+1);
    }
    else if(y+2 < N && x+2 >= N){
        BFS(y, x, y+1, x, y+2, x);
        BFS(y, x, y+1, x, y+1, x+1);
        BFS(y, x, y, x+1, y+1, x+1);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            tetromino(i,j,1);
        }
    }
    printf("%d\n", answer);
}