#include <iostream>
#include <cstring>
#define MAX 21
char map[MAX][MAX];
int direction[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int N, M;
bool check_visit[MAX][MAX][15][4] = {false, };
bool flag = false;

void Compiler(int y, int x, int dir, int memory, int count){

    if(check_visit[y][x][dir][memory] == true){
        return;
    }
    else
        check_visit[y][x][dir][memory] = true;

    switch(map[y][x]){ // 0:right, 1:down, 2:left, 3:up 
        case '<':
            dir = 2;
            break;
        case '>':
            dir = 0;
            break;
        case '^':
            dir = 3;
            break;
        case 'v':
            dir = 1;
            break;
        case '_':
            if(memory == 0) dir = 0;
            else dir = 2;
            break;
        case '|':
            if(memory == 0) dir = 1;
            else dir = 3;
            break;
        case '?':
            if(x == M-1) Compiler(y, 0, dir, memory, count+1);
            else Compiler(y, x+1, dir, memory, count+1);
            if(y == N-1) Compiler(0, x, dir, memory, count+1);
            else Compiler(y+1, x, dir, memory, count+1);
            if(x == 0) Compiler(y, M-1, dir, memory, count+1);
            else Compiler(y, x-1, dir, memory, count+1);
            if(y == 0) Compiler(N-1, x, dir, memory, count+1);
            else Compiler(y-1, x, dir, memory, count+1);
            break;
        case '.':
            break;
        case '@':
            flag = true;
            return;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            memory = map[y][x] - '0';
            break;
        case '+':
            if(memory == 15) memory = 0;
            else memory++;
            break;
        case '-':
            if(memory == 0) memory = 15;
            else memory--;
            break;
    }

    switch(dir){
        case 0:
            if(x == M-1) Compiler(y, 0, dir, memory, count+1);
            else Compiler(y, x+1, dir, memory, count+1);
            break;
        case 1:
            if(y == N-1) Compiler(0, x, dir, memory, count+1);
            else Compiler(y+1, x, dir, memory, count+1);
            break;
        case 2:
            if(x == 0) Compiler(y, M-1, dir, memory, count+1);
            else Compiler(y, x-1, dir, memory, count+1);
            break;
        case 3:
            if(y == 0) Compiler(N-1, x, dir, memory, count+1);
            else Compiler(y-1, x, dir, memory, count+1);
            break;
    }

}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=1; i<=test_case_num; ++i){
        scanf("%d %d", &N, &M);
        for(int j=0; j<N; ++j){
            for(int k=0; k<M; ++k){
                std::cin >> map[j][k];
            }
        }
        Compiler(0,0,0,0,0);
        printf("#%d ", i);
        if(flag == true){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        std::memset(check_visit, false, sizeof(check_visit));
        flag = false;
    }
}