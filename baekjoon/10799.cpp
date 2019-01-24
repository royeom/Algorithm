#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

int main(){
    std::string test_string;
    std::cin >> test_string;
    int len = test_string.length();
    std::stack<char> mystack;
    int result = 0;
    for(int i=0; i<len; ++i){
        if(test_string[i] == '('){
            mystack.push('(');
        }
        else{
            mystack.pop();
            if(test_string[i-1] == '(')
                result += mystack.size();
            else
                result++;
        }
    }
    printf("%d\n", result);
    return 0;
}