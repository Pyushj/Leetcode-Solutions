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
    bool isSame(TreeNode *a,TreeNode *b)
    {
        if(!a && !b)
            return true;
        if(!a || !b)
            return false;
        if(a->val!=b->val)
            return false;
        return isSame(a->left,b->left) && isSame(a->right,b->right);
    }
     void preorder(TreeNode * root,TreeNode *subRoot,bool& found)
     {
         if(!root || found==true)
             return;
         if(root->val==subRoot->val)
             found=isSame(root,subRoot);
         preorder(root->left,subRoot,found);
         preorder(root->right,subRoot,found);    
     }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       bool found=false;
        preorder(root,subRoot,found);
        return found;
    }
};
