class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int temp1 = 2147483647, temp2 =2147483647;
        int size = nums.size();
        for(int i=0; i<size; ++i) {
            if(nums[i] <= temp1)
                temp1 = nums[i];
            else if(nums[i] <= temp2)
                temp2 = nums[i];
            else 
                return true;
        }
        return false;
    }
};