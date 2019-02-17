#include <iostream>
#include <vector>
#define MAX 101
std::vector<int> vec;
int map[MAX][MAX] = {0, };
int y, x, dir, num;

int direction[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=0; i<test_case_num; ++i){
        scanf("%d %d %d %d", &x, &y, &dir, &num);
        vec.push_back(dir);
        while(num--){
            for(int j=vec.size()-1; j>=0; --j){
                if(vec[j] == 3)
                    vec.push_back(0);
                else
                    vec.push_back(vec[j]+1);
            }
        }

        map[y][x] = 1;
        for(int j=0; j<vec.size(); ++j){
            y += direction[vec[j]][0];
            x += direction[vec[j]][1];
            map[y][x] = 1;
        }
        vec.clear();
    }
    int count = 0;
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++j){
            if(map[i][j] == 1 && map[i+1][j] == 1 && map[i][j+1] == 1 && map[i+1][j+1] == 1){
                count++;
            }
        }
    }
    printf("%d\n", count);
}