#define Pair pair<int,int>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};
        queue<Pair> q;
        q.push({0,0});
        grid[0][0]=1;
        int dist=0;
        while(!q.empty())
        {
            int size=q.size();
            dist++;
            while(size--)
            {
                Pair temp=q.front();
                q.pop();
                if(temp.first==n-1 && temp.second==n-1)
                {
                    return dist;
                }
                for(int k=0;k<8;k++)
                {
                    int r=temp.first + dir[k][0];
                    int c=temp.second + dir[k][1];
                    if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0)
                    {
                        q.push({r,c});
                        grid[r][c]=1;
                    }
                }
            }
        }
        return -1;
        
    }
};
