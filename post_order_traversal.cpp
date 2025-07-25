#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
void postorder(TreeNode* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
    postorder(root,ans);
    return ans;
    }
};