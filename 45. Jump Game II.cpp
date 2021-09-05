class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=INT_MAX;
        
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            int j=1;
            while(i+j<n && j<=nums[i])
            {
                dp[i+j]=min(dp[i+j],dp[i]+1);
                j++;
            }
        }
        return dp[n-1];
    }
};
