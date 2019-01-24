#include <iostream>
#define MAX 21
int N, M;
int map[MAX][MAX];
int cur_y, cur_x;
int direction[5][2] = {{0,0}, {0,1}, {0,-1}, {-1,0}, {1,0}}; // 가운데 동 서 북 남

class dice{
public:
    int top = 0;
    int bottom = 0;
    int east = 0;
    int west = 0;
    int south = 0;
    int north = 0;
};
dice myDice;

bool isInArea(int y, int x){
    return y >=0 && y<N && x>=0 && x<M;
}
void copy(int y, int x){
    if(map[y][x] == 0){
        map[y][x] = myDice.bottom;
    }else{
        myDice.bottom = map[y][x];
        map[y][x] = 0;
    }
    printf("%d\n", myDice.top);
}
void MOVE(int command){

    int next_y = cur_y + direction[command][0];
    int next_x = cur_x + direction[command][1];
    if(!isInArea(next_y, next_x))
        return;
    cur_y = next_y; cur_x = next_x;
    int temp = myDice.top;
    switch(command){
        case 1: // 동
            myDice.top = myDice.west;
            myDice.west = myDice.bottom;
            myDice.bottom = myDice.east;
            myDice.east = temp;
            copy(next_y, next_x);
            break;
        case 2: // 서
            myDice.top = myDice.east;
            myDice.east = myDice.bottom;
            myDice.bottom = myDice.west;
            myDice.west = temp;
            copy(next_y, next_x);
            break;
        case 3: // 북
            myDice.top = myDice.south;
            myDice.south = myDice.bottom;
            myDice.bottom = myDice.north;
            myDice.north = temp;
            copy(next_y, next_x);
            break;
        case 4: // 남 
            myDice.top = myDice.north;
            myDice.north = myDice.bottom;
            myDice.bottom = myDice.south;
            myDice.south = temp;
            copy(next_y, next_x);
            break;
    }
}

int main(){
    int command_num;

    scanf("%d %d %d %d %d", &N, &M, &cur_y, &cur_x, &command_num);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0; i<command_num; ++i){
        int command;
        scanf("%d", &command);
        MOVE(command);
    }
}
