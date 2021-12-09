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
    static bool compare(string x,string y)
    {
        return x.compare(y)<1;
    }
    void preorder(TreeNode* root,vector<string>& res,string prev)
    {
        if(!root)
            return;
        
        char ch=(char)(root->val+'a');
        string curr=ch+prev;
        preorder(root->left,res,curr);
        preorder(root->right,res,curr);
        
        if(!root->left && !root->right)
            res.push_back(curr);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<string> res;
        preorder(root,res,"");
        string min=res[0];
        for(int i=0;i<res.size();i++)
        {
            if(min.compare(res[i])>0)
                min=res[i];
        }
        return min;
    }
};
