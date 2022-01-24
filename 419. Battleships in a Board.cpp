class Solution {
public:
    void findCount(int x,int y,vector<vector<char>>& board)
    {
        int n=board.size(),m=board[0].size();
        int i=x-1,j=y;
        while(i>=0 && board[i][j]=='X')
        {
            board[i][j]='.';
            i--;
        }
            i=x+1,j=y;
         while(i<n && board[i][j]=='X')
        {
            board[i][j]='.';
            i++;
        }
        i=x,j=y-1;
        while(j>=0 && board[i][j]=='X')
        {
            board[i][j]='.';
            j--;
        }
        i=x,j=y+1;
        while(j<m && board[i][j]=='X')
        {
            board[i][j]='.';
            j++;
        }
        board[x][y]='.';       
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                   if(board[i][j]=='X')
                   {
                        findCount(i,j,board);
                        count++;
                   }

            }
        }
        return count;
        
    }
};
