class Solution {
public:
    bool canDiffuse(vector<int> a,vector<int> b)
    {
        long long int x=(b[0]-a[0]);
        long long int y=(b[1]-a[1]);
        long long int r=a[2];
        long long int res=(x*x)+(y*y) -(r*r);
        if(res<=0)
            return true;
        else
            return false;
    }
    
    void dfs(int src,vector<int> adj[],int& count,vector<int>& visited)
    {
        if(visited[src])
            return;
        visited[src]=1;
        count++;
        for(auto x:adj[src])
        {
            dfs(x,adj,count,visited);
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(canDiffuse(bombs[i],bombs[j]))
                    adj[i].push_back(j);
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            vector<int> visited(n,0);
            dfs(i,adj,count,visited);
            //cout<<count<<endl;
            mx=max(mx,count);
        }
        return mx;  
    }
};
