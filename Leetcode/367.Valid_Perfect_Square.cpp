class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1;
        int end = min(num, 46340);
        while(start<=end){
            int mid = (start+end)/2;
            if(mid*mid < num) start = mid+1;
            else if(mid*mid > num) end = mid-1;
            else return true;
        }
        return false;
    }
};


