#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001
int island_num;
double E;
long long island[MAX][MAX];
long long parents[MAX];

long long find(long long first){
    if(parents[first] == first)
        return first;
    else    
        return parents[first] = find(parents[first]);
}   

bool Union(long long first, long long second){
    long long parent_first = find(first);
    long long parent_second = find(second);
    if(parent_first == parent_second)
        return true;
    
    parents[parent_first] = parent_second;
    return false;
}


int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=1; i <= test_case_num; ++i){
        std::priority_queue<std::pair<long long, std::pair<long long, long long> > > pq;
        memset(island, 0, MAX);
        memset(parents, 0, MAX);
        scanf("%d", &island_num);
        std::vector<long long> x, y;
        x.resize(island_num);
        y.resize(island_num);
        for(int j=0; j<island_num; ++j)
            scanf("%lld", &x[j]);
        for(int j=0; j<island_num; ++j)
            scanf("%lld", &y[j]);
        scanf("%lf", &E);

        for(long long j=0; j<island_num; ++j)
            parents[j] = j;
        for(long long j=0; j<island_num; ++j){
            for(long long k=j+1; k<island_num; ++k){
                island[j][k] = (x[k]-x[j])*(x[k]-x[j]) + (y[k]-y[j])*(y[k]-y[j]);
                island[k][j] = island[j][k];
                pq.push(std::make_pair(-island[j][k], std::make_pair(j, k)));
            }
        }
        double size = 0;
        int count = 0;
        while(!pq.empty()){
            if(count == island_num-1)
                break;
            long long dist = -pq.top().first;
            long long first = pq.top().second.first;
            long long second = pq.top().second.second;
            pq.pop();
            bool isUnion = Union(first, second);

            if(isUnion)
                continue;

            size += dist;
            count++;
        }
        size = size * E;

        printf("#%d %.0f\n", i, size);
    }
}