#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    int test_case_number;
    int vec_size;
    std::cin >> vec_size >> test_case_number;
    std::vector<int> num_vec;

    for(int i=0; i<vec_size; ++i)
        num_vec.push_back(i+1);

    int left, right;
    for(int j=0; j < test_case_number; ++j){
        std::cin >> left >> right;
        std::swap(num_vec[left-1], num_vec[right-1]);
    }

    for(int i=0; i<vec_size; ++i)
        std::cout << num_vec[i] << " ";
    std::cout << std::endl;

    return 0;
}