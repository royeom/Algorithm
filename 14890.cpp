#include <iostream>
#define MAX 101
int map[MAX][MAX];
int N, L;
bool rowFinished[MAX];
bool colFinished[MAX];
int count = 0;

int main(){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &map[i][j]);
        }
    }
    
    for(int i=0; i<N; ++i){
        bool flag = true; // flag가 1이면 도중에 문제가 생긴 것
        if(map[i][0] > map[i][N-1]){ // 왼쪽부터 스타트
            for(int j=0; j<N-1; ++j){
                if(flag == false){
                    break;
                }
                int diff = map[i][j] - map[i][j+1];
                if(diff == 0)
                    continue;
                else if(diff == 1){
                    for(int k =1; k<=L; ++k){
                        if(j+k >= N){
                            flag = false;
                            break;
                        }
                        if(map[i][j] - map[i][j+k] != 1){
                            flag = false;
                            break;
                        }
                    }
                }else if(diff >= 2){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                count++; 
        }else{ // 오른쪽부터 스타트
            for(int j=N-1; j>=1; --j){
                
            }
        }
    }
}