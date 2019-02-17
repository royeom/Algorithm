#include <iostream>
#include <vector>
#include <algorithm>
int map[11][11];
int A[11][11];
int N, M, K;
int direction[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
std::vector<int> vec[11][11];

void SpringAndSummer(int y, int x){
    int size = vec[y][x].size();
    std::vector<int> temp;
    
    int dead_trees = 0;
    for(int i=0; i<size; ++i){
        if(vec[y][x][i] <= map[y][x]){
            map[y][x] -= vec[y][x][i];
            temp.push_back(vec[y][x][i] + 1);
        }else{
            dead_trees += vec[y][x][i]/2;
        }
    }
    vec[y][x].clear();
    map[y][x] += dead_trees;
    for(int i=0; i<temp.size(); ++i){
        vec[y][x].push_back(temp[i]);
    }
    
}

void Fall(int y, int x){
    for(int i=0; i<vec[y][x].size(); ++i){
        if(vec[y][x][i] % 5 == 0){
            for(int j=0; j<8; ++j){
                int next_y = y + direction[j][0];
                int next_x = x + direction[j][1];
                if(next_y <= 0 || next_x <= 0 || next_y > N || next_x > N)
                    continue;
                vec[next_y][next_x].push_back(1);
            }
        }
    }
}

void Winter(){
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            map[i][j] += A[i][j];
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            scanf("%d", &A[i][j]);
            map[i][j] = 5;
        }
    }
    int tree_y, tree_x, tree_age;
    for(int i=0; i<M; ++i){
        scanf("%d %d %d", &tree_y, &tree_x, &tree_age);
        vec[tree_y][tree_x].push_back(tree_age);
    }

    for(int year=0; year<K; ++year){
        for(int i=1; i<=N; ++i)
            for(int j=1; j<=N; ++j)
                std::sort(vec[i][j].begin(), vec[i][j].end());

        for(int i=1; i<=N; ++i)
            for(int j=1; j<=N; ++j)
                SpringAndSummer(i, j);

        for(int i=1; i<=N; ++i)
            for(int j=1; j<=N; ++j)
                Fall(i, j);
        
        Winter();
    }
    
    int answer = 0;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            answer += vec[i][j].size();

    printf("%d\n", answer);
    return 0;
}