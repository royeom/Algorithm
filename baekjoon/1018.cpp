#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 51
char map[MAX][MAX];
int N, M;
int minCount = 100000;
std::string chess[2][8] ={
    {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	},
	{
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	}
};

void matching(int y, int x){
    char copy[8][8];
    for(int c=0; c<2; ++c){
        int count = 0;
        for(int i=0; i<8; ++i){
            for(int j=0; j<8; ++j){
                if(map[y+i][x+j] != chess[c][i][j])
                    count++;
            }   
        }
        minCount = std::min(minCount, count);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            std::cin >> map[i][j];
       }
    }
    for(int i=0;  i <= N-8; ++i){
        for(int j=0; j <= M-8; ++j){
            matching(i, j);
        }
    }
    printf("%d\n", minCount);
}