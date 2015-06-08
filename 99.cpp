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
    TreeNode*pre, *t1,*t2;
    int f=0;
    void inorder(TreeNode* n){
        if(n==NULL) return;
        inorder(n->left);
        if(pre==NULL){
            
        }
        else if(pre->val>n->val){
            if(f==0){
                t1=pre;
                f=1;
                t2=n;
            }
            else t2=n;
            
            
        }
        pre=n;
        inorder(n->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* t=root;
        while(t->left!=NULL){
            t=t->left;
        }
        t1=t;
        t2=t;
        pre=NULL;
        inorder(root);
        
        swap(t1->val,t2->val);
    }
};
