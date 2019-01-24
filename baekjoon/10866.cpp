#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

int main(){
    int test_case_number;
    std::cin >> test_case_number;
    std::deque<int> mydeque;
    std::string command;
    for(int i=0; i<test_case_number; ++i){
        std::cin >> command;
        if(command =="push_front"){
            int temp;
            std::cin >> temp;
            mydeque.push_front(temp);
        }else if(command =="push_back"){
            int temp;
            std::cin >> temp;
            mydeque.push_back(temp);
        }else if(command == "pop_front"){
            if(mydeque.empty()){
                printf("-1\n");
            }else{
                int temp = mydeque.front();
                printf("%d\n", temp);
                mydeque.pop_front();
            }
        }else if(command == "pop_back"){
            if(mydeque.empty()){
                printf("-1\n");
            }else{
                int temp = mydeque.back();
                printf("%d\n", temp);
                mydeque.pop_back();
            }
        }else if(command == "size"){
            printf("%d\n", mydeque.size());
        }else if(command == "empty"){
            printf("%d\n", mydeque.empty());
        }else if(command == "front"){
            if(mydeque.empty()){
                printf("-1\n");
            }else{
                printf("%d\n", mydeque.front());
            }
        }else if(command == "back"){
            if(mydeque.empty()){
                printf("-1\n");
            }else{
                printf("%d\n", mydeque.back());
            }
        }
    }
    return 0;
}