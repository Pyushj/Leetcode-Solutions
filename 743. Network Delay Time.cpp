#define Pair pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<Pair> adj[n+1];
        for(auto x: times)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            adj[u].push_back({v,wt});
        }
        vector<int> time(n+1,INT_MAX);
        vector<int> visited(n+1,0);
        queue<int> q;
        q.push(k);
        visited[k]=1;
        time[k]=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int temp=q.front();
                q.pop();
                int mx=0;
                for(auto x: adj[temp])
                {
                  
                    if(time[x.first]> time[temp] + x.second)
                    {
                        time[x.first]=time[temp] + x.second;
                        q.push(x.first);
                        visited[x.first]=1; 
                    }
                    else
                        continue;
                   
                }
            }
        }
        int tm=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==0)
                return -1;
            tm=max(tm,time[i]);
        }
        return tm; 
    }
};
