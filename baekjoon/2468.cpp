#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101

int area[MAX][MAX];
int size;
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int maxVal = 0;

void BFS();

int main(){
    scanf("%d", &size);
    
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            scanf("%d", &area[i][j]);
            if(maxVal < area[i][j])
                maxVal = area[i][j];
        }
    }
    BFS();
}

void BFS(){
    std::queue<std::pair<int, int> > myqueue;
    int max_safe_area = 0;
    for(int k=0; k<=maxVal; ++k){
        int num = 0;
        bool check_visit[MAX][MAX] = {false, };
        for(int i=0; i<size; ++i){
            for(int j=0; j<size; ++j){
                if(area[i][j] >= k && !check_visit[i][j]){
                    myqueue.push(std::pair<int, int>(i, j));
                    check_visit[i][j] = true;
                    while(!myqueue.empty()){
                        int cur_y = myqueue.front().first;
                        int cur_x = myqueue.front().second;
                        myqueue.pop();
                        for(int i=0; i<4; ++i){
                            int next_y = cur_y + direction[i][0];
                            int next_x = cur_x + direction[i][1];        
                            if(((next_y>=0 && next_y<size) && (next_x>=0 && next_x<size)) && area[next_y][next_x] >= k && !check_visit[next_y][next_x]){
                                check_visit[next_y][next_x] = true;
                                myqueue.push(std::pair<int, int>(next_y, next_x));
                            }
                        }
                    }
                    num++;
                }
            }
        }
        if(max_safe_area < num)
            max_safe_area = num;
    }
    printf("%d\n", max_safe_area);
}