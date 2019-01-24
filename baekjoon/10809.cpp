#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main(){

    std::string test_str;
    std::cin >> test_str;
    std::vector<int> find_vec;
    int test_str_len = test_str.length();
    for(int i=0; i < 26; ++i)
        find_vec.push_back(-1);

    for(int j=0; j<test_str_len; ++j){
        if(find_vec[test_str[j]-97] == -1){
            find_vec[test_str[j]-97] = j;
        }
    }

    for(int k=0; k < 26; ++k){
        std::cout << find_vec[k] << " ";
    }
    std::cout << std::endl;

    return 0;
}