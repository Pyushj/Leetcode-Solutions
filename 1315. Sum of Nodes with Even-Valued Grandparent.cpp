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
  store the parent of every node create a function and pass the current node and the parent 
  for every node check the value of its patents's ---> parent 
  if even add it to the sum otherwise  recur for the left and right subtree;

*/
class Solution {
public:
void findSum(TreeNode* root, TreeNode *parent,int& sum,unordered_map<TreeNode*,int>& mp)
{
    if(!root)
        return;
    mp[root]=parent->val;
    if(mp[parent]%2==0)
        sum+=root->val;
    
    findSum(root->left,root,sum,mp);
    findSum(root->right,root,sum,mp);
    
}
    
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;
        
        unordered_map<TreeNode*,int> mp;
        TreeNode *x=new TreeNode(-1);
        mp[x]=-1;
        int sum=0;
        findSum(root,x,sum,mp);
        return sum;
    }
};
