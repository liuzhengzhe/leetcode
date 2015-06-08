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
    int h(TreeNode* t){
        if(t==NULL) return 0;
        return max(h(t->left),h(t->right))+1;
    }
    bool dfs(TreeNode* t){
        if(t==NULL) return 1;
        return dfs(t->left) and dfs(t->right)  and abs(h(t->left)-h(t->right))<2;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return 1;
        return dfs(root);
    }
};
