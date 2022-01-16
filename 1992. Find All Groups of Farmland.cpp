class Solution {
public:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int r,int c,vector<vector<int>>& land,vector<vector<int>>& visited,int& row,int& col)
    {
        visited[r][c]=1;
        if(r>row )
            row=r;
        if(c>col)
            col=c;
        for(int i=0;i<4;i++)
        {
            int x= dir[i][0] + r;
            int y= dir[i][1] + c;
            if( (x>=0 && x< land.size()) &&(y>=0 && y< land[0].size()) && land[x][y]==1 &&                                                                                          !visited[x][y] )
                dfs(x,y,land,visited,row,col);
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> res;
        vector<vector<int>> visited(305,vector<int> (305,0));
        
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[i].size();j++)
            {
                if(land[i][j]==1 && !visited[i][j])
                {
                    int row=i,col=j;
                    dfs(i,j,land,visited,row,col);
                    res.push_back({i,j,row,col});
                    
                }
            }
        }
        return res;
        
    }
};
