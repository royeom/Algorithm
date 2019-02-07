#include <iostream>
#include <algorithm>
int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        int score1, score2, score3;
        score1 = score2 = score3 = 0;
        int x1, y1, x2, y2, xS, xL, yS, yL;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        // x1,y1이 x2,y2보다 무조건 작은 위치(왼쪽 아래 꼭지점)을 가리키면 편하다.
        if(x1>x2)
            std::swap(x1, x2);
        if(y1>y2)
            std::swap(y1, y2);
        
        int point_num, x3, y3;
        scanf("%d", &point_num);
        for(int pn = 1; pn <= point_num; ++pn){
            scanf("%d %d", &x3, &y3);
            if(x3 < x2 && x3 > x1 && y3 < y2 && y3 > y1 ){
                score1++;
                continue;
            }
            if((x3 == x1 && y3 >= y1 && y3 <= y2)||(x3 == x2 && y3 >= y1 && y3 <= y2) || (y3 == y1 && x3 >= x1 && x3 <= x2) || (y3 == y2 && x3 >= x1 && x3 <= x2)){
                score2++;
                continue;
            }
            else{
                score3++;
                continue;
            }
        }
        printf("#%d %d %d %d\n", tcn, score1, score2, score3);
    }
}