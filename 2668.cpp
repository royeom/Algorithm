#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX 101
int N;
int graph[MAX] = {0, };
bool check_visit[MAX] = {false, };
std::vector<int> result;

void DFS(int num, int goal){
    if(num == goal){
        for(int i=1; i<=N; ++i){
            if(check_visit[i]){
                result.push_back(i);
                graph[i] = 0;
            }
        }
        return;
    }
    if(check_visit[num] || graph[num] == 0)
        return;
    
    check_visit[num] = true;
    DFS(graph[num], goal);
}

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; ++i){
        scanf("%d", &graph[i]);
    }

    for(int i=1; i<=N; ++i){
        if(graph[i] == 0)
            continue;
        if(graph[i] == i){
            result.push_back(i);
            continue;
        }
        memset(check_visit, false, sizeof(check_visit));
        check_visit[i] = true;
        DFS(graph[i], i);
    }

    sort(result.begin(), result.end());
    printf("%d\n", result.size());
    for(int i=0; i<result.size(); ++i){
        printf("%d\n", result[i]);
    }
}