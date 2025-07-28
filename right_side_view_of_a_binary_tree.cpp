/*
preorder order traversal of a binary tree in the order root right left gives the right side of the tree whereas the normal preporder would give the left side view of the tree.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
struct TreeNode {
  int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void recursive_pre_order(TreeNode* root,int level,vector<int>&ans){
    if(root==NULL) return;
    if(ans.size()==level) ans.push_back(root->val);
    recursive_pre_order(root->right,level+1,ans);
    recursive_pre_order(root->left,level+1,ans);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        recursive_pre_order(root,0,ans);
        return ans;
    }
};