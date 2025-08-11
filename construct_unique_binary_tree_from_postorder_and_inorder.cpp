/*
Very similar to constructing an unique binary tree from preorder and inorder traversal,
In postorder traversal, the last element is the root, then we find the node in the inorder traversal, the elements to the left of root are the left subtree and the elements to the right are the elements of the right subtree,
seperating the elements based on the root must be done carefully,
apart from that , map is used to store the indices of the inorder traversal elements as the list is trimmmed which may affect the elements position.
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
TreeNode* buildTree(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,map<int,int>&inorderindex){
    if(instart>inend || poststart>postend) return NULL;
    TreeNode* node=new TreeNode(postorder[postend]);
    int inroot=inorderindex[node->val];
    int elementsleft=inroot-instart;
    node->left=buildTree(inorder,instart,inroot-1,postorder,poststart,poststart+elementsleft-1,inorderindex);
    node->right=buildTree(inorder,inroot+1,inend,postorder,poststart+elementsleft,postend-1,inorderindex);
    return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        map<int,int>inorderindex;
        for(int i=0;i<inorder.size();i++){
            inorderindex[inorder[i]]=i;
        }
        int n=inorder.size();
        return buildTree(inorder,0,n-1,postorder,0,n-1,inorderindex);
    }
