/*
A binary tre is said to be balanced binary tree if the absolute height between the right subtree and the left subtree is less or equal to one for any given node,
we use the method od=f returning the height of the tree,
where in every case we see whether the absolute height concept and return -1,if it is to the contrary.
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
    int height_of_tree(TreeNode* root){
    if(root==NULL) return 0;
    int lft=height_of_tree(root->left);
    if(lft==-1) return -1;
    int rft=height_of_tree(root->right);
    if(rft==-1) return -1;
    if(abs(lft-rft)>1) return -1;
    return max(lft,rft)+1;
}
    bool isBalanced(TreeNode* root) {
        return height_of_tree(root)!=-1;
    }
