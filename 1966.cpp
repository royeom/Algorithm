#include <iostream>
#include <queue>

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    while(test_case_num--){
        std::queue<std::pair<int, int> > myqueue;
        std::priority_queue<int> pq;
        int N, M; 
        int count = 0;
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; ++i){
            int temp;
            scanf("%d", &temp);
            myqueue.push(std::make_pair(i, temp));
            pq.push(temp);
        }
        while(!myqueue.empty()){
            int cur_idx = myqueue.front().first;
            int cur_val = myqueue.front().second;
            myqueue.pop();
            if(cur_val == pq.top()){
                pq.pop();
                count++;
                if(cur_idx == M){
                    printf("%d\n", count);
                    break;
                }
            }
            else{
                myqueue.push(std::make_pair(cur_idx, cur_val));
            }
        }
    }
    return 0;
}