#include <iostream>
#include <cstring>
int map[5][5] = {0, };
int direction[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int answer = 0;
bool check_visit[10000000] = {false, };

void MAKE_NUMBER(int cur_y, int cur_x, int num, int count){
    if(count == 7){
        check_visit[num] = true;
        return;
    }

    num *= 10;
    num += map[cur_y][cur_x];

    for(int i=0; i<4; ++i){
        int next_y = cur_y + direction[i][0];
        int next_x = cur_x + direction[i][1];
        if(next_y == 5 || next_y == 0 || next_x == 5 || next_x == 0)
            continue;
        MAKE_NUMBER(next_y, next_x, num, count+1);
    }
}

int main(){
    // std::string str = "00123450";
    // int str1 = std::stoi(str);
    // printf("%d\n", str1);
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=1; i <= test_case_num; ++i){
        for(int j=1; j<=4; ++j){
            for(int k=1; k<=4; ++k){
                scanf("%d", &map[j][k]);
            }
        }
        for(int j=1; j<=4; ++j){
            for(int k=1; k<=4; ++k){
                MAKE_NUMBER(j, k, 0, 0);
            }
        }
        for(int x=0; x<10000000; ++x){
            if(check_visit[x] != 0)
                answer++;
        }
        printf("#%d %d\n", i, answer);
        answer = 0;
        std::memset(check_visit, false, sizeof(check_visit));
    }
}