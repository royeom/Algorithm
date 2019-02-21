#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 105
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int map[MAX][MAX] = {0, };
char temp[MAX][MAX];
int N, M;
bool check_visit[MAX][MAX] = {false, };

struct Node{
    int y, x, weight;
    Node(int _y, int _x, int _weight) : y(_y), x(_x), weight(_weight) {}
    bool operator < (Node node) const {
        return weight > node.weight;
    }
};

void BFS(){
    std::priority_queue<Node> pq;
    pq.push(Node(1, 1, 0));
    while(!pq.empty()){
        Node temp = pq.top();
        pq.pop();
        if(temp.y == N && temp.x == M){
            printf("%d\n", temp.weight);
            return;
        }
        check_visit[temp.y][temp.x] = true;
        for(int i=0; i<4; ++i){
            int next_y = temp.y + direction[i][0];
            int next_x = temp.x + direction[i][1];
            int next_weight = temp.weight + map[next_y][next_x];
            if(next_y <= 0 || next_y > N || next_x <= 0 || next_x > M ||check_visit[next_y][next_x])
                continue;
            pq.push(Node(next_y, next_x, next_weight));
        }
    }
}

int main(){
    scanf("%d %d", &M, &N);
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            std::cin >> temp[i][j];
            map[i][j] = temp[i][j] - '0';
        }
    }
    BFS();
    return 0;
}