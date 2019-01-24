#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

int adj_matrix[1001][1001] = {0, };
int node_count, edge_count, start;

void DFS();
void BFS();

int main(){
    scanf("%d %d %d", &node_count, &edge_count, &start);
    for(int k=0; k < edge_count; ++k){
        int edge_start, edge_end;
        scanf("%d %d", &edge_start, &edge_end);
        adj_matrix[edge_start][edge_end] = 1;
        adj_matrix[edge_end][edge_start] = 1;
    }
    DFS();
    BFS();
}

void DFS(){
    bool check_visit[1001]= {false, };
    std::stack<int> mystack;
    mystack.push(start);
    check_visit[start] = true;
    printf("%d ", start);

    while(!mystack.empty()){
        int current_node = mystack.top();
        mystack.pop();
        for(int i=1; i < node_count+1; ++i){
            if(check_visit[i] == false && adj_matrix[current_node][i] == 1){
                printf("%d ", i);
                mystack.push(current_node);
                mystack.push(i);
                check_visit[i] = true;
                break;
            }
        }
    }
    printf("\n");
}

void BFS(){
    bool check_visit[1001]= {false, };
    std::queue<int> myqueue;
    myqueue.push(start);
    check_visit[start] = true;
    while(!myqueue.empty()){
        int current_node = myqueue.front();
        printf("%d ", current_node);
        myqueue.pop();
        for(int i=0; i < node_count+1; ++i){
            if(check_visit[i] == false && adj_matrix[current_node][i] == 1){
                myqueue.push(i);
                check_visit[i] = true;
            }
        }
    }
    printf("\n");
}