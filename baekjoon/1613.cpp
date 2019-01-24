#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 401
int n, k, s;
std::vector<std::vector<int> > prev_vec;
bool check_visit[MAX] = {false, };

int BFS(int first, int second){
    memset(check_visit, false, MAX);
    std::queue<int> myqueue;
    myqueue.push(first);
    check_visit[first] = true;
    while(!myqueue.empty()){
        int cur = myqueue.front();
        myqueue.pop();
        for(int i=0; i<prev_vec[cur].size(); ++i){
            int next = prev_vec[cur][i];
            if(next == second)
                return -1;
            if(!check_visit[next]){
                check_visit[next] = true;
                myqueue.push(next);
            }
        }
    }
    memset(check_visit, false, MAX);
    myqueue.push(second);
    check_visit[second] = true;
    while(!myqueue.empty()){
        int cur = myqueue.front();
        myqueue.pop();
        for(int i=0; i<prev_vec[cur].size(); ++i){
            int next = prev_vec[cur][i];
            if(next == first)
                return 1;
            if(!check_visit[next]){
                check_visit[next] = true;
                myqueue.push(next);
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d %d", &n, &k);
    int prev, later;
    prev_vec = std::vector<std::vector<int> >(n+1);

    for(int i=0; i<k; ++i){
        scanf("%d %d", &prev, &later);
        prev_vec[prev].push_back(later);
    }
    scanf("%d", &s);
    int first, second;
    for(int i=0; i<s; ++i){
        scanf("%d %d", &first, &second);
        printf("%d\n", BFS(first, second));
    }
    return 0;
}