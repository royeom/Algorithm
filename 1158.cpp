#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::queue<int> myqueue;
    for(int i=0; i<N; ++i)
        myqueue.push(i+1);
    printf("<");
    while(!myqueue.empty()){
        if(myqueue.size() == 1){
            printf("%d>\n", myqueue.front());
            myqueue.pop();
            break;
        }else{
            for(int j=0; j<M-1; ++j){
                myqueue.push(myqueue.front());
                myqueue.pop();
            }
            printf("%d, ", myqueue.front());
            myqueue.pop();
        }
    }
    return 0;
}