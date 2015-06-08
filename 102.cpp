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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL) return ret;
        queue<TreeNode*> q;
        queue<int> num;
        
        q.push(root);
        num.push(0);
        int last=-1;
        while(q.empty()==0){
            TreeNode* n=q.front();
            int tmp=num.front();
            q.pop();
            num.pop();
            if(last!=tmp){
                vector<int> v;
                ret.push_back(v);
                ret[tmp].push_back(n->val);
            }
            else{
                ret[tmp].push_back(n->val);
            }
            last=tmp;
            if(n->left!=NULL){
                q.push(n->left);
                num.push(tmp+1);
            }
            if(n->right!=NULL){
                q.push(n->right);
                num.push(tmp+1);
            }
            
        }
        return ret;
        
    }
};
