#include<iostream>
#include<vector>
using namespace std;

int tiling(int n)
{
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  for(int i=3; i<=n; ++i){
    int temp = vec[i-1]+vec[i-2];
  	vec.push_back(temp % 100000);
  }
	int answer = vec[n];
	return answer;
}
int main()
{
	int testn = 2;
	int testAnswer = tiling(testn);

	cout<< testAnswer;
}
