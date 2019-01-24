class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        int L[length+1][length+1] = {0, };
        int MAX = 0;
        
        for(int i=0; i<=length; ++i){
            for(int j=0; j<=length; ++j){
                if(i == 0 || j == 0){
                    L[i][j] = 0;
                    continue;
                }
                if(s.at(i-1) != rev.at(j-1))
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
                else
                    L[i][j] = L[i-1][j-1] + 1;
                MAX = max(MAX, L[i][j]);
            }
        }
        return MAX;
    }
};