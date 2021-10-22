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
    int sumTree(TreeNode *root,unordered_map<int,int>& mp,int& count)
    {
        if(!root)
        {
            count++;
            return 0;
        }
        int left=sumTree(root->left,mp,count);
        mp[left]++;
       
        int right=sumTree(root->right,mp,count);
        mp[right]++;
        return root->val + left + right;
    }
    
    
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        int count=0;
        int sum=sumTree(root,mp,count);
        mp[sum]++;
        mp[0]-=count;
        int freq=0;
        for(auto x: mp)
        {
            freq=max(freq,x.second);
        }
        vector<int> res;
        for(auto x: mp)
        {
            if(x.second==freq)
                res.push_back(x.first);
        }
        return res;
    }
};
