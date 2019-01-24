#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    int test_case_number;
    int vec_size;
    std::cin >> vec_size >> test_case_number;
    std::vector<int> num_vec;

    for(int i=0; i<vec_size; ++i)
        num_vec.push_back(0);

    int left, right, value;
    for(int j=0; j < test_case_number; ++j){
        std::cin >> left >> right >> value;
        std::fill(num_vec.begin() + left - 1, num_vec.begin() + right, value);
    }

    for(int i=0; i<vec_size; ++i)
        std::cout << num_vec[i] << " ";
    std::cout << std::endl;

    return 0;
}