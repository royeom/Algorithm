#include <iostream>
#include <cstring>
char alter[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
std::string answer;
int num;

// void Check_Letter(){
//     for(int i=0; i<temp.size(); ++i){
//         switch(temp[i]){
//             case 'a': case 'b': case 'c':
//                 temp[i] = '2'; 
//                 break;
//             case 'd': case 'e': case 'f':
//                 temp[i] = '3';
//                 break;
//             case 'g': case 'h': case 'i':
//                 temp[i] = '4';
//                 break;
//             case 'j': case 'k': case 'l':
//                 temp[i] = '5';
//                 break;
//             case 'm': case 'n': case 'o':
//                 temp[i] = '6';
//                 break;
//             case 'p': case 'q': case 'r': case 's':
//                 temp[i] = '7';
//                 break;
//             case 't': case 'u': case 'v':
//                 temp[i] = '8';
//                 break;
//             case 'w': case 'x': case 'y': case 'z':
//                 temp[i] = '9';
//                 break;
//             default:
//                 break;
//         }
//     }
// }

int main(){
    int test_case_num;
    scanf("%d", &test_case_num);
    
    for(int tcn = 1; tcn <= test_case_num; ++tcn){
        std::cin >> answer >> num ;
        int count = 0;

        for(int ln = 0; ln < num; ++ln){
            std::string str;
            std::cin >> str;
            if(str.size() != answer.size())
                continue;

            bool flag = true;
            for(int i=0; i<str.size(); ++i){
                if(alter[str[i] - 'a'] != answer[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) 
                count++;
        }
        printf("#%d %d\n", tcn, count);
    }
}