#include <iostream>
#define MAX 101

int size;
int path_map[MAX][MAX] = {0, };
bool check_visit[MAX] = {false, };
void DFS(int vertex);

int main(){
    scanf("%d", &size);
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            scanf("%d", &path_map[i][j]);
        }
    }
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            check_visit[j] = false;
        }
        DFS(i);
        for(int k=0; k<size; ++k){
            if(check_visit[k] == true)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void DFS(int vertex){
    for(int i=0; i<size; ++i){
        if(path_map[vertex][i] == 1 && check_visit[i] == false){
            check_visit[i] = true;
            DFS(i);
        }
    }
}