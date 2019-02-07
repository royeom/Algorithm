#include <iostream>

int main(){
    int test_num_case;
    scanf("%d", &test_num_case);
    for(int tnc = 1; tnc <= test_num_case; ++tnc){
        int D, H, M;
        scanf("%d %d %d", &D, &H, &M);
        int answer = M-11 + (H-11)*60 + (D-11)*60*24; 
        if(answer < 0)
            printf("#%d -1\n", tnc);
        else
            printf("#%d %d\n", tnc, answer);
    }
}