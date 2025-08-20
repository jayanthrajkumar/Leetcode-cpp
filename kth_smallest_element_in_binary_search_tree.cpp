/*
Since the binary search tree is sorted, by using the inorder traversal we can easily find the kth smallest element,
and by using the morris traversal for the inorder traversal, it becomes even more easy as the space conmplexity becomes O(1),
we use a counter variable to keep track of the root occuring,
if the count exaclty matches k, we store the node's answer , we return the answer.
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
int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=-1;
    TreeNode*curr=root;
    while(curr){
        if(!curr->left){
            count++;
            if(count==k){
                ans=curr->val;
            }
            curr=curr->right;
        }
        else{
            TreeNode*prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(!prev->right){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                count++;
                if(count==k){
                    ans=curr->val;
                }
                curr=curr->right;
            }

        }
    }
    return ans;
    }