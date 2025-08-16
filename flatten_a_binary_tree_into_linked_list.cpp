/*
Flatten a binary tree into a linked list such that the preorder is stored in a binary tree(right skewed tree),
we use the morris approach, where ww make the rightmost node of the left subtree point to the root's right and disconnect the root's right from the root,
then attach the left node of the root to the right and make the node's left node as null,
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode *prev=curr->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};