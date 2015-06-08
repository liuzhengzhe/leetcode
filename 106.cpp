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
    unordered_map<int,int>  map;
    TreeNode* dfs(vector<int>& inorder,int l1,int r1, vector<int>& postorder,int l2,int r2){
        if(l1>r1 or l2>r2) return NULL;
        TreeNode* n=new TreeNode(postorder[r2]);
        int cen=map[n->val];
        n->left=dfs(inorder,l1,cen-1,postorder,l2,l2+cen-l1-1);
        n->right=dfs(inorder,cen+1,r1,postorder,l2+cen-l1,r2-1);
        return n;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        
        
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return dfs(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};
