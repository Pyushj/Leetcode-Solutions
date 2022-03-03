class Solution {
public:
void dfs(int i,int j,int m,int n,bool& flag,vector<vector<int>>& grid1, vector<vector<int>>& grid2)
{
    if(i<0 ||i >=m || j<0 || j>=n)
        return;
    if(grid2[i][j]==0)
        return;
    if(grid2[i][j]==1 && grid1[i][j]==0)
    {
     flag=true;
        return;
    }
    grid2[i][j]=0;
    grid1[i][j]=0;
    
    dfs(i+1,j,m,n,flag,grid1,grid2);
    dfs(i-1,j,m,n,flag,grid1,grid2);
    dfs(i,j+1,m,n,flag,grid1,grid2);
    dfs(i,j-1,m,n,flag,grid1,grid2);       
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(),n=grid1[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool flag=false;
                if(grid2[i][j]==1)
                {
                    dfs(i,j,m,n,flag,grid1,grid2);
                    if(flag==false)
                        count++;
                }
            }
        }
        return count;
        
    }
};
