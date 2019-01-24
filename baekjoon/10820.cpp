#include <iostream>
#include <algorithm>
#include <string>

int main(){
    std::string temp;
    int lit, big, num, space;
    while(1){
        lit = big = num = space = 0;
        getline(std::cin, temp);
        if(temp == "")
            break;
        int len = temp.length();
        for(int i=0; i<len; ++i){
            if(temp[i] >= 'a' && temp[i] <= 'z')
                lit++;
            else if(temp[i] >= 'A' && temp[i] <= 'Z')
                big++;
            else if(temp[i] >= '0' && temp[i] <= '9')
                num++;
            else if(temp[i] == ' ')
                space++;
        }
        printf("%d %d %d %d\n", lit, big, num, space);
    }
    return 0;
}