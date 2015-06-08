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
    int dfs(TreeNode* n,int d){
        if(n==NULL) return d-1;
        if(n->left==NULL and n->right==NULL){
            return d;
        }
        return max(dfs(n->left,d+1),dfs(n->right,d+1));

    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return dfs(root,1);
    }
};
