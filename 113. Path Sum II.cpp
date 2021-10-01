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
    void pathUtil(TreeNode* root, int targetSum,int sum,vector<int> res,vector<vector<int>>& grid)
    {
        if(!root)
            return;
        sum+=root->val;
        res.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(sum==targetSum)
            {
                grid.push_back(res);
            }
        }
        pathUtil(root->left,targetSum,sum,res,grid);
        pathUtil(root->right,targetSum,sum,res,grid);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> grid;
        vector<int> res;
        int sum=0;
        
        pathUtil(root,targetSum,sum,res,grid);
        
        return grid;   
    }
};
