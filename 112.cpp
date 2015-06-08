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
    int dfs(TreeNode* n,int s,int sum){
        if(n==NULL) return 0;
        if(n->left==NULL and n->right==NULL){
            if(sum==s+n->val) return 1;
            else return 0;
        }
        return dfs(n->left,s+n->val,sum) or dfs(n->right,s+n->val,sum);
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        return dfs(root,0,sum);
    }
};
