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
    void sumUtil(TreeNode* root, int sum,vector<int>& res)
    {
        if(!root)
            return ;
        sum=sum*10 + root->val;
        if(!root->left && !root->right)
        {
            res.push_back(sum);
        }
        sumUtil(root->left,sum,res);
        sumUtil(root->right,sum,res);
        
    }
    int sumNumbers(TreeNode* root) {
       
        int sum=0,sm=0;
        vector<int> res;
        sumUtil(root,sum,res);
        for(auto x:res)
        {
            sm+=x;
        }
        return sm;
    }
};
