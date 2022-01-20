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
    int find(vector<int>& arr,int start,int end,int key)
    {
        for(int i=start;i<=end;i++)
        {
            if(arr[i]==key)
                return i;
        }
        return 0;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int& preItr,int start,int end){
        if(start>end)
            return nullptr;
        int mid=find(inorder,start,end,preorder[preItr]);
        TreeNode *root=new TreeNode(preorder[preItr]);
        preItr++;
        root->left=build(preorder,inorder,preItr,start,mid-1);
        root->right=build(preorder,inorder,preItr,mid+1,end);
        
        return root;   
        }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preItr=0;
        return build(preorder,inorder,preItr,0,inorder.size()-1);
        
    }
};
