/*
We check whether the given node lies between the range or not,
for the root we int min and int max to be checked, for the left node, we go with root's left range and root's value,
for the right node, we check with the root's value and root's right range.
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
bool isValidBST(TreeNode* root,long low,long high){
    if(root==NULL) return true;
    if(!(root->val<high && root->val>low)){
        return false;
    }
    return isValidBST(root->left,low,root->val) && isValidBST(root->right,root->val,high);
}
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }