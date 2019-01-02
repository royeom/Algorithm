#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 301

int map[MAX][MAX] = {0, };
int direction[8][2] = {{-1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
int size;
int y1, x1, y2, x2;

void BFS(int y, int x){
    bool check_visit[MAX][MAX] = {false, };
    std::queue<std::pair<int, std::pair<int, int> > > myqueue;
    myqueue.push(std::make_pair(0, std::make_pair(y, x)));
    while(!myqueue.empty()){
        int count = myqueue.front().first;
        int cur_y = myqueue.front().second.first;
        int cur_x = myqueue.front().second.second;
        myqueue.pop();

        if(cur_y == y2 && cur_x == x2){
            printf("%d\n", count);
            break;
        }

        for(int i=0; i<8; ++i){
            int next_y = cur_y + direction[i][0];
            int next_x = cur_x + direction[i][1];

            if(next_y < 0 || next_y >= size || next_x < 0 || next_x >= size)
                continue;

            if(check_visit[next_y][next_x])
                continue;

            check_visit[next_y][next_x] = true;
            myqueue.push(std::make_pair(count+1, std::make_pair(next_y, next_x)));
        }
    }
}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=0; i<test_case_num; ++i){
        scanf("%d", &size);
        scanf("%d %d", &y1, &x1);
        scanf("%d %d", &y2, &x2);
        BFS(y1, x1);
    }
    return 0;
}