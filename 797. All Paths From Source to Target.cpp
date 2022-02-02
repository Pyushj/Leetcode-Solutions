class Solution {
public:
    void findPath(int src,int dest,vector<int>& currPath,vector<vector<int>>&                                                               graph,vector<vector<int>>& res)
    {
        if(src==dest)
        {
            currPath.push_back(src);
            res.push_back(currPath);
            currPath.pop_back();
            return;
        }
        currPath.push_back(src);
        for(auto x: graph[src])
        {
            findPath(x,dest,currPath,graph,res);
        }
        currPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       
        vector<vector<int>> res;
        int n=graph.size();
        vector<int> currPath;
        findPath(0,n-1,currPath,graph,res);
        return res;
    }
};
