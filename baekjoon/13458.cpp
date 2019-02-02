#include <iostream>
#define MAX 1000000
int A;
long long B, C;
long long arr[MAX];

int main(){
    scanf("%d", &A);
    for(int i=1; i<=A; ++i){
        scanf("%lld", &arr[i]);
    }
    scanf("%lld %lld", &B, &C);
    long long total = 0;
    for(int i=1; i<=A; ++i){
        long long temp = arr[i] - B;
        total += 1;
        if(temp <= 0){
            continue;
        }
        else{
            if(temp%C == 0){
                total += temp/C;
            }
            else{
                total += temp/C + 1;
            }
        }
    }
    printf("%lld\n", total);
}