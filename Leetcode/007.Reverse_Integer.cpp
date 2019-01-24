class Solution {
public:
    int reverse(int x) {
        long result=0;
        
        while(x>=10 || x<=-10){
            
            result += x%10;
            
            if(result*10 <-2147483648 || result*10 >2147483647)
                return 0;
            else
                result *= 10;
            
            x /= 10;
            
        }
        result += x;
        return result;
    }
};