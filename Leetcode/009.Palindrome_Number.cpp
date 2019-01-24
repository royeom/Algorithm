class Solution {
public:
    bool isPalindrome(int x) {
        long result=0;
        int temp = x;
        while(x>=10 || x<=-10){
            
            result += x%10;
            
            if(result*10 <-2147483648 || result*10 >2147483647)
                return 0;
            else
                result *= 10;
            
            x /= 10;
            
        }
        result += x;
        
        if(result != temp || temp <0)
            return false;
        else
            return true;
    }
};