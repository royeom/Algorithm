#include <iostream>
#include <cstring>

int main(){
    int N, count;
    scanf("%d", &N);
    for(int i=1; i<=N; ++i){
        std::string temp = std::to_string(i);
        count = 0;
        for(int j=0; j<temp.length(); ++j){
            if(temp[j] == '3' || temp[j] == '6' || temp[j] == '9')
                count++;
        }
        if(count == 0)
            printf("%d ", i);
        else{
            for(int k=0; k<count; ++k)
                printf("-");
            printf(" ");
        }
    }
    printf("\n");
}