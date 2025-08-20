/*
There are tow ways to delete a node, after deleting the node, we either attach the right child node to the last rightmost child on the left subtree
or we attach the left child node to the last leftmost child on the right subtree,
one more condition is we check wether the root itself is the key or the root is null,
Moreover first we need to traverse to the key inorder to start deleting.
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
TreeNode* find_last_child_on_right(TreeNode * root){
    while(root->left){
        root=root->left;
    }
    return root;
}
TreeNode* helper(TreeNode* root){
    if(!root->left) return root->right;
    else if (!root->right) return root->left;
    TreeNode* leftchild=root->left;
    TreeNode* lastchildonright=find_last_child_on_right(root->right);
    lastchildonright->left=leftchild;
    return root->right;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            return helper(root);
        }
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }