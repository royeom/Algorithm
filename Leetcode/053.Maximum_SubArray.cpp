class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0;
        int size = nums.size();
        int result = INT_MIN;
        for(int i = 0; i < size; ++i){
            prev = max(prev + nums[i] , nums[i]);
            result = max(result, prev);
        }
        return result;
    }
};