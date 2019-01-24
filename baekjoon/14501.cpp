#include <iostream>
#include <algorithm>
#define MAX 16
int N;
int T[MAX];
int P[MAX];
int dp[MAX];

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; ++i){
        scanf("%d %d", &T[i], &P[i]);
    }
    dp[1] = 0;
    for(int i=2; i<=N+1; ++i){
        dp[i] = dp[i-1];
        for(int j=1; j<i; ++j){
            if(T[i-j] <= j){
                dp[i] = std::max(dp[i], dp[i-j] + P[i-j]);
            }
        }
    }
    printf("%d\n", dp[N+1]);
}