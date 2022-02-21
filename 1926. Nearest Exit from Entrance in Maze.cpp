class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int dist=-1;
        
        while(!q.empty())
        {
            dist++;
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> temp=q.front();
                q.pop();
                int row=temp.first;
                int col=temp.second;
                
            if(row==0 || row==m-1 || col==0 || col== n-1)
            {
                if(row ==entrance[0] && col ==entrance[1])
                    ;
                else
                    return dist;
            }
                for(int i=0;i<4;i++)
                {
                    int r=row+dir[i][0];
                    int c=col+dir[i][1];
                    if((r>=0 && r<m)&& (c>=0 && c<n) && maze[r][c]=='.')
                    {
                        q.push({r,c});
                        maze[r][c]='+';
                    }
                }
            }
        }
        return -1;
    }
};
