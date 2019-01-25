#include <iostream>
#define MAX 101
int map[MAX][MAX] = {0, };
int N;
int count = 0;

int Magnetic(){
    int count = 0;
    bool flag = false;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(map[j][i] == 0)
                continue;
            else if(map[j][i] == 1)
                flag = true;
            else if(map[j][i] == 2){
                if(flag){
                    count++;
                    flag = false;
                }
                else
                    continue;
            }
        }
        flag = false;
    }
    return count;
}

int main(){
    int test_case_num = 10;
    for(int i=1; i<=test_case_num; ++i){
        scanf("%d", &N);
        for(int j=0; j<N; ++j){
            for(int k=0; k<N; ++k){
                scanf("%d", &map[j][k]);
            }
        }
        printf("#%d %d\n", i, Magnetic());
    }
    return 0;
}