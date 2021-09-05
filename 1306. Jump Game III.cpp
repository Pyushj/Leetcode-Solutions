class Solution {
public:
    /*
    Using BFS push the current start into  the queue
    now check for all the indices reachable from the the current start and push them into the queue 
    perform the same operation on all the elements of the queue
    if any index has a value 0 return true
    if after all the operation the queue becomes empty simply return false
    */
  bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        bool visited[n];
        memset(visited,0,sizeof(visited));
        queue<int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty())
        {
            int idx=q.front();
            q.pop();
            int val=arr[idx];
            if(val==0)
                return true;
            if(idx+val>0 && idx+val<n && !visited[idx+val])
            {
                q.push(idx+val);
                visited[idx+val]=true;
            }
                
            if(idx-val >=0 && idx-val<n && !visited[idx-val])
            {
                q.push(idx-val);
                visited[idx-val]=true;
            }
                
                    
        }
        return false;
        
        
    }
};
