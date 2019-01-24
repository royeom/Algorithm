class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookie = s.size();
        int person = g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0, j=0;
        while(i<cookie && j<person){
            if(s[i]>=g[j]){
                j++;
            }
            i++;
        }
        return j;
    }
};