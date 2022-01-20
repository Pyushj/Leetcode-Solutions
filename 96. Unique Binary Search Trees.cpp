class Solution {
public:
    int numTrees(int n) {
        if(n<=1)
            return 1;
        int dp[n+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int k=0,sum=0;
            for(int j=i-1;j>=0;j--)
            {
                sum+=dp[j]*dp[k];
                k++;
            }
            dp[i]=sum;
        }
        return dp[n];
        
        
    }
};
