#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(){
    std::string str;
    std::cin >> str;
    int len = str.length();
    std::vector<std::string> vec;
    for(int i=0; i < len; ++i){
        std::string temp = "";
        for(int j=i; j<len; ++j){
            temp += str[j];
        }
        vec.push_back(temp);
        // std::cout<< i << " : " << temp << "\n";
        temp = "";
    }
    std::sort(vec.begin(), vec.end());
    int vec_size = vec.size();
    for(int j=0; j<vec_size; ++j){
        std::cout << vec[j] << "\n";
    }
    return 0;
}