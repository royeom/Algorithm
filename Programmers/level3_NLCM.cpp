#include<iostream>
#include<vector>
using namespace std;

long long gcd(long long a, long long b)
{
  long long c;
  while(b!=0){
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

long long lcm(long long a, long long b)
{
  return a * b / gcd(a,b);
}

long long nlcm(vector<int> num)
{
	long long answer = num[0];
	for(int i=0; i<num.size()-1; ++i){
    answer = lcm(answer, num[i+1]);
  }
  return answer;
}

int main()
{
	vector<int> test{2,6,8,14};

	// 아래는 테스트로 출력해 보기 위한 코드입니다.
	cout << nlcm(test);
}
