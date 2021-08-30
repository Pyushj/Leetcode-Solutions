/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0)
        {
            int size=q.size(),mx=INT_MIN;
            while(size--)
            {
                TreeNode *temp=q.front();
                q.pop();
                mx=max(mx,temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};
