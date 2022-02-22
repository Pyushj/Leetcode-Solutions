class Solution {
public:
    void dfs(int i,int j,int m,int n,int& count,vector<vector<int>>& grid)
    {
        if(i<0 ||i>=m || j<0 || j>=n)
            return;
        if(grid[i][j]==0)
            return;
        grid[i][j]=0;
        count++;
        dfs(i+1,j,m,n,count,grid);
        dfs(i-1,j,m,n,count,grid);
        dfs(i,j+1,m,n,count,grid);
        dfs(i,j-1,m,n,count,grid);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int mx=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int count=0;
                    dfs(i,j,m,n,count,grid);
                    mx=max(count,mx);
                }
            }
        }
        return mx;
    }
};
