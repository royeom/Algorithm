#include <iostream>
#include <vector>
#include <cstring>
#define MAX 101

std::vector<std::string> ans;
std::vector<std::string> mine;
int reward[MAX] = {0, };
int N, M;

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tn=1; tn <= test_case_num; ++tn){
        scanf("%d %d", &N, &M);
        ans.resize(N);
        mine.resize(M);
        for(int i=0; i<N; ++i){
            std::cin >> ans[i] >> reward[i];
        }
        for(int i=0; i<M; ++i){
            std::cin >> mine[i];
        }

        int total_reward = 0;

        for(int i=0; i<M; ++i){
            for(int j=0; j<N; ++j){
                bool flag = true;
                for(int k=0; k<8; ++k){
                    if(ans[j][k] == '*')
                        continue;
                    if(ans[j][k] != mine[i][k])
                        flag = false;
                }
                if(flag)
                    total_reward += reward[j];
            }
        }
        printf("#%d %d\n", tn, total_reward);
    }
}