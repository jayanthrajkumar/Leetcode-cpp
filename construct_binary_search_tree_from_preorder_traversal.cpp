/*
Preorder traversal, first node is the root,
we use the concept of range of upperbound, where for each element we maintain the upper bound,
if is lesser than the upper bound, it goes to the left side otherwise to the right side,
*/
#include<bits/stdc++.h>
using namespace std;
class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
TreeNode* construct(vector<int>&preorder,int &i,int bound){
    if(i==preorder.size() || preorder[i]>bound){
        return NULL;
    }
    TreeNode *node=new TreeNode(preorder[i++]);
    node->left=construct(preorder,i,node->val);
    node->right=construct(preorder,i,bound);
    return node;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return construct(preorder,i,INT_MAX);
    }