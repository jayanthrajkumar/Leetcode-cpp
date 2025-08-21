/*
we check wether the node lies between the two nodes,
if it is greater than both the nodes, we move to the node's left,
if it is lesser, we move to the node's right,
if both os these conditions fail, we say that the node is the lowest common ancestor.
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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        while(root){
        if(root->val>p->val && root->val>q->val){
            root=root->left;
        }
        else if(root->val<p->val && root->val<q->val){
            root=root->right;
        }
        else return root;
    }
    return NULL;
    }