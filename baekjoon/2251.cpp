#include <iostream>
#include <cstring>
#define MAX 201

bool check_visit[MAX][MAX][MAX] = {false, };
int A, B, C;

void DFS(int a, int b, int c){
    if(c > 0){
        // C->A
        if(a + c > A){
            if(!check_visit[A][b][a+c-A]){
                check_visit[A][b][a+c-A] = true;
                DFS(A, b, a+c-A);
            }
        }else{
            if(!check_visit[a+c][b][0]){
                check_visit[a+c][b][0] = true;
                DFS(a+c, b, 0);
            }
        }
        //C->B
        if(b + c > B){
            if(!check_visit[a][B][b+c-B]){
                check_visit[a][B][b+c-B] = true;
                DFS(a, B, b+c-B);
            }
        }else{
            if(!check_visit[a][b+c][0]){
                check_visit[a][b+c][0] = true;
                DFS(a, b+c, 0);
            }
        }
    }
    if(b > 0){
        // B->A
        if(a + b > A){
            if(!check_visit[A][a+b-A][c]){
                check_visit[A][a+b-A][c] = true;
                DFS(A, a+b-A, c);
            }
        }else{
            if(!check_visit[a+b][0][c]){
                check_visit[a+b][0][c] = true;
                DFS(a+b, 0, c);
            }
        }
        // B->C
        if(b + c > C){
            if(!check_visit[a][b+c-C][C]){
                check_visit[a][b+c-C][C] = true;
                DFS(a, b+c-C, C);
            }
        }else{
            if(!check_visit[a][0][b+c]){
                check_visit[a][0][b+c] = true;
                DFS(a, 0, b+c);
            }
        }
    }
    if(a > 0){
        // A->B
        if(b + a > B){
            if(!check_visit[b+a-B][B][c]){
                check_visit[b+a-B][B][c] = true;
                DFS(b+a-B, B, c);
            }
        }else{
            if(!check_visit[0][a+b][c]){
                check_visit[0][a+b][c] = true;
                DFS(0, a+b, c);
            }
        }
        // A->C
        if(c + a > C){
            if(!check_visit[c+a-C][b][C]){
                check_visit[c+a-C][b][C] = true;
                DFS(c+a-C, b, C);
            }
        }else{
            if(!check_visit[0][b][c+a]){
                check_visit[0][b][c+a] = true;
                DFS(0, b, c+a);
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &A, &B, &C);
    memset(check_visit, false, sizeof(check_visit));
    DFS(0, 0, C);
    bool final_check[201] = {false, };

    for(int i=0; i<=B; ++i){
        for(int j=0; j<=C; ++j){
            if(check_visit[0][i][j]){
                final_check[j] = true;
            }
        }
    }
    for(int i=0; i<=C; ++i){
        if(final_check[i]){
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}