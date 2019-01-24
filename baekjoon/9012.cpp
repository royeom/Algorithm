#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

bool ParenCheck(std::string str){
    std::stack<char> mystack;
    int str_len = str.length();
    for(int i=0; i<str_len; ++i){
        if(str[i] == '('){
            mystack.push(str[i]);
        }else{
            if(mystack.empty()){
                return false;
            }else{
                mystack.pop();
            }
        }
    }
    if(mystack.empty()){
        return true;
    }else{
        return false;
    }
}
int main(){
    int test_case_number;
    std::cin >> test_case_number;
    std::string temp;
    for(int i=0; i<test_case_number; ++i){
        std::cin >> temp;
        if(ParenCheck(temp)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}