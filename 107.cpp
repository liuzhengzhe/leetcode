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
    vector<vector<int>> ret;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return ret;
        queue<TreeNode*> q;
        queue<int> l;
        q.push(root);
        l.push(0);
        int last=-1;
        while(q.empty()==0){
            TreeNode* n=q.front();
            int num=n->val;
            int lv=l.front();
            q.pop();
            l.pop();
            if(lv!=last){
                vector<int> v;
                ret.insert(ret.begin(),v);
                ret[0].push_back(num);
            }
            else{
                ret[0].push_back(num);
            }
            last=lv;
            if(n->left){
                q.push(n->left);
                l.push(lv+1);
            }
            if(n->right){
                q.push(n->right);
                l.push(lv+1);
            }
        }
        return ret;
    }
};
