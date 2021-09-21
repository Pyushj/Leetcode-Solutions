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
    bool isOne(TreeNode* root)
    {
        if(!root)
            return false;
        if(root->val==1)
            return true;
        return isOne(root->left) || isOne(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root || isOne(root)==false)
            return nullptr;
        if(root->left)
        {
            if(isOne(root->left))
                root->left=pruneTree(root->left);
            else
                root->left=nullptr;
        }
        if(root->right)
        {
            if(isOne(root->right))
                root->right=pruneTree(root->right);
            else
                root->right=nullptr;
        }
        return root;      
    }
};
