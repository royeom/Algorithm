class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int a = A.size(), b = B.size();
        int L[a+1][b+1] = {0, };
        int MAX = 0;
        
        for(int i=0; i<=a; ++i){
            
            for(int j=0; j<=b; ++j){
                if(i == 0 || j == 0){
                    L[i][j] = 0;
                    continue;
                }
                if(A[i-1] != B[j-1])
                    L[i][j] = 0;
                else
                    L[i][j] = L[i-1][j-1] + 1;
                MAX = max(MAX, L[i][j]);
            }
        }
        return MAX;
    }
};