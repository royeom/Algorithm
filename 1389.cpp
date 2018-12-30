#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#define MAX 101

int N, M;
int relation_map[MAX][MAX] = {0, };
int bacon_num[MAX] = {0, };

void BFS();

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i){
        int A, B;
        scanf("%d %d", &A, &B);
        relation_map[A][B] = relation_map[B][A] = 1;
    }
    BFS();
}

void BFS(){
    bool check_visit[MAX][MAX] = {false, };
    std::queue<int> myqueue;
    int minVal = INT_MAX;
    int answer = 0;

    for(int i=1; i<=N; ++i){
        myqueue.push(i);
        check_visit[i][i] = true;
        int temp = 0;
        while(!myqueue.empty()){
            int current_node = myqueue.front();
            myqueue.pop();
            for(int j=1; j<=N; ++j){
                if(relation_map[current_node][j] == 1 && !check_visit[i][j]){
                    myqueue.push(j);
                    relation_map[i][j] = relation_map[i][current_node] + relation_map[current_node][j];
                    check_visit[i][j] = true;
                    temp += relation_map[i][j];
                }
            }
        }
        if(temp < minVal){
            minVal = temp;
            answer = i;
        }
    }
    printf("%d\n", answer);
}