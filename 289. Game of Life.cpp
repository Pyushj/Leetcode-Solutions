class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        int m=board.size(),n=board[0].size();
        vector<vector<int>> res(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                for(int k=0;k<8;k++)
                {
                    int r=i+dir[k][0];
                    int c=j+dir[k][1];
                    if(r>=0 && r<m && c>=0 && c<n)
                    {
                        if(board[r][c]==1)
                        count++;
                    }
                }
                    if(board[i][j]==1)
                    {
                       if(count<2)
                           res[i][j]=0;
                        else if(count==2 || count==3)
                            res[i][j]=1;
                        else if(count>3)
                            res[i][j]=0;
                    }
                    else
                    {
                        if(count==3)
                            res[i][j]=1;
                        else
                            res[i][j]=0;
                    }
                }
            }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]=res[i][j];
            }
        }
    }
};
