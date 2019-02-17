#include <iostream>
#include <vector>
int N, M;
std::vector<int> vec;

void DFS(){
    if(vec.size() == M){
        for(int i=0; i<vec.size(); ++i){
            printf("%d ", vec[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=N; ++i){
        vec.push_back(i);
        DFS();
        vec.pop_back();
    }

}

int main(){
    scanf("%d %d", &N, &M);
    DFS();
}