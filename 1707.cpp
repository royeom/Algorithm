#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int node_count, edge_count;

bool BFS(int (*adj_matrix)[1001]);

int main(){
    int num_test_case;
    scanf("%d", &num_test_case);
    for(int i=0; i<num_test_case; ++i){
        int adj_matrix[1001][1001] = {0, };
        scanf("%d %d", &node_count, &edge_count);
        for(int k=0; k < edge_count; ++k){
            int edge_start, edge_end;
            scanf("%d %d", &edge_start, &edge_end);
            adj_matrix[edge_start][edge_end] = 1;
            adj_matrix[edge_end][edge_start] = 1;
        }
        if(BFS(adj_matrix))
            printf("YES\n");
        else
            printf("NO\n");
    }
}

bool BFS(int (*adj_matrix)[1001]){
    int color_check[1001]= {0, }; // '0' : 방문 X, '1' : 빨간색,  '2' : 파란색
    std::queue<int> myqueue;
    myqueue.push(1);
    int flag = 1;
    int previous_flag=0;
    color_check[1] = flag;

    while(!myqueue.empty()){
        int current_node = myqueue.front();
        myqueue.pop();

        if(flag == 1){
            flag = 2;
            previous_flag = 1;
        } 
        else if(flag == 2){
            flag = 1;
            previous_flag = 2;
        }

        for(int i=1; i <= node_count; ++i){
            if(adj_matrix[current_node][i] == 1){
                if(color_check[i] == 0){
                    myqueue.push(i);
                    color_check[i] = flag;
                }else if(color_check[i] == previous_flag){
                    return false;
                }
            }
        }
    }
    return true;
}