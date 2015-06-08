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
    bool dfs(TreeNode* p,TreeNode *q){
        if(p==NULL and q==NULL){
            return 1;
        }
        if(p==NULL and q!=NULL){
            return 0;
        }
        if(p!=NULL and q==NULL){
            return 0;
        }
        if(p!=NULL and q!=NULL){
            if(p->val!=q->val) return 0;
            else return (dfs(p->left,q->left) and dfs(p->right,q->right));
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};
