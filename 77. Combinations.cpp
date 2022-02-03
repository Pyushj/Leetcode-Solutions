class Solution {
public:
void subset(int idx,int k,vector<int>& nums,vector<int>& curr,vector<vector<int>>& res)
{
    if(idx==nums.size())
    {
        if(curr.size()==k)
            res.push_back(curr);
        return;
    }
    if(curr.size() > k)
        return;
     
    subset(idx+1,k,nums,curr,res);
    curr.push_back(nums[idx]);
    subset(idx+1,k,nums,curr,res);
    curr.pop_back();
    return;
}
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                res.push_back({i});
            }
            return res;
        }
        
        vector<int> nums,curr;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        
        if(n==k)
        {
            res.push_back(nums);
            return res;
        }
        subset(0,k,nums,curr,res);
        return res;
    }
};
