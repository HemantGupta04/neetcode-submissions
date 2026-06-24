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
    bool sameTree(TreeNode* p,TreeNode * q){
        if(p==NULL || q==NULL) return (p==q);
        return p->val==q->val && sameTree(p->left,q->left)&&sameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        if(root==NULL)return false;
        if(root->val==subRoot->val){
            if(sameTree(root,subRoot)) return true;
        } 
        bool chk1=isSubtree(root->left,subRoot);
        if(chk1==true) return true;
        bool chk2=isSubtree(root->right,subRoot);
        if(chk2==true) return true;
        return false;

        
    }
};
