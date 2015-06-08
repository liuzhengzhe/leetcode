/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* dfs(ListNode *&h,int l,int r){
        int mid = l + (r - l) / 2;
        if(l>r) return NULL;
        TreeNode* left=dfs(h,l,mid-1);
        
        TreeNode* p=new TreeNode(h->val);
        
        
        p->left=left;
        h=h->next;
        p->right=dfs(h,mid+1,r);
        return p;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n=0;
        ListNode* h=head;
        while(h!=NULL){
            h=h->next;
            n++;
        }
        return dfs(head,0,n-1);
    }
};
