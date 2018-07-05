#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

int main(){
    int test_case_number;
    std::string input_str;
    std::cin >> input_str >> test_case_number;
    std::stack<int> stack_right;
    std::stack<int> stack_left;
    int len = input_str.length();
    for(int j=0; j<len; ++j){
        stack_left.push(input_str[j]);
    }
    char command;
    for(int i=0; i<test_case_number; ++i){
        std::cin >> command;
        if(command == 'L'){
            if(!stack_left.empty()){
                char temp;
                temp = stack_left.top();
                stack_left.pop();
                stack_right.push(temp);
            }
        }else if(command == 'D'){
            if(!stack_right.empty()){
                char temp;
                temp = stack_right.top();
                stack_right.pop();
                stack_left.push(temp);
            }
        }else if(command == 'B'){
            if(!stack_left.empty()){
                stack_left.pop();
            }
        }else if(command == 'P'){
            char temp;
            std::cin >> temp;
            stack_left.push(temp);
        }
    }
    std::string result;
    int stack_size = stack_left.size();
    for(int k=0; k<stack_size; ++k){
        result += stack_left.top();
        stack_left.pop();
    }
    std::reverse(result.begin(), result.end());
    stack_size = stack_right.size();
    for(int l=0; l<stack_size; ++l){
        result += stack_right.top();
        stack_right.pop();
    }
    std::cout << result;
    printf("\n");
    return 0;
}