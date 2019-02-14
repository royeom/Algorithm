#include <iostream>
#define MAX 1000001
int L, R;
long long dp[MAX] = {0, };

int main(){
    for(int i=1; i <= 1000000; i+=2){
        for(int j=i; j <= 1000000; j+=i){
            dp[j] += i;
        }
    }
    for(int i=1; i <= 1000000; ++i){
        dp[i] += dp[i-1];
    }
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        scanf("%d %d", &L, &R);
        printf("#%d %lld\n", tcn, dp[R] - dp[L-1]);
    }
    return 0;
}