#include <iostream>
#include <string>

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int t=1; t<=test_case_num; ++t){
        printf("#%d ", t);
        int deck[4][13] = {0, };
        std::string str;
        std::cin >> str;
        bool flag = true;
        for(int i=0; i<str.length(); i = i+3){
            int shape;
            int number = 10 * (str[i+1] - '0') + (str[i+2] - '0');
            if(str[i] == 'S')
                shape = 0;
            if(str[i] == 'D')
                shape = 1;
            if(str[i] == 'H')
                shape = 2;
            if(str[i] == 'C')
                shape = 3;
            if(deck[shape][number-1] != 0){
                flag = false;
                break;
            }
            else{
                deck[shape][number-1]++;
            }
        }
        int S_num, D_num, H_num, C_num;
        S_num = D_num = H_num = C_num = 0;
        for(int i=0; i<4; ++i){
            for(int j=0; j<13; ++j){
                if(deck[i][j] == 0){
                    if(i==0) S_num++;
                    if(i==1) D_num++;
                    if(i==2) H_num++;
                    if(i==3) C_num++;
                }
            }
        }
        if(flag)
            printf("%d %d %d %d\n", S_num, D_num, H_num, C_num);
        else
            printf("ERROR\n");
    }
    return 0;
}