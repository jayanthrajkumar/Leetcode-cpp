/*
Morris approach eleminates the space taken for traversal,
In this appraoch, the rightmost node of each root node is connected by a thread to the root node, and after traversing the thread is removed,
so that the recursive stack space is removed,
Three cases exist to be taken care, is teh root node has no left node, then we simply point the current pointer to the root's right,
next if left node, exists, we traverse to the right most node of the left node and create a thread, here if it null, we point it to the root node of the subtree, 
otherwise we add teh node to the answer and remove the connection
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};