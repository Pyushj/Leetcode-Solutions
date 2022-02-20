class Solution {
public:
    vector<vector<int>> res;
    void permute(unordered_map<int,int>& mp,vector<int>& currAns,int n)
    {
        if(currAns.size()==n)
        {
            res.push_back(currAns);
            return;
        }
        for(auto x:mp)
        {
            int key=x.first;
            int freq=x.second;
            if(freq<=0)
                continue;
            mp[key]=freq-1;
            currAns.push_back(key);
            permute(mp,currAns,n);
            mp[key]=freq;
            currAns.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        vector<int> currAns;
        int n=nums.size();
        
        permute(mp,currAns,n);
        return res;
        
        
    }
};
