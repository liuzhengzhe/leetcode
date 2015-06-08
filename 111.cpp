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
    int dfs(TreeNode* n){
        if(n==NULL) return INT32_MAX;
        if(n->left==NULL and n->right==NULL) return 1;
        return min(dfs(n->left),dfs(n->right))+1;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return dfs(root);
    }
};
