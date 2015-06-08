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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL) return ret;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        stack<int> lvl1;
        stack<int> lvl2;
        s1.push(root);
        lvl1.push(0);
        int last=-1;
        int f=1;
        while(s1.empty()==0 or s2.empty()==0){
            if(f==1){
                TreeNode* n=s1.top();
                s1.pop();
                int now=lvl1.top();
                lvl1.pop();
                if(now!=last){
                    vector<int> v;
                    ret.push_back(v);
                    ret[now].push_back(n->val);
                }
                else{
                    ret[now].push_back(n->val);
                }
                last=now;
                if(n->left!=NULL){
                    s2.push(n->left);
                    lvl2.push(now+1);
                    
                }
                
                if(n->right!=NULL){
                    s2.push(n->right);
                    lvl2.push(now+1);                    
                }
                if(s1.empty()){
                    f=2;
                    //continue;
                }
                
            }
            else if(f==2){
                TreeNode* n=s2.top();
                s2.pop();
                int now=lvl2.top();
                lvl2.pop();
                if(now!=last){
                    vector<int> v;
                    ret.push_back(v);
                    ret[now].push_back(n->val);
                }
                else{
                    ret[now].push_back(n->val);
                }
                last=now;
                if(n->right!=NULL){
                    s1.push(n->right);
                    lvl1.push(now+1);                    
                }
                if(n->left!=NULL){
                    s1.push(n->left);
                    lvl1.push(now+1);
                    
                }
                
                if(s2.empty()){
                    f=1;
                    //continue;
                }
                
            }
        }
        return ret;
        
    }
};
