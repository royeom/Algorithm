#include <iostream>
#include <cstring>
#include <vector>
#define MAX 6001
#define INF 987654321
int D[MAX] = {0, };
int N, M;
struct Edge{
    int from, to, weight;
    Edge(int _from, int _to, int _weight) : from(_from), to(_to), weight(_weight) {}
};

std::vector<Edge> vec;



int main(){
    for(int i=2; i<MAX; ++i){
        D[i] = INF;
    }

    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i){
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        vec.push_back(Edge(from, to, weight));
    }

    for(int j=0; j<=N; ++j){
        for(int i=0; i<M; ++i){
            if(D[vec[i].from] == INF)
                continue;
            if(D[vec[i].to] > D[vec[i].from] + vec[i].weight){
                if(j==N){
                    printf("-1\n");
                    return 0;
                }
                D[vec[i].to] = D[vec[i].from] + vec[i].weight;
            }
        }
    }

    for(int i=2; i<=N; ++i){
        if(D[i] == INF){
            printf("-1\n");
        }else{
            printf("%d\n", D[i]);
        }
    }
}