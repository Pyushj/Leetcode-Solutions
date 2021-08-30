class Solution {
public:
    bool PredictTheWinner(vector<int>& arr) {
        long long int sum=0,collected=0,rem=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        long long int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;j++,i++)
            {
                if(gap==0)
                {
                    dp[i][j]=arr[i];
                }
                else if(gap==1)
                {
                    dp[i][j]=max(arr[i],arr[j]);
                }
                else
                {
                    long long int x= arr[i] + min(dp[i+2][j],dp[i+1][j-1]);
                    long long int y= arr[j] + min(dp[i][j-2] , dp[i+1][j-1]);
                    dp[i][j]= max(x,y);
                }
            }
        }
        collected=dp[0][n-1];
        rem=sum-collected;
        if(collected >=rem)
            return true;
        else
            return false;
        
    }
};
