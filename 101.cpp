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
    bool dfs(TreeNode* n,TreeNode* m){
        if(n==NULL and m==NULL){
            return 1;
        }
        if(n==NULL and m!=NULL){
            return 0;
        }  
        if(n!=NULL and m==NULL){
            return 0;
        }
        if(n->val!=m->val){
            return 0;
        }
        else{
            return (dfs(n->left,m->right) and dfs(n->right,m->left));
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        return dfs(root->left,root->right);
    }
};
