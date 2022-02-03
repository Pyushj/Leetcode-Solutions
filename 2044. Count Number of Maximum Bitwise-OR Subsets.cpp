class Solution {
public:
    void subset(int idx,int n,vector<int>& nums,int currOR,unordered_map<int,int>& mp)
    {
        if(idx==n)
        {
            mp[currOR]++;
            return;
        }
        subset(idx+1,n,nums,currOR,mp);
        subset(idx+1,n,nums,(currOR | nums[idx]),mp); 
        return;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        subset(0,n,nums,0,mp);
        int mx=0;
        for(auto x:mp)
        {
            mx=max(mx,x.first);
        }
        return mp[mx];
    }
};
