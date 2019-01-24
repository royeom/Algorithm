#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

int main(){
    int test_case_number;
    std::cin >> test_case_number;
    std::stack<int> mystack;
    std::string command;
    for(int i=0; i<test_case_number; ++i){
        std::cin >> command;
        if(command =="push"){
            int temp;
            std::cin >> temp;
            mystack.push(temp);
        }else if(command == "pop"){
            if(mystack.empty()){
                printf("-1\n");
            }else{
                int temp = mystack.top();
                printf("%d\n", temp);
                mystack.pop();
            }
        }else if(command == "size"){
            printf("%d\n", mystack.size());
        }else if(command == "empty"){
            printf("%d\n", mystack.empty());
        }else if(command == "top"){
            if(mystack.empty()){
                printf("-1\n");
            }else{
                printf("%d\n", mystack.top());
            }
        }
    }
    return 0;
}