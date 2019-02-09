#include <iostream>
#define MAX 14
int candidate[MAX];
int K;
int temp[MAX];

void DFS(int start, int count){
    if(count == 6){
        for(int i=0; i<6; ++i){
            printf("%d ", temp[i]);
        }
        printf("\n");
        return;
    }
    for(int i = start; i<K; ++i){
        temp[count] = candidate[i];
        DFS(i+1, count+1);
    }
}

int main(){
    while(1){
        scanf("%d", &K);
        if(K == 0)
            break;
        for(int i=0; i<K; ++i){
            scanf("%d", &candidate[i]);
        }
        DFS(0, 0);
        printf("\n");
    }
}