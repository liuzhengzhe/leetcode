#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int,int> map;
    TreeNode* dfs(int h,int r,vector<int>& preorder, vector<int>& inorder){
        if(h>=preorder.size()-1){
            return NULL;
        }
        if(h>=r-1){
            return NULL;
        }
        int cen=map[preorder[h]];
        TreeNode* n=new TreeNode(preorder[h]);
        TreeNode* l=dfs(h+1,cen-1,preorder,inorder);
        TreeNode* ri=dfs(cen+1,r,preorder,inorder);
        n->left=l;
        n->right=ri;
        return n;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return dfs(0,inorder.size(),preorder,inorder);
        
    }
};
int main()
{
    Solution s;
    vector<int> a;
    a.push_back(4);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    s.buildTree(a, b);
    return 0;
}