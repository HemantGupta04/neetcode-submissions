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
    int f(TreeNode*root,int &ans){
        if(root==NULL) return 0;
        int l=f(root->left,ans);
        if(l==-1) return -1;
        int r=f(root->right,ans);
        if(r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return 1+max(l,r);

    }
    bool isBalanced(TreeNode* root) {
        int ans=0;
        if(root==NULL) return true;
        int a=f(root,ans);
        return (a!=-1);
        
    }
};
