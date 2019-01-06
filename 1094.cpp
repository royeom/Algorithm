#include <iostream>

int main(){
    int ruler = 64;
    int count = 0;
    int sum = 0;
    int x;
    scanf("%d", &x);

    if(x == 64){
        printf("1\n");
        return 0;
    }
    while(x != sum){
        ruler /= 2;
        if(ruler + sum > x)
            continue;
        sum += ruler;
        count++;
    }

    printf("%d\n", count);
    return 0;
}