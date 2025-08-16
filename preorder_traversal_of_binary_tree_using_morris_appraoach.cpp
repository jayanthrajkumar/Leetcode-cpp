/*
Morris approach is same for preorder as well but the root must be printed before traversing to the left
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
vector<int> preorderTraversal(TreeNode* root) {
vector<int>preorder;
    TreeNode *curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                preorder.push_back(curr->val);
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preorder;
}