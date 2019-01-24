#include <iostream>
#include <algorithm>
#include <string>

int main(){
    std::string str;
    getline(std::cin, str);
    int len = str.length();
    for(int i=0; i<len; ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            if(str[i]+13 > 'z')
                str[i] -= 13;
            else   
                str[i] += 13;
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            if(str[i]+13 > 'Z')
                str[i] -= 13;
            else   
                str[i] += 13;
        }
    }
    std::cout << str;
    printf("\n");
    return 0;
}