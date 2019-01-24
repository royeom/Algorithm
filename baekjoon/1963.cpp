#include <iostream>
#include <queue>
#define MAX 10000

bool isPrimeNumber(int number){
    int i = 0;
    int last = number / 2;
    if(number <= 1)
        return false;
    for(i = 2; i <= last; ++i){
        if((number%i) == 0)
            return false;
    }
    return true;
}

void BFS(int num1, int num2){
    int count = 0;
    int num[4];
    std::queue<int> myqueue;
    bool check_visit[MAX] = {false, };
    myqueue.push(num1);
    check_visit[num1] = true;
    bool success_flag = false;

    while(!myqueue.empty()){
        int q_size = myqueue.size();
        while(q_size--){
            int cur_num = myqueue.front();
            myqueue.pop();

            if(cur_num == num2){
                success_flag = true;
                break;
            }
            for(int i=0; i<4; ++i){
                for(int j=0; j<10; ++j){
                    if(i==0 && j==0)
                        continue;
                    num[0] = cur_num/1000;
                    num[1] = cur_num%1000 / 100;
                    num[2] = (cur_num%1000)%100 / 10;
                    num[3] = cur_num%10;
                    num[i] = j;

                    int next_num = num[0]*1000 + num[1]*100 + num[2]*10 + num[3];
                    if(isPrimeNumber(next_num) && !check_visit[next_num]){
                        check_visit[next_num] = true;
                        myqueue.push(next_num);
                    }
                }
            }
        }
        if(success_flag) break;
        count++;
    }

    if(success_flag == true)
        printf("%d\n", count);
    else
        printf("Impossible\n");
    
}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=0; i<test_case_num; ++i){
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        BFS(num1, num2);
    }
}