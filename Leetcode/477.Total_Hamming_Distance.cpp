class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        int *lastNum = new int[2];
        while(true){
            int count = 0;
            lastNum[0] = 0;
            lastNum[1] = 0;
            for(int i=0; i<size; ++i){
                if(nums[i] == 0)
                    count++;
                lastNum[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            res += lastNum[0] * lastNum[1];
            if(count == size)
                return res;
        }
    }
};