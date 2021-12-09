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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            level++;
            if(level==depth-1)
                break;
            int len=q.size();
            while(len--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            TreeNode* prevLeft=temp->left;
            TreeNode* newLeft = new TreeNode(val);
            temp->left=newLeft;
            newLeft->left=prevLeft;
            
            TreeNode* prevRight=temp->right;
            TreeNode* newRight = new TreeNode(val);
            temp->right=newRight;
            newRight->right=prevRight; 
        }
        return root;
        
    }
};
