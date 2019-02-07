#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001
int score[101];
bool check_visit[MAX];


int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        int problem_num;
        scanf("%d", &problem_num);
        memset(score, 0 , sizeof(score));
        memset(check_visit, false, sizeof(check_visit));
        int count = 0;
        int max = 0;
        check_visit[0] = true;

        for(int pn = 0; pn < problem_num; ++pn){
            scanf("%d", &score[pn]);
            max += score[pn];
            for(int i = MAX; i >=0; --i){
                if(check_visit[i])
                    check_visit[i + score[pn]] = true;
            }
            check_visit[score[pn]]= true;
        }

        for(int i=0; i<MAX; ++i){
            if(check_visit[i])
                count++;
        }
        printf("#%d %d\n", tcn, count);
    }
}