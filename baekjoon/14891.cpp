#include <iostream>
char wheel[5][8];
int N;

void rotate_right(int num){
    char temp = wheel[num][7];
    for(int i=7; i>0; --i){
        wheel[num][i] = wheel[num][i-1];
    }
    wheel[num][0] = temp;
}

void rotate_left(int num){
    char temp = wheel[num][0];
    for(int i=0; i<7; ++i){
        wheel[num][i] = wheel[num][i+1];
    }
    wheel[num][7] = temp;
}

void Rotate(int num, int direction){
    switch(num){
        case 1:
            if(direction == 1){
                if(wheel[1][2] != wheel[2][6]){
                    rotate_left(2);
                    if(wheel[2][3] != wheel[3][6]){
                        rotate_right(3);
                        if(wheel[3][1] != wheel[4][6])
                            rotate_left(4);
                    }
                }
                rotate_right(1);
            }else if(direction == -1){
                if(wheel[1][2] != wheel[2][6]){
                    rotate_right(2);
                    if(wheel[2][1] != wheel[3][6]){
                        rotate_left(3);
                        if(wheel[3][3] != wheel[4][6])
                            rotate_right(4);
                    }
                }
                rotate_left(1);
            }
            break;
        case 2:
            if(direction == 1){
                if(wheel[1][2] != wheel[2][6]){
                    rotate_left(1);
                }
                if(wheel[2][2] != wheel[3][6]){
                    rotate_left(3);
                    if(wheel[3][1] != wheel[4][6])
                        rotate_right(4);
                }
                rotate_right(2);
            }else if(direction == -1){
                if(wheel[1][2] != wheel[2][6]){
                    rotate_right(1);
                }
                if(wheel[2][2] != wheel[3][6]){
                    rotate_right(3);
                    if(wheel[3][3] != wheel[4][6])
                        rotate_left(4);
                }
                rotate_left(2);
            }
            break;
        case 3:
            if(direction == 1){
                if(wheel[2][2] != wheel[3][6]){
                    rotate_left(2);
                    if(wheel[2][5] != wheel[1][2]){
                        rotate_right(1);
                    }
                }
                if(wheel[3][2] != wheel[4][6]){
                    rotate_left(4);
                }
                rotate_right(3);
            }else if(direction == -1){
                if(wheel[2][2] != wheel[3][6]){
                    rotate_right(2);
                    if(wheel[2][7] != wheel[1][2]){
                        rotate_left(1);
                    }
                }
                if(wheel[3][2] != wheel[4][6]){
                    rotate_right(4);
                }
                rotate_left(3);
            }
            break;
        case 4:
            if(direction == 1){
                if(wheel[3][2] != wheel[4][6]){
                    rotate_left(3);
                    if(wheel[3][5] != wheel[2][2]){
                        rotate_right(2);
                        if(wheel[2][7] != wheel[1][2])
                            rotate_left(1);
                    }
                }
                rotate_right(4);
            }else if(direction == -1){
                if(wheel[3][2] != wheel[4][6]){
                    rotate_right(3);
                    if(wheel[3][7] != wheel[2][2]){
                        rotate_left(2);
                        if(wheel[2][5] != wheel[1][2])
                            rotate_right(1);
                    }
                }
                rotate_left(4);
            }
            break;
    }
}

int main(){
    for(int i=1; i<=4; ++i){
        for(int j=0; j<8; ++j){
            std::cin >> wheel[i][j];
        }
    }
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        int num, direction;
        scanf("%d %d", &num, &direction);
        Rotate(num, direction);
    }
    int score = 0;
    if(wheel[1][0] == '1') score += 1;
    if(wheel[2][0] == '1') score += 2;
    if(wheel[3][0] == '1') score += 4;
    if(wheel[4][0] == '1') score += 8;

    printf("%d\n", score);
}