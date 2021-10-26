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
    int findMax(vector<int>& nums,int l,int r){
        int mx=INT_MIN,idx=-1;
        for(int i=l;i<=r;i++)
        {
            if(nums[i]>mx)
            {
                mx=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    
    TreeNode* util(vector<int>& nums,int l,int r){
        if(l>r)
            return nullptr;
        int mx=findMax(nums,l,r);
        
        TreeNode *root=new TreeNode(nums[mx]);
        root->left=util(nums,l,mx-1);
        root->right=util(nums,mx+1,r);
        
        return root;
    }
    
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int r=nums.size()-1;
        return util(nums,0,r);
    }
};
