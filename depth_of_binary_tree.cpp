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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return 1+max(lh,rh);
    }