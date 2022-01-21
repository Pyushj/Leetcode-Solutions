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
    bool isPalindrome(vector<int>& arr)
    {
        int odd=0;
        for(int i=1;i<10;i++)
        {
            if(arr[i]&1)
                odd++;
            if(odd>1)
                return false;
        }
        return true;
    }
    void preorder(TreeNode* root,vector<int>& hash,int& count)
    {
        if(!root)
            return;
        hash[root->val]++;
        if(!root->left && !root->right)
        {
            if(isPalindrome(hash))
                count++;
        }
        preorder(root->left,hash,count);
        preorder(root->right,hash,count);
        hash[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash(10,0);
        int count=0;
        
        preorder(root,hash,count);
        return count;
    }
};
