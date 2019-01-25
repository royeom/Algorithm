#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
int maxVal = 0;
int number_size;

void DFS(int num, int cnt){
    if(cnt == 0){
        maxVal = std::max(num, maxVal);
        return;
    }
    for(int i=0; i<number_size; ++i){
        for(int j=i; j<number_size; ++j){
            if(i != j){
                int first, second;
                first = second = num;
                while(number_size-i){
                    first /= 10;
                    i++;
                }
                while(number_size-j){
                    second /= 10;
                    j++;
                }
                if(first < second){
                    num = num - std::pow(10, i)*first - std::pow(10, j)*second + std::pow(10, i)*second + std::pow(10, j)*first;
                    DFS(num, cnt--);
                }
            }
        }
    }

}

int sizeOfNumber(int number){
    int count = 1;
    while(1){
        if(number/10 == 0)
            break;
        number/= 10;
        count++;
    }
    return count;
}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=1; i<=test_case_num; ++i){
        int num,  count;
        scanf("%d %d", &num, &count);
        DFS(num, count);
        number_size = sizeOfNumber(num);
        printf("#%d %d", i, maxVal);
        maxVal = 0;
    }
    return 0;
}