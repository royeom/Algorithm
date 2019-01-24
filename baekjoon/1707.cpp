#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define VERTEX_MAX 20001
#define EDGE_MAX 200001

std::vector<std::vector<int> > vec;
std::vector<int> check_visit;
int V, E;

void BFS(){
    std::queue<int> myqueue;
    for(int i=1; i<=V; ++i){
        if(check_visit[i] == 0){
            myqueue.push(i);
            check_visit[i] = 1;
            while(!myqueue.empty()){
                int cur = myqueue.front();
                myqueue.pop();
                for(int j=0; j<vec[cur].size(); ++j){
                    if(check_visit[vec[cur][j]] == 0){
                        myqueue.push(vec[cur][j]);
                        check_visit[vec[cur][j]] = ~check_visit[cur] + 1;
                    }
                    else if(check_visit[cur] + check_visit[vec[cur][j]] != 0){
                        printf("NO\n");
                        return;
                    }
                }
            }
        }
    }
    printf("YES\n");
}

int main(){
    int K;
    scanf("%d", &K);
    for(int i=0; i<K; ++i){
        scanf("%d %d", &V, &E);
        vec = std::vector<std::vector<int> >(V + 1);
        check_visit = std::vector<int>(V + 1, 0);
        int ver1, ver2;
        for(int j=0; j<E; ++j){
            scanf("%d %d", &ver1, &ver2);
            vec[ver1].push_back(ver2);
            vec[ver2].push_back(ver1);
        }
        BFS();
    }
}
