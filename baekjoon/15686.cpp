#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
int N, M;
int map[MAX][MAX] = {0, };
int chicken_distance = 87654321;
std::vector<std::pair<int, int> > house;
std::vector<std::pair<int, int> > chicken;
bool check_visit[14] = {false, };

void DFS(int num, int count){
    if(num > chicken.size())
        return;
    
    if(count == M){
        int total_dist = 0;
        for(int i=0; i < house.size(); ++i){
            int min_dist = 87654321;
            for(int j=0; j < chicken.size(); ++j){
                if(check_visit[j]){
                    int distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                    min_dist = std::min(distance, min_dist);
                }
            }
            total_dist += min_dist;
        }
        chicken_distance = std::min(total_dist, chicken_distance);
        return;
    }

    check_visit[num] = true;
    DFS(num+1, count+1);
    check_visit[num] = false;
    DFS(num+1, count);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1)
                house.push_back(std::make_pair(i, j));
            else if(map[i][j] == 2)
                chicken.push_back(std::make_pair(i, j));
        }
    }
    DFS(0, 0);

    printf("%d\n", chicken_distance);
}