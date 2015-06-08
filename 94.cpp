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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* n=root;
        TreeNode* t;
        while(s.empty()==0 || n!=NULL){
            while(n!=NULL){
                s.push(n);
                n=n->left;
            }
            n=s.top();
            s.pop();
            ret.push_back(n->val);
            
            n=n->right;
        }
        return ret;        
    }
};