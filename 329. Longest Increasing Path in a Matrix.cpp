class Solution {
public:
    int dp[205][205];
    int dfs(int r,int c,int m,int n,vector<vector<int>>& matrix,int prev)
    {
        if(r<0 || r>=m || c<0 || c>=n || matrix[r][c]<=prev)
            return 0;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        static int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        int temp=0;
        for(int k=0;k<4;k++)
        {
            int row=r+ dir[k][0];
            int col=c+ dir[k][1];
            
            temp=max(temp,dfs(row,col,m,n,matrix,matrix[r][c]));
        }
        return dp[r][c]= 1+ temp;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        
        int path=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=dfs(i,j,m,n,matrix,INT_MIN);
                path=max(path,temp);
            }
        }
        return path;
        
    }
};
