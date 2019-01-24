#include <iostream>
#define MAX 100001
int graph[MAX] = {0, };
bool check_visit[MAX] = {false, };
bool check_finish[MAX] = {false, };
int count = 0;

void DFS(int cur_v){
    check_visit[cur_v] = true;
    int next_v = graph[cur_v];

    if(!check_visit[next_v]){
        DFS(next_v);
    } 
    else{
        if(!check_finish[next_v]){
            for(int x = next_v; cur_v != x; x = graph[x]){
                count++;
            }
            count++;
        }
    }
    
    check_finish[cur_v] = true;
}

void init(int num){
    for(int i=1; i<=num; ++i){
        graph[i] = 0;
        check_finish[i] = false;
        check_visit[i] = false;
    }
}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    while(test_case_num--){
        int student_num;
        count = 0;

        scanf("%d", &student_num);
        for(int student=1; student <= student_num; ++student){
            scanf("%d", &graph[student]);
        }
        for(int i=1; i<=student_num; ++i){
            if(check_visit[i] == true)
                continue;
            DFS(i);
        }
        printf("%d\n", student_num - count);
        init(student_num);
    }
    
}