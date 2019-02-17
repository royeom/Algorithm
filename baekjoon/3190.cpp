#include <iostream>
#include <vector>
#define MAX 101
int map[MAX][MAX] = {0, };
int N;
int timer = 0;
int direction[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
std::vector<std::pair<int, int> > snake; // [0]은 항상 Head.
int cur_dir = 0;
bool isFinished = false;

void Move(){
    timer++;
    int snake_size = snake.size();
    int next_y = snake[snake_size-1].first + direction[cur_dir][0];
    int next_x = snake[snake_size-1].second + direction[cur_dir][1];
    if(next_y <= 0 || next_y > N || next_x <= 0 || next_x > N){
        isFinished = true;
        return;
    }
    for(int i=0; i<snake_size-1; ++i){
        if(snake[i].first == next_y && snake[i].second == next_x){
            isFinished = true;
            return;
        }
    }
    snake.push_back(std::make_pair(next_y, next_x));
    // printf("y: %d, x: %d, size: %d, cur_dir: %d\n", next_y, next_x, snake_size, cur_dir);
    // std::pair<int, int> temp = std::make_pair(snake[snake_size-1].first, snake[snake_size-1].second);
    if(map[next_y][next_x] != 1){
        // printf("tail : %d %d\n", snake.begin()->first, snake.begin()->second);
        snake.erase(snake.begin());
    }else{
        map[next_y][next_x] = 0;
    }
}

void Change(int sec, char dir){
    for(int i=timer; i<sec; ++i){
        if(isFinished)
            return;
        else{
            Move();
        }
    }
    if(dir == 'D'){
        if(cur_dir == 3)
            cur_dir = 0;
        else
            cur_dir++;
    }
    else if(dir == 'L'){
        if(cur_dir == 0)
            cur_dir = 3;
        else
            cur_dir--;
    }
}

int main(){
    scanf("%d", &N);
    int apple_num, y, x, change_num;
    scanf("%d", &apple_num);
    for(int i=0; i<apple_num; ++i){
        scanf("%d %d", &y, &x);
        map[y][x] = 1;
    }
    scanf("%d", &change_num);
    int second;
    char direction;

    snake.push_back(std::make_pair(1,1));
    for(int i=0; i<change_num; ++i){
        scanf("%d %c", &second, &direction);
        if(!isFinished)
            Change(second, direction);
        else{
            break;
        }
    }
    while(!isFinished){
        Move();
    }
    printf("%d\n", timer);
}