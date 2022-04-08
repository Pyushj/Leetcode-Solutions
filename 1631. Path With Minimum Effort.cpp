class Solution {
public:
#define vt vector<int>,vector<vector<int>>,greater<vector<int>>
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        if(n==1 && m==1)
            return 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        
        priority_queue<vt> pq;
        pq.push({INT_MIN,0,0});
        
        while(!pq.empty())
        {
            vector<int> temp=pq.top();
            pq.pop();
            int r=temp[1],c=temp[2];
            
            if(r==n-1 && c==m-1)
                return temp[0];
            if(visited[r][c])
                continue;
            
            visited[r][c]=1;
            for(int k=0;k<4;k++)
            {
                int row=r+dir[k][0];
                int col=c+dir[k][1];
                
                if(row>=0 && row<n && col>=0 && col<m)
                {
                    int diff=abs(heights[row][col]-heights[r][c]);
                    int mx=max(diff,temp[0]);
                    
                    pq.push({mx,row,col});
                }
            }
        }
        return 0;
        
    }
};
