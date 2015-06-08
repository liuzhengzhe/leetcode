/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        queue<TreeLinkNode*> q;
        queue<int> num;
        
        q.push(root);
        num.push(0);
        int last=1;
        while(q.empty()==0){
            TreeLinkNode* n=q.front();
            int tmp=num.front();
            q.pop();
            num.pop();
            if(q.empty()==0) last=num.front();
            if(last!=tmp or q.empty()){
                n->next=NULL;
            }
            else{
                n->next=q.front();
            }
            //last=tmp;
            if(n->left!=NULL){
                q.push(n->left);
                num.push(tmp+1);
            }
            if(n->right!=NULL){
                q.push(n->right);
                num.push(tmp+1);
            }
            
        }
        return;                
    }
};
