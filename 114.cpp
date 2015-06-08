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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* head=new TreeNode(0);
        while(s.empty()==0){
            TreeNode* n=s.top();
            s.pop();
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);
            head->left=NULL;
            head->right=n;
            head=n;
        }
        return;
    }
};
