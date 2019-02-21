#include <iostream>
#include <queue>
#include <cstring>

int N1, N2;
bool check_visit[10000] = {false, };
std::string answer;

struct State{
    int num;
    std::string str;
    State(int _num, std::string _str) : num(_num), str(_str) {}
};

int D(int num){
    num = (num * 2) % 10000;
    return num;
}

int S(int num){
    num -= 1;
    if(num == -1)   num = 9999;
    return num;
}

int L(int num){
    int front = num / 1000;
    int back = num % 1000;
    num = (back * 10) + front;
    return num;
}

int R(int num){
    int temp = num % 10;
    num = (temp * 1000) + num / 10;
    return num;
}

void BFS(){
    std::queue<State> myqueue;
    myqueue.push(State(N1, ""));
    check_visit[N1] = true;
    while(!myqueue.empty()){
        int num = myqueue.front().num;
        std::string str = myqueue.front().str;
        myqueue.pop();

        if(num == N2){
            answer += str;
            return;
        }

        int next_num;
        next_num = D(num);
        if (!check_visit[next_num]){
            myqueue.push(State(next_num, str + "D"));
            check_visit[next_num] = true;
        }
        next_num = S(num);
        if (!check_visit[next_num]){
            myqueue.push(State(next_num, str + "S"));
            check_visit[next_num] = true;
        }
        next_num = L(num);
        if (!check_visit[next_num]){
            myqueue.push(State(next_num, str + "L"));
            check_visit[next_num] = true;
        }
        next_num = R(num);
        if (!check_visit[next_num]){
            myqueue.push(State(next_num, str + "R"));
            check_visit[next_num] = true;
        }
    }
}

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int i=0; i < test_case_num; ++i){
        memset(check_visit, false, sizeof(check_visit));
        answer = "";
        scanf("%d %d", &N1, &N2);
        BFS();
        std::cout << answer << std::endl;
    }
    return 0;
}