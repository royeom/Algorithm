#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001

int N;
std::vector<std::vector<std::pair<int ,int> > > tree;
bool check_visit[MAX] = {false, };
int distance[MAX];

int DFS(int node){
    check_visit[node] = true;
    int max = node;
    distance[node] = 0;
    for(int i=0; i<tree[node].size(); ++i){
        int next_node = tree[node][i].first;
        int weight = tree[node][i].second;
        if(check_visit[next_node])
            continue;
        int result_next = DFS(next_node);
        if(distance[node] < distance[next_node] + weight){
            distance[node] = distance[next_node] + weight;
            max = result_next;
        }
    }
    return max;
}

int main(){
    scanf("%d", &N);
    tree = std::vector<std::vector<std::pair<int ,int> > >(N+1);
    int parent, child, weight;
    for(int i=0; i < N-1; ++i){
        scanf("%d %d %d", &parent, &child, &weight);
        tree[parent].push_back(std::make_pair(child, weight));
        tree[child].push_back(std::make_pair(parent, weight));
    }
    int start = DFS(1);
    memset(check_visit, 0, MAX);
    memset(distance, 0, MAX);
    int end = DFS(start);
    printf("%d\n", distance[start]);
}