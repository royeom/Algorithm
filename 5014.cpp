#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1000001
int height, location, goal, up, down;
bool check_visit[MAX] = {false, };

int BFS(){
    int visit_count[MAX] = {0, };
    std::queue<int> myqueue;
    myqueue.push(location);
    check_visit[location] = true;

    while(!myqueue.empty()){
        int cur_stair = myqueue.front();
        myqueue.pop();

        if(cur_stair == goal){
            return visit_count[cur_stair];
        }

        if(check_visit[cur_stair + up] == false && cur_stair + up <= height){
            myqueue.push(cur_stair + up);
            check_visit[cur_stair + up] = true;
            visit_count[cur_stair + up] = visit_count[cur_stair] + 1;
        }
        if(check_visit[cur_stair - down] == false && cur_stair - down > 0){
            myqueue.push(cur_stair - down);
            check_visit[cur_stair - down] = true;
            visit_count[cur_stair - down] = visit_count[cur_stair] + 1;
        }
    }
}

int main(){
    scanf("%d %d %d %d %d", &height, &location, &goal, &up, &down);
    int temp = BFS();
    if(!check_visit[goal])
        printf("use the stairs\n");
    else   
        printf("%d\n", temp);

    return 0;
}