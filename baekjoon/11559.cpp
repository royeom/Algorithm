#include <iostream>
#include <vector>
#include <cstring>
int map[12][6] = {0, }; // R=1 G=2 B=3 P=4 Y=5
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool check_visit[12][6] = {false, };
int puyo_count = 0;
int chain = 0;
std::vector<std::pair<int, int> > vec;

void Move_Down(){
    for(int j=0; j<6; ++j){
        for(int i=11; i>=0; --i){
            if(map[i][j] != 0){
                for(int k= 11; k>i; --k){
                    if(map[k][j]  == 0){
                        map[k][j] = map[i][j];
                        map[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void PuyoPuyo(int cur_y, int cur_x, int color){
    vec.push_back(std::make_pair(cur_y, cur_x));
    for(int i=0; i<4; ++i){
        int next_y = cur_y + direction[i][0];
        int next_x = cur_x + direction[i][1];
        if(next_y < 0 || next_y >= 12 || next_x < 0 || next_x >= 6)
            continue;
        if(!check_visit[next_y][next_x] && map[next_y][next_x] == color){
            check_visit[next_y][next_x] = true;
            puyo_count++;
            PuyoPuyo(next_y, next_x, color); 
        }
    }
}

int main(){
    char temp;
    for(int i=0; i<12; ++i){
        for(int j=0; j<6; ++j){
            std::cin >> temp;
            if(temp == 'R') map[i][j] = 1;
            if(temp == 'G') map[i][j] = 2;
            if(temp == 'B') map[i][j] = 3;
            if(temp == 'P') map[i][j] = 4;
            if(temp == 'Y') map[i][j] = 5;
         }
    }
    while(1){
        bool isFinishedFlag = true;
        bool chainFlag = false;
        for(int i=0; i<12; ++i){
            for(int j=0; j<6; ++j){
                if(map[i][j] != 0){
                    PuyoPuyo(i, j, map[i][j]);
                    if(puyo_count >= 4){
                        for(int k=0; k<vec.size(); ++k){
                            map[vec[k].first][vec[k].second] = 0;
                        }
                        isFinishedFlag = false;
                        if(!chainFlag){
                            chain++;
                            chainFlag = true;
                        }
                    }
                    puyo_count = 0;
                    vec.clear();
                }
            }
        }
        if(!isFinishedFlag){
            Move_Down();
            memset(check_visit, false, sizeof(check_visit));
        }
        else
            break;
    }
    printf("%d\n", chain);
}