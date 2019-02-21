#include <iostream>
#include <cmath>

int N;
int result = 0;
int col[15];

bool isPromising(int col_num){
    for(int i=0; i<col_num; ++i){
        if(col[col_num] == col[i] || std::abs(col[col_num]-col[i]) == col_num - i)
            return false;
    }
    return true;
}

void Queen(int col_num){
    if(col_num == N){
        result++;
        return;
    }
    for(int row_num=0; row_num<N; ++row_num){
        col[col_num] = row_num;
        if(isPromising(col_num)){
            Queen(col_num+1);
        }
    }
}

int main(){
    scanf("%d", &N);
    Queen(0);
    printf("%d\n", result);
}