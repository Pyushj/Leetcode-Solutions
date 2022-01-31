class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,int m,int n)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
            return 0;
        int curr=grid[i][j];
        grid[i][j]=0;
        
        int top= dfs(i-1,j,grid,m,n);
        int down= dfs(i+1,j,grid,m,n);
        int left= dfs(i,j-1,grid,m,n);
        int right= dfs(i,j+1,grid,m,n);
        grid[i][j]=curr;
        
        return curr+ max(max(top,down),max(left,right));
          
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int mx=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    int sum=dfs(i,j,grid,m,n);
                    mx=max(sum,mx);
                }
            }
        }
        return mx;
        
    }
};
