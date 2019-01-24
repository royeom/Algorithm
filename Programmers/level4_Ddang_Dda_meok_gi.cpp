#include<iostream>
#include<vector>
using namespace std;

int hopscotch(vector<vector<int> > board)
{
	// 함수를 완성하세요.
	int answer = 0;
  int board_size = board.size();
  int max = 0;
	for(int i=1; i<board_size; ++i){
    for(int j=0; j<4; ++j){
      for(int k=0; k<4; ++k){
        if(j!=k){
          max = board[i-1][k] > max ? board[i-1][k] : max;
        }
      }
      board[i][j] += max; 
      max = 0;
    }
  }
  for(int i=0; i<4; ++i){
   answer = board[board_size-1][i] > answer ? board[board_size-1][i] : answer;
  }
  return answer;
}

int main()
{
	vector<vector<int> > test{{1,2,3,5},{5,6,7,8},{4,3,2,1}};
 //아래는 테스트로 출력해 보기 위한 코드입니다.
	cout << hopscotch(test);
}
