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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int count=0;
        queue<TreeNode*> q;
        q.push(root);
        bool isLast=false;
        while(!q.empty())
        {
            if(isLast)
                break;
            int sz=q.size();
            while(sz--)
            {
                TreeNode* temp=q.front();
                count++;
                q.pop();
                if((!temp->left || !temp->right) && isLast==false)
                    isLast=true;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        count+=q.size();
        return count;
        
        
    }
};
