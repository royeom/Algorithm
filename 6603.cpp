#include <iostream>
#include <string>
#define MAX 14

int num;
std::string lotto[MAX];

void DFS(int, int, std::string);

int main(){
    while(true){
        scanf("%d", &num);
        if(num == 0) break;
        for(int i=0; i<num; ++i){
            std::cin >> lotto[i];
        }
        DFS(0, 0, "");
    }
}

void DFS(int start, int count, std::string str){
    if(count == 6){
        for(int i=0; i<str.size(); ++i){
            printf("%d ", str[i]);
        }
        printf("\n");
        return;
    }
    for(int i=start; i<num; ++i){
        DFS(i+1, count+1, str + lotto[i] + ' ');
    }
}