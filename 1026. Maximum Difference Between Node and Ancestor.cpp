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
    void preorder(TreeNode* root,int mx,int mn,int& diff)
    {
        if(!root)
            return;
        mx=max(root->val,mx);
        mn=min(root->val,mn);
        int currDiff=abs(mx-mn);
        diff=max(diff,currDiff);
        preorder(root->left,mx,mn,diff);
        preorder(root->right,mx,mn,diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int diff=INT_MIN;
        preorder(root,root->val,root->val,diff);
        return diff;
    }
};
