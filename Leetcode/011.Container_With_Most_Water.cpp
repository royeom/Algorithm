class Solution {
public:
    int maxArea(vector<int>& height) {
        
        if(height.size() <2) return 1;
        
        int start = 0;
        int end = height.size() - 1;
        int result;
        int temp = 0;
        while(start < end){
            result = (end - start) * abs(min(height[end], height[start]));
            result = max(result, temp);
            if(height[start] < height[end])
                start++;
            else if(height[start] > height[end])
                end--;
            else{
                start++;
                end--;
            }

            temp = result;
                
        }
        return temp;
    }
};