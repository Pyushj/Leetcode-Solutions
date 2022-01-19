/*
 count the frequency of each element 
 no of good pairs  is nC2 for each element
 */

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            mp[nums[i]]++;
        }
        int count=0;
        for(auto x:mp)
        {
            int temp=x.second;
            if(temp==1)
                continue;
            count+= (temp*(temp-1))/2;
        }
        return count;
        
    }
};
