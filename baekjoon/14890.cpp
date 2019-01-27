#include <iostream>
#include <cstring>
#define MAX 101
int map[MAX][MAX];
int N, L;
bool rowFinished[MAX];
bool colFinished[MAX];
int count = 0;
bool check_visit[MAX] = {false, };

int temp[MAX][MAX] ={0, };

void rotate_matrix(){    
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            temp[j][N-1-i] = map[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            map[i][j] = temp[i][j];
        }
    }
}

int main(){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &map[i][j]);
        }
    }
    for(int x=0; x<2; ++x){ // 90도 회전시켜서 똑같이 한번 더 해주기 위함.
        for(int i=0; i<N; ++i){
            bool flag = true; // flag가 1이면 도중에 문제가 생긴 것
            std::memset(check_visit, false, N+1);
            for(int j=0; j<N-1; ++j){
                int diff = map[i][j] - map[i][j+1];
                if(diff == 0)
                    continue;
                else if(diff == 1){
                    for(int k =1; k<=L; ++k){
                        if(map[i][j] - map[i][j+k] != 1 || check_visit[j+k]){
                            flag = false;
                            break;
                        }
                        check_visit[j+k] = true;
                    }
                }
                else if(diff == -1){
                    for(int k =0; k<L; ++k){
                        if(map[i][j+1] - map[i][j-k] != 1 || check_visit[j-k]){
                            flag = false;
                            break;
                        }
                        check_visit[j-k] = true;
                    }
                }
                else if(diff >= 2 || diff <=-2){
                    flag = false;
                    break;
                    }
                }
            if(flag == true)
                count++; 
        }
        rotate_matrix();
    }
    printf("%d\n", count);
    return 0;
}