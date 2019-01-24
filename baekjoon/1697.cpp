#include <iostream>
#include <queue>
#include <algorithm>

int finder, hider;
int BFS();

int main(){
    scanf("%d %d", &finder, &hider);
    printf("%d\n", BFS());
}

int BFS(){
    int count = 0;
    bool check_visit[100001] = {false, } ;
    std::queue<int> myqueue;
    myqueue.push(finder);
    check_visit[finder] = true;
    while(!myqueue.empty()){
        int q_size = myqueue.size();
        for(int i=0; i<q_size; ++i){
            int current_finder = myqueue.front();
            myqueue.pop();
            if(current_finder == hider)
                return count;
            if(current_finder > 0 && check_visit[current_finder-1] == false){
                myqueue.push(current_finder-1);
                check_visit[current_finder-1] = true;
            }
            if(current_finder < 100000 && check_visit[current_finder+1] == false){
                myqueue.push(current_finder+1);
                check_visit[current_finder+1] = true;
            }
            if(current_finder*2 < 100001 && check_visit[current_finder*2] == false){
                myqueue.push(current_finder*2);
                check_visit[current_finder*2] = true;
            }
        }
        count++;
    }
}