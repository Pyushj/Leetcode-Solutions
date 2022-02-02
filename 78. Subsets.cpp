class Solution {
public:
    void subset(int idx,int n,vector<int>& nums, vector<int>& currAns,                                                                               vector<vector<int>>& res)
    {
        if(idx==n)
        {
            res.push_back(currAns);
            return;
        }
        subset(idx+1,n,nums,currAns,res);
        currAns.push_back(nums[idx]);
        subset(idx+1,n,nums,currAns,res);
        currAns.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        vector<int> currAns;
        subset(0,n,nums,currAns,res);
        return res;
    }
};
