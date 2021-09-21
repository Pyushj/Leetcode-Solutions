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
    void preorder(TreeNode* root,int mx,int& count)
    {
        if(!root)
            return;
        if(root->val>=mx)
            count++;
        mx=max(root->val,mx);
        preorder(root->left,mx,count);
        preorder(root->right,mx,count);    
    }
    
    int goodNodes(TreeNode* root) {
      
        int count=0,mx=root->val;
        preorder(root,mx,count);
        return count;
    }
};
