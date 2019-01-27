#include <iostream>

int main(){
    int N;
    scanf("%d", &N);
    int count = 0;
    while(N/5 <= N/3){
        if(N < 0){
            break;
        }
        if(N%5 == 0){
            count += N/5;
            break;
        }
        N -= 3;
        count++;
    }
    if(N < 0)
        printf("-1\n");
    else
        printf("%d\n", count);  
}