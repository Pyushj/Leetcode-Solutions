class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
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
                res[row][col]=dist;
                
                for(int i=0;i<4;i++)
                {
                    int r=row+dir[i][0];
                    int c=col+dir[i][1];
                if((r>=0 && r<m) && (c>=0 && c<n) && res[r][c]==-1 && mat[r][c]==1)
                    {
                     mat[r][c]=0;    
                     q.push({r,c});
                    }
                } 
            }
        }
        return res;
        
    }
};
