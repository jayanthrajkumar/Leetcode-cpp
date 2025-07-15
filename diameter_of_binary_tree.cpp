/*
diameter of the binary tree is the longest path between two nodes, it may or may not pass through the node,
we use the same technique as the height of the binary tree
*/
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
    int diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root,diameter);
    return diameter;
    }
int height(TreeNode* root,int &diameter){
    if(root==NULL) return 0;
    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}