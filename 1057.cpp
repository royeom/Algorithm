#include <iostream>

int main(){
    int N, kim, lim;
    scanf("%d %d %d", &N, &kim, &lim);
    if(kim == lim || N < kim || N < lim){
        printf("-1\n");
        return 0;
    }
    int count = 0;

    while(kim != lim){
        kim = kim/2 + kim%2;
        lim = lim/2 + lim%2;
        count++;
    }

    printf("%d\n", count);
}