class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& num) {
        vector<vector<int> > result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
	void permuteRecursive(vector<int> &num, int start, vector<vector<int> > &result)	{
		if (start >= num.size()) {
            for(int i=0; i<result.size(); ++i){
                if(result[i] == num)
                    return;
            }
		    result.push_back(num);
		    return;
		}
		
		for (int i = start; i < num.size(); i++) {
		    swap(num[start], num[i]);
		    permuteRecursive(num, start + 1, result);
		    swap(num[start], num[i]);
		}
    }
};