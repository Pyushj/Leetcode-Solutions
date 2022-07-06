#define Pair pair<int,int>
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,-2));
        queue<Pair> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int height=-1;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int size=q.size();
            height++;
            while(size--)
            {
                Pair temp=q.front();
                q.pop();
                res[temp.first][temp.second]=height;
                for(int i=0;i<4;i++)
                {
                     int r=temp.first + dir[i][0];
                     int c=temp.second + dir[i][1];
                    if(r>=0 && r< m && c>=0 && c<n && res[r][c]==-2)
                    {
                        q.push({r,c});
                        res[r][c]=0;
                    }
                }
            }
        }
        return res;
        
        
        
    }
};






