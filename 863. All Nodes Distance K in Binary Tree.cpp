/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParent(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,TreeNode*>& mp)
    {
        if(!root)
            return;
        mp[root]=parent;
        findParent(root->left,root,mp);
        findParent(root->right,root,mp);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        vector<int> res;
        unordered_set<int> st;
        findParent(root,nullptr,mp);
        int lev=-1;
        queue<TreeNode*> q;
        q.push(target);
        st.insert(target->val);
        while(!q.empty())
        {
            lev++;
            if(lev==k)
                break;
            int sz=q.size();
            while(sz--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && st.find(temp->left->val)==st.end())
                {
                    q.push(temp->left);
                    st.insert(temp->left->val);
                }
                if(temp->right && st.find(temp->right->val)==st.end())
                {
                    q.push(temp->right);
                    st.insert(temp->right->val);
                }
                if(mp[temp] && st.find(mp[temp]->val)==st.end())
                {
                    q.push(mp[temp]);
                    st.insert(mp[temp]->val);
                }
                    
            }
        }
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
        
        
        
    }
};
