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
    TreeNode* dfs(vector<int>& nums,int l,int r){
        if(l>r){
            return NULL;
        }
        TreeNode* n=new TreeNode(nums[(l+r)/2]);
        n->left=dfs(nums,l,(l+r)/2-1);
        n->right=dfs(nums,(l+r)/2+1,r);
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //if(nums.size()==0) return NULL;
        return dfs(nums,0,nums.size()-1);
    }
};
