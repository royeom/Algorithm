#include <iostream>
#include <queue>
#define MAX 101
int total_num;
int person1, person2;
int answer = 0;
int map[MAX][MAX] = {0, };

void DFS(int now, int before, int count){
    if(now == person2){
        answer = count;
        return;
    }
    for(int i=1; i<=total_num; ++i){
        if(map[now][i] == 1 && i != before){
            DFS(i, now, count+1);
        }
    }
}

int main(){    
    scanf("%d", &total_num);
    scanf("%d %d", &person1, &person2);
    int relation_num;
    scanf("%d", &relation_num);
    for(int i=0; i<relation_num; ++i){
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        map[temp1][temp2] = map[temp2][temp1] = 1;
    }
    DFS(person1, 0, 0);

    if(answer == 0)
        printf("0\n");
    else
        printf("%d\n", answer);
}