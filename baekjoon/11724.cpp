#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001

int vertex_num, edge_num;
int matrix[MAX][MAX] = {0, };
bool check_visit[MAX] = {false, };
int BFS();

int main(){
    scanf("%d %d", &vertex_num, &edge_num);
    for(int i=0; i<edge_num; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        matrix[u][v] = matrix[v][u] = 1;
    }

    printf("%d\n", BFS());
}

int BFS(){
    std::queue<int> myqueue;
    int count = 0;
    for(int i=1; i<=vertex_num; ++i){
        if(check_visit[i] == false){
            check_visit[i] = true;
            myqueue.push(i);
            while(!myqueue.empty()){
                int cur_vertex = myqueue.front();
                myqueue.pop();
                for(int j=i; j<=vertex_num; ++j){
                    if(matrix[cur_vertex][j] == 1 && check_visit[j] == false){
                        myqueue.push(j);
                        check_visit[j] = true;
                    }
                }
            }
            count++;
        }
    }
    return count;
}