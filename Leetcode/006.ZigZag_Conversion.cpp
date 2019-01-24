class Solution {
public:
    string convert(string s, int numRows) {
        string result ="";
        string strarr[numRows] = {"", };
        int len = s.length();
        int i = 0;
        int curRow = 0;
        bool rising = true;
        
        if(numRows == 1 || len == 0)
            return s;
        
        while(i<len){
            if(rising == true){
                strarr[curRow].append(1, s.at(i++));
                curRow++;
                if(curRow == numRows -1){
                    rising = false;
                }
            }
            else{
                strarr[curRow].append(1, s.at(i++));
                curRow--;
                if(curRow == 0){
                    rising = true;
                }
            }
        }
        for(int j=0; j<numRows; j++){
            result += strarr[j];
        }
        return result;
        
    }
};