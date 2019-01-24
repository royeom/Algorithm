class Solution {
public:
    // int max=-99999;
    int maxProduct(vector<int>& nums) {
//         int size = nums.size();
//         if(size == 0) return 0;
//         if(size == 1) return nums[0];
//         int temp;
        
//         for(int i=0; i<size; ++i){
//             temp = 1;
//             for(int j=i; j<size; ++j){
//                 temp *= nums[j];
//                 if(temp >= max)
//                     max = temp;
//             }
//         }
//         return max;
        int size = nums.size();
        if(size == 0)
            return 0;
        
        int curMax = nums[0];
        int curMin = nums[0];
        int result = nums[0];
        
        for(int i = 1; i < size; ++i){
            int tempMax = curMax * nums[i];
            int tempMin = curMin * nums[i];
            
            curMax = max(nums[i], max(tempMax, tempMin));
            curMin = min(nums[i], min(tempMax, tempMin));
            
            result = max(result, curMax);
            
        }
        
        return result;
    }
};