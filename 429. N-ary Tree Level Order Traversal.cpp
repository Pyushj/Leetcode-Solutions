/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> arr;
            while(size--)
            {
                Node* temp=q.front();
                q.pop();
                arr.push_back(temp->val);
                for(auto x: temp->children)
                {
                    if(x)
                        q.push(x);
                }
            }
            res.push_back(arr);
        }
        return res;
    }
};
