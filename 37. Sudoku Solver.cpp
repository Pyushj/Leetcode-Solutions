class Solution {
public:
    bool solved=false;
    bool isPossible(int i,int j, char option,vector<vector<char>>& board)
    {
        for(int x=0;x<9;x++)
        {
            if(board[i][x]==option)
                return false;
        }
        for(int y=0;y<9;y++)
        {
            if(board[y][j]==option)
                return false;
        }
        int subI=i/3 *3;
        int subJ=j/3 *3;
        
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                if(board[subI+x][subJ+y]==option)
                    return false;
            }
        }
        return true; 
    }
    void solve(int i,int j,vector<vector<char>>& board,vector<vector<char>>& copy)
    {
        if(i==9)
        {
            for(int x=0;x<9;x++)
            {
                for(int y=0;y<9;y++)
                {
                    copy[x][y]=board[x][y];
                }
            }
            solved=true;
            return;
        }
        if(solved)
            return;
        int nextI,nextJ;
        if(j==8)
        {
            nextI=i+1;
            nextJ=0;
        }
        else
        {
            nextI=i;
            nextJ=j+1;
        }
        if(board[i][j]!='.')
        {
            solve(nextI,nextJ,board,copy);
            return;
        }
        
        for(char op='1';op<='9';op++)
        {
            if(isPossible(i,j,op,board))
            {
                board[i][j]=(char)op;
                solve(nextI,nextJ,board,copy);
                board[i][j]='.';
            }
        }
        return;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<char>> copy(9,vector<char>(9,'*'));
        solve(0,0,board,copy);
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                board[i][j]=copy[i][j];
            }
        }
    }
};
