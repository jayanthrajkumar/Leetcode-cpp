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
class Solution {
public:
    bool checkTree(TreeNode* root) {
        int node=0;
        if(root->left) node+=root->left->data;
        if(root->right) node+=root->right->data;
        return root->data==node;
    }
};