/*
for symmetrical trees, we follow the same approach as for preorder traversal,
we leave the root of the tree, then compare the left subtree and the right subtree,
left subtree's left child node is compared with the right subtree's right child node and vice-versa.
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
    bool isSymmetriccheck(TreeNode *root1,TreeNode*root2){
    if(root1==NULL || root2==NULL) return root1==root2;
    if(root1->data!=root2->data) return false;
    return isSymmetriccheck(root1->left,root2->right) && isSymmetriccheck(root1->right,root2->left);
}
bool isSymmetric(TreeNode* root)
{
    // Write your code here.   
    return root==NULL || isSymmetriccheck(root->left,root->right); 
}