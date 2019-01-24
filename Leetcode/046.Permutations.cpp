class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
	void permuteRecursive(vector<int> &num, int start, vector<vector<int> > &result)	{
		if (start >= num.size()) {
		    
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