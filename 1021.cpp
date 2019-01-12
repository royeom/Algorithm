#include <iostream>
#include <deque>

int main(){
    std::deque<int> mydeque;
    std::deque<int>::iterator iter;
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; ++i)
        mydeque.push_back(i);
    
    int count = 0;
    int idx, left, right;
    for(int i=0; i<M; ++i){
        int input;
        scanf("%d", &input);
        if(mydeque.front() == input){
            mydeque.pop_front();
        }
        else{
            idx = 1;
            for(iter = mydeque.begin(); iter < mydeque.end(); ++iter){
                if(*iter == input)
                    break;
                idx++;
            }
            left = idx -1;
            right = mydeque.size() - idx + 1;

            if(left >= right){
                for(int j=0; j<right; ++j){
                    mydeque.push_front(mydeque.back());
                    mydeque.pop_back();
                }
                count += right;
                mydeque.pop_front();
            }
            else if(left < right){
                for(int j=0; j<left; ++j){
                    mydeque.push_back(mydeque.front());
                    mydeque.pop_front();
                }
                count += left;
                mydeque.pop_front();
            }
        }
    }
    printf("%d\n", count);
}