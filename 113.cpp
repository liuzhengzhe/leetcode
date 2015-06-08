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
    vector<vector<int> > ret;
    void dfs(TreeNode* n,int s,int sum,vector<int> list){
        if(n==NULL) return;
        if(n->left==NULL and n->right==NULL){
            if(s+n->val==sum){
                list.push_back(n->val);
                ret.push_back(list);
                list.pop_back();
                return;
            }
            else return;
        }
        list.push_back(n->val);
        dfs(n->left,s+n->val,sum,list);
        dfs(n->right,s+n->val,sum,list);
        list.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL) return ret;
        vector<int> list;
        dfs(root,0,sum,list);
        return ret;
    }
};
