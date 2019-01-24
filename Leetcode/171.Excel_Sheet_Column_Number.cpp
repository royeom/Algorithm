class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int result = 0;
        for(int i=0; i<len; ++i){
            result += pow(26,len-1-i) * (s.at(i) - 64);
        }
        return result;
    }
};