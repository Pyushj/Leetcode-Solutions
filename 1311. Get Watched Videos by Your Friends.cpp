#define Pair pair<int,string>
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        int n=friends.size();
        vector<int> adj[n];
        
        for(int i=0;i<friends.size();i++)
        {
            for(auto x:friends[i])
            {
                adj[i].push_back(x);
            }
        }
        vector<int> visited(n,0);
        queue<int> q;
        q.push(id);
        visited[id]=1;
        int k=-1;
        while(!q.empty())
        {
            int size=q.size();
            k++;
            if(k==level)
                break;
            while(size--)
            {
                int src=q.front();
                q.pop();
                for(auto x:adj[src])
                {
                    if(!visited[x])
                    {
                        q.push(x);
                        visited[x]=1;
                    }
                }
            }
        }
        
        unordered_map<string,int> mp;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            for(auto x:watchedVideos[i])
            {
                mp[x]++;
            }
        }
        vector<string> result;
        priority_queue<Pair,vector<Pair>,greater<Pair> > pq;
        for(auto x: mp)
        {
            pq.push({x.second,x.first});
        }
        while(!pq.empty())
        {
            Pair curr=pq.top();
            pq.pop();
            result.push_back(curr.second);
        }
        return result;
        
    }
};
