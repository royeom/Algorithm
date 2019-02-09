#include <iostream>
#include <vector>
#define MAX 1001
struct Cats{
    int x, y;
    int number;
};
std::vector<Cats> cat;
std::vector<std::pair<int, int> > eats; // x좌표, 고양이 몇 마리
int N, M;
int minOfMax;

int HowManyCats(){
    // 초기화
    for(int i=0; i<M; ++i){
        eats[i].second = 0;
    }
    // 각 배식구에 몇 마리의 고양이가 오는지 찾는 과정
    for(int i=0; i<N; ++i){
        std::pair<int ,int> temp = std::make_pair(0, 987654321);
        for(int j=0; j<M; ++j){

            if(eats[j].first == -987654321)
                continue;

            int distance = (cat[i].x - eats[j].first)*(cat[i].x - eats[j].first) + cat[i].y * cat[i].y;
            if(distance == temp.second){
                if(eats[j].first < temp.first){
                    temp.first = j;
                    temp.second = distance;
                }
            }                
            else if(distance < temp.second){
                temp.first = j;
                temp.second = distance;
            }
        }
        eats[temp.first].second += cat[i].number;        
    }
    // for(int i=0; i<M; ++i){
    //     printf("In %d : %d \n", eats[i].first, eats[i].second);
    // }

    int max = eats[0].second;
    for(int i=0; i<M; ++i){
        if(eats[i].second > max){
            max = eats[i].second;
        }
    }
    // printf("Size %d : %d\n", size, max);
    return max;
}

void DFS(int count){
    if(count == M)
        return;
    int current_max = HowManyCats();
    if(minOfMax > current_max){
        minOfMax = current_max;
    }
    for(int i=0; i<M; ++i){
        int temp = eats[i].first;
        eats[i].first = -987654321;
        DFS(count+1);
        eats[i].first = temp;
    }
}

// void DFS(int count){
//     // int size = eats.size();
//     if(count == M-1)
//         return;

//     std::pair<int, int> current_max = HowManyCats();
//     if(minOfMax > current_max.second){
//         minOfMax = current_max.second;
//     }
//     eats[current_max.first].second = -1;
//     DFS(count+1);
// }

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        scanf("%d %d", &N, &M);
        cat.resize(N);
        eats.resize(M);
        minOfMax = 987654321;
        for(int i=0; i<N; ++i){
            scanf("%d %d %d", &cat[i].x, &cat[i].y, &cat[i].number);
        }
        for(int i=0; i<M; ++i){
            scanf("%d", &eats[i].first);
            eats[i].second = 0;
        }
        DFS(0);
        printf("#%d %d\n", tcn, minOfMax);
        cat.clear();
        eats.clear();
    }
    return 0;
}