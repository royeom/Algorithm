#include <iostream>
#include <vector>
#include <string.h>
#define MAX 10001

int N;
std::vector<std::vector<int> > vec;
std::vector<int> check_vec;
std::vector<bool> isFinished;
int maxVal = 0;

int DFS(int num){
    if(!isFinished[num]){
        if(vec[num].empty()){
            isFinished[num] = true;
            return 0;
        }
        else{
            int vec_size = vec[num].size();
            for(int i=0; i<vec_size; ++i){
                if(vec[num][i] == num){
                    continue;
                }
                check_vec[num] += DFS(vec[num][i]) + 1;
            }
            isFinished[num] = true;
            maxVal = check_vec[num] > maxVal ? check_vec[num] : maxVal;
            return check_vec[num];
        }
    }
    else{
        return check_vec[num];
    }
}

int main(){
    int M;
    scanf("%d %d", &N, &M);
    vec = std::vector<std::vector<int> >(N+1);
    check_vec = std::vector<int>(N+1, 0);
    isFinished = std::vector<bool>(N+1, false);
    for(int i=0; i<M; ++i){
        int A, B;
        scanf("%d %d", &A, &B);
        vec[B].push_back(A);
    }
    for(int i=1; i<=N; ++i){
        DFS(i);
    }
    if(maxVal == 0)
        return 0;
    for(int i=1; i<=N; ++i){
        if(check_vec[i] == maxVal)
            printf("%d ", i);
    }
    printf("\n");
}