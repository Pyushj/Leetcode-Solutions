class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),length,maxLength=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            nums[i]=-1;
        }
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum)==mp.end())
            {
             mp[sum]=i;   
            }
            else
            {
                length=i-mp[sum];
                maxLength=max(length,maxLength);
            }
        }
        return maxLength;
        
    }
};
