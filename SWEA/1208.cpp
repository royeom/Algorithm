#include <iostream>
#include <vector>
#define MAX 101

std::vector<int> vec;
int dump;
int max = 0;
int min = 500;
int count = 1;

std::pair<int, int> FindMaxAndMin(){
    int max_idx, min_idx;
    int min_val = 101;
    int max_val = 0;
    for(int i = 1 ; i <= 100; ++i){
        if(vec[i] > max_val){
            max_val = vec[i];
            max_idx = i;
        }
        if(vec[i] < min_val){
            min_val = vec[i];
            min_idx = i;
        }
    }
    max = max_val;
    min = min_val;
    std::pair<int, int> val = std::make_pair(max_idx, min_idx);
    // printf("count %d : MAX : %d(%d), MIN: %d(%d) \n", count, max, max_idx, min, min_idx);
    // count++;
    return val;
}

void Flatten(){
    for(int k = 0; k < dump+1; ++k){
        std::pair<int, int> val = FindMaxAndMin();
        if(max - min == 0 || max - min == 1){
            return;
        }
        else{
            vec[val.first] -= 1;
            vec[val.second] += 1;
        }
    }
}

int main (){
    for(int test_num = 1; test_num <= 10; ++test_num){
        vec = std::vector<int>(MAX);
        scanf("%d", &dump);
        for (int i = 1; i <= 100; ++i)
            scanf("%d", &vec[i]);

        Flatten();

        printf("#%d %d\n", test_num, max-min);
        max = 0;
        min = 500;
        vec.clear();
    }
}