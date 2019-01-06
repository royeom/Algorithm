#include <iostream>

int main(){
    int total = 0;
    int maxVal = 0;
    for(int i=0; i<4; ++i){
        int geton, getoff;
        scanf("%d %d", &getoff, &geton);
        total = total + geton - getoff;
        if(maxVal < total)
            maxVal = total;
    }
    printf("%d\n", maxVal);
}