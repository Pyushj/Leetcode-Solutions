class Solution {
public:
    void floodFill(int i,int j,int m,int n,vector<vector<char>>& board)
    {
        if(i<0 || i>=m || j<0 ||j>=n)
            return;
        if(board[i][j]!='$')
            return;
        
        board[i][j]='O';
        floodFill(i+1,j,m,n,board);
        floodFill(i-1,j,m,n,board);
        floodFill(i,j+1,m,n,board);
        floodFill(i,j-1,m,n,board);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='$';
            }
        }
        //top
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='$')
            floodFill(0,j,m,n,board); 
        }
        //bottom
        for(int j=0;j<n;j++)
        {
            if(board[m-1][j]=='$')
            floodFill(m-1,j,m,n,board); 
        }
        //left
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='$')
                floodFill(i,0,m,n,board);
        }
        //right
        for(int i=0;i<m;i++)
        {
            if(board[i][n-1]=='$')
                floodFill(i,n-1,m,n,board);
        }
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='$')
                    board[i][j]='X';
            }
        }
        
        
        
        
        
        
    }
};
