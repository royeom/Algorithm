#include <iostream>
#include <algorithm>
#include <string>

int main(){
    std::string num1, num2, num3, num4;
    std::cin >> num1 >> num2 >> num3 >> num4;
    num1 += num2; 
    num3 += num4;
    printf("%llu\n", std::stoll(num1) + std::stoll(num3));
    return 0;
}