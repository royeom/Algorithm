#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<int> works)
{
  int maxIndex = works[0];
  int index = 0;
  int size = works.size();
  
  for(int i=1; i<size; ++i){
    if(maxIndex < works[i]){
      maxIndex = works[i];
      index = i;
    }
  }
  return index;
}

int noOvertime(int no,vector<int> works)
{
  int size = works.size();
	int answer = 0;
	while(no!=0){
    works[findMax(works)]--;
    no--;
  }
  for(int i=0; i<size; ++i){
    answer += works[i] * works[i];
  }
	return answer;
}

int main()
{
	vector<int> works{4,3,3};
	int testNo = 4;

	int testAnswer = noOvertime(testNo,works);

	cout<<testAnswer;
}