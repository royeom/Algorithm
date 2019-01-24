#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    int test_case_number;
    std::cin >> test_case_number;
    std::vector<int> num_vec;
    int find_num;
    for(int i=0; i < test_case_number; ++i){
        int temp;
        std::cin >> temp;
        num_vec.push_back(temp);
    }
    std::cin >> find_num;

    std::cout << std::count(num_vec.begin(), num_vec.end(), find_num) << std::endl;

    return 0;
}