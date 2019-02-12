#include <iostream>
#include <cstring>

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        char s[5][17] = { 0, };
        for (int i = 0; i < 5; ++i)
            std::cin >> s[i];
        printf("#%d ", tcn);
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 5; ++j){
                if (s[j][i])
                    std::cout << s[j][i];
            }
        }
        printf("\n");
    }
}