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
    void preorder(TreeNode* root,long long min,long long max,bool& valid)
    {
        if(!root || valid==false)
            return;
        if(root->val < min || root->val >max)
            valid=false;
        long long int value=(long long int) (root->val);
        preorder(root->left,min,value-1,valid);
        preorder(root->right,value+1,max,valid);
    }
    bool isValidBST(TreeNode* root) {
        long long min=INT_MIN;
        long long max=INT_MAX;
        bool valid=true;
        preorder(root,min,max,valid);
        return  valid;
    }
};
