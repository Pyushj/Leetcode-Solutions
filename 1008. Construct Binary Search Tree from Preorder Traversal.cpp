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
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]==key)
                return mid;
            else if(arr[mid] < key)
                start=mid+1;
            else
                end=mid-1;
        }
        return 0;
    }
    TreeNode* construct(vector<int>& preorder,vector<int>& inorder,int& preItr,int start,int end)
    {
        if(start > end)
            return nullptr;
        int mid=find(inorder,start,end,preorder[preItr]);
        TreeNode *root=new TreeNode(preorder[preItr]);
        preItr++;
        root->left=construct(preorder,inorder,preItr,start,mid-1);
        root->right=construct(preorder,inorder,preItr,mid+1,end);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int preItr=0;
        return construct(preorder,inorder,preItr,0,inorder.size()-1);
    }
};
