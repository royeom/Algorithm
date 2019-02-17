#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
int N, M;
int map[MAX][MAX]= {0, };
struct Camera{
    int num;
    int direction;
    int y, x;
    Camera() {}
    Camera(int _num, int _direction, int _y, int _x){
        num = _num; 
        direction = _direction; 
        y = _y; 
        x = _x;
    }
    
};
std::vector<Camera> vec;
int answer = 87654321;

void PrintMap(){
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}
bool isPossibleArea(int next_y, int next_x){
    if(next_y >= N || next_y < 0 || next_x >= M || next_x < 0 || map[next_y][next_x] == 6) 
        return false;
    else
        return true;
}

void Camera1(Camera camera){
    int y = camera.y;
    int x = camera.x;
    while(isPossibleArea(y, x)){
        if(map[y][x] == 0)
            map[y][x] = 7;

        if(camera.direction == 0) y--;
        else if(camera.direction == 1) x++;
        else if(camera.direction == 2) y++;
        else if(camera.direction == 3) x--;
    }
}

void Camera2(Camera camera){
    int y = camera.y;
    int x = camera.x;
    int temp_y = y;
    int temp_x = x;
    if(camera.direction == 0){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y++;
        }
        y = temp_y;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y--;
        }
    }
    else if(camera.direction == 1){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x++;
        }
        x = temp_x;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x--;
        }
    }
}

void Camera3(Camera camera){
    int y = camera.y;
    int x = camera.x;
    int temp_y = y;
    int temp_x = x;
    if(camera.direction == 0){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y--;
        }
        y = temp_y;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x++;
        }
    }
    else if(camera.direction == 1){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x++;
        }
        x = temp_x;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y++;
        }
    }
    else if(camera.direction == 2){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y++;
        }
        y = temp_y;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x--;
        }
    }
    else if(camera.direction == 3){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x--;
        }
        x = temp_x;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y--;
        }
    }
}

void Camera4(Camera camera){
    int y = camera.y;
    int x = camera.x;
    int temp_y = y;
    int temp_x = x;
    if(camera.direction == 0){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y--;
        }
        y = temp_y;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x++;
        }
        x = temp_x;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x--;
        }
    }
    else if(camera.direction == 1){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x++;
        }
        x = temp_x;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y++;
        }
        y = temp_y;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y--;
        }
    }
    else if(camera.direction == 2){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y++;
        }
        y = temp_y;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x--;
        }
        x = temp_x;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x++;
        }
    }
    else if(camera.direction == 3){
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            x--;
        }
        x = temp_x;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y--;
        }
        y = temp_y;
        while(isPossibleArea(y, x)){
            if(map[y][x] == 0)
                map[y][x] = 7;
            y++;
        }
    }
}

void Camera5(Camera camera){
    int y = camera.y;
    int x = camera.x;
    int temp_y = y;
    int temp_x = x;
    while(isPossibleArea(y,x)){
        if(map[y][x] == 0)
            map[y][x] = 7;
        y++;
    }
    y = temp_y;
    while(isPossibleArea(y,x)){
        if(map[y][x] == 0)
            map[y][x] = 7;
        y--;
    }
    y = temp_y;
    while(isPossibleArea(y,x)){
        if(map[y][x] == 0)
            map[y][x] = 7;
        x++;
    }
    x = temp_x;
    while(isPossibleArea(y,x)){
        if(map[y][x] == 0)
            map[y][x] = 7;
        x--;
    }
}

void FindBlindArea(){
    int count = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(map[i][j] == 0)
                count++;
        }
    }
    answer = std::min(answer, count);
}

void DFS(int count){
    if(count == vec.size()){
        for(int i=0; i<vec.size(); ++i){
            if(vec[i].num == 1) Camera1(vec[i]);
            else if(vec[i].num == 2) Camera2(vec[i]);
            else if(vec[i].num == 3) Camera3(vec[i]);
            else if(vec[i].num == 4) Camera4(vec[i]);
            else if(vec[i].num == 5) Camera5(vec[i]);
        }
        FindBlindArea();
        PrintMap();
        return;
    }
    for(int i=count; i<vec.size(); ++i){
        if(vec[i].num != 5){
            for(int j=0; j<4; ++j){
                if(vec[i].direction == 3){
                    vec[i].direction = 0;
                }else{
                    vec[i].direction++;
                }
                DFS(count++);
                if(vec[i].direction == 0){
                    vec[i].direction = 3;
                }else{
                    vec[i].direction--;
                }
            }
        }
        else{ // 5인 경우는 모든 방향을 다 보기 때문에 바꿀 필요가 없음.
            DFS(count+1);
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf("%d", &map[i][j]);
            if(map[i][j] >= 1 && map[i][j] <= 5)
                vec.push_back(Camera(map[i][j], 0, i, j));
        }
    }
    DFS(0);
    printf("%d\n", answer);
}