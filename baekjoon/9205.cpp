#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 102

std::vector<int> graph[MAX];
bool check_visit[MAX];
int N;

void Go(int num){
    check_visit[num] = true;
    for(int i=0; i<graph[num].size(); ++i){
        int next = graph[num][i];
        if(!check_visit[next])
            Go(next);
    }
}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        for(int i=0; i<MAX; ++i){
            graph[i].clear();
        }
        memset(check_visit, false, sizeof(check_visit));
        scanf("%d", &N);
        std::vector<std::pair<int, int> > beer;
        for(int i=0; i<N+2; ++i){
            int x, y;
            scanf("%d %d", &x, &y);
            beer.push_back(std::make_pair(x,y));
        }
        for(int i=0; i<N+2; ++i){
            for(int j=i+1; j<N+2; ++j){
                if(std::abs(beer[i].first-beer[j].first)+std::abs(beer[i].second-beer[j].second) <= 1000){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        Go(0);
        if(check_visit[N+1])
            printf("happy\n");
        else
            printf("sad\n");
    }
}