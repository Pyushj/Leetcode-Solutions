class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> res;
        for(auto x: trips)
        {
            int pep=x[0];
            int from=x[1];
            int to=x[2];
            res.push_back({from,pep});
            res.push_back({to,-1*pep});
        }
        sort(res.begin(),res.end());
        
        int pep=0;
        for(auto x: res)
        {
            pep+=x.second;
            if(pep> capacity)
                return false;
        }
        return true;
        
        
    }
};
