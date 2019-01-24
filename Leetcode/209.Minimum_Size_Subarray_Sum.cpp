class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int size = nums.size();
        if(size == 0) return 0;
        int res[size] ={0,};
        int sum = 0;
        int count = 0;
        int pivot = 0;
        int min = 9999;
        
        for(int i=0; i<size; ++i){
            sum += nums[i];
            count++;
            if(sum >= s){
                while(sum - nums[pivot] >= s){
                    count--;
                    sum -= nums[pivot];
                    pivot++;
                }
                res[i] = count;
            }
            if(res[i] < min && res[i] != 0)
                min = res[i];
        }
        
        if(min == 9999)
            return 0;
        return min;
    }
};