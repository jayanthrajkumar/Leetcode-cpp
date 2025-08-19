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
TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val){
            root=val<root->val?root->left:root->right;
        }
        return root;
    }