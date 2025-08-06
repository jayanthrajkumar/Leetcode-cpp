/*
problem is to find the lowest common ancestor between two nodes, somtimes the answer maybe even one of the nodes itself,
we follow the inorder traversal of  the bianry tree,
we start from the root ans check whether it is any of the nodes or if the root value is null,if it is we return the root,otherwise we move on to the left,
if the left subnode is null, the right node's  is passed on to the parent node, otherwise the left node,
if both the left and right subnode are not null, return the root value
*/
#include<bits/stdc++.h>
using namespace std;
class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }