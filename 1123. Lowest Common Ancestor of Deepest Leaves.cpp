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
 
/* 
 Pick the leftMost leaf node and rightMost leaf  node 
 and then find the lca of leftMost and rightMost nodes
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root,int a,int b)
    {
        if(!root)
            return nullptr;
        if(root->val==a || root->val==b)
            return root;
        TreeNode* left=lca(root->left,a,b);
        TreeNode* right=lca(root->right,a,b);
        if(left && right)
            return root;
        if(left)
            return left;
        if(right)
            return right;
        
        return nullptr;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if(!root)
            return root;
        
        TreeNode  *leftMost=nullptr,*rightMost=nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            leftMost=nullptr;rightMost=nullptr;
            while(size--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(!temp->left && !temp->right)
                {
                    if(leftMost==nullptr)
                        leftMost=temp;
                    rightMost=temp;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        if(leftMost==rightMost)
            return leftMost;
        
        return lca(root,leftMost->val,rightMost->val);
    }
};
