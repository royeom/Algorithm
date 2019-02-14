#include <iostream>
#include <cstring>
#include <algorithm>

int kyuyoung[10] = {0, };
int inyoung[10] = {0, };
int win_count = 0;
int lose_count = 0;
bool check[19] = {false, };
int k_score, i_score;

void DFS(int count){
    k_score = i_score = 0;
    for(int i=0; i<9; ++i){
        if(kyuyoung[i] > inyoung[i]){
            k_score += kyuyoung[i] + inyoung[i];
        }else{
            i_score += kyuyoung[i] + inyoung[i];
        }
    }
    if(k_score > i_score)
        win_count++;
    else if(k_score < i_score)
        lose_count++;

    for(int i=count; i<9; ++i){
        std::swap(inyoung[count], inyoung[i]);
        DFS(count+1);
        std::swap(inyoung[count], inyoung[i]);
    }
}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        // 초기화
        memset(check, false, sizeof(check));
        win_count = lose_count = 0;
        for(int i=0; i<9; ++i){
            scanf("%d", &kyuyoung[i]);
            check[kyuyoung[i]] = true;
        }
        int in_count=0;
        for(int i=1; i <= 18; ++i){
            if(!check[i]){
                check[i] = true;
                inyoung[in_count] = i;
                in_count++;
            }
        }
        DFS(0);
        printf("#%d %d %d", tcn, win_count, lose_count);
    }
}