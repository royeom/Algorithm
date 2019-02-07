#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
int N, K;
std::vector<std::pair<int, double> > vec;

bool cmp(const std::pair<int, double> &a, const std::pair<int, double> &b){
    return a.second > b.second;
}

std::string score[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=1; i <= test_case_num; ++i){
        scanf("%d %d", &N, &K);
        vec.resize(N);
        double score1, score2, score3;
        for(int j=1; j<= N; ++j){
            scanf("%lf %lf %lf", &score1, &score2, &score3);
            vec.push_back(std::make_pair(j, score1 * 0.35 + score2 * 0.45 + score3 * 0.2));
        }
        std::sort(vec.begin(), vec.end(), cmp);
        for(int j=0; j<vec.size(); ++j){
            if(vec[j].first == K){
                std::cout << "#" << i << " " << score[(j)*10/N] << std::endl;
                break;
            }
        }
        vec.clear();
    }
    
}