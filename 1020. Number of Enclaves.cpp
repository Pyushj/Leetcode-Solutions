class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid)
    {
        if(i<0 || i>=m || j<0 || j>=n)
            return;
        if(grid[i][j]==0)
            return;
        grid[i][j]=0;
        dfs(i+1,j,m,n,grid);
        dfs(i-1,j,m,n,grid);
        dfs(i,j+1,m,n,grid);
        dfs(i,j-1,m,n,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        // top
        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==1)
                dfs(0,j,m,n,grid);
        }
        //bottom
         for(int j=0;j<n;j++)
         {
            if(grid[m-1][j]==1)
                dfs(m-1,j,m,n,grid);
         }
        // left
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
                dfs(i,0,m,n,grid);
        }
        //right
        for(int i=0;i<m;i++)
        {
            if(grid[i][n-1]==1)
                dfs(i,n-1,m,n,grid);
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;   
    }
};
