#include <iostream>

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=1; i<=test_case_num; ++i){
        int N;
        scanf("%d", &N);
        double percent, money;
        double sum = 0;
        for(int j=1; j<=N; ++j){
            scanf("%lf %lf", &percent, &money);
            sum += percent*money;
        }
        printf("#%d %lf\n",test_case_num, sum);
    }
    return 0;
}