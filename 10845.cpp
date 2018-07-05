#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

int main(){
    int test_case_number;
    std::cin >> test_case_number;
    std::queue<int> myqueue;
    std::string command;
    for(int i=0; i<test_case_number; ++i){
        std::cin >> command;
        if(command =="push"){
            int temp;
            std::cin >> temp;
            myqueue.push(temp);
        }else if(command == "pop"){
            if(myqueue.empty()){
                printf("-1\n");
            }else{
                int temp = myqueue.front();
                printf("%d\n", temp);
                myqueue.pop();
            }
        }else if(command == "size"){
            printf("%d\n", myqueue.size());
        }else if(command == "empty"){
            printf("%d\n", myqueue.empty());
        }else if(command == "front"){
            if(myqueue.empty()){
                printf("-1\n");
            }else{
                printf("%d\n", myqueue.front());
            }
        }else if(command == "back"){
            if(myqueue.empty()){
                printf("-1\n");
            }else{
                printf("%d\n", myqueue.back());
            }
        }
    }
    return 0;
}