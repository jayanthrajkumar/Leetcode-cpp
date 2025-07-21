/* 
boundary traversal returns the anticlockwise boundary traversal of the binary tree, first we traverse the left boundary excluding the leaf nodes,
then the leaf nodes and then we go the right boundary of the binary tree,
for the left boundary, we check if the the current node is a not a leaf node, then we add it to the answer, then if the curr has a left node, the curr is made to point the left subnode otherwise the right subnode,
for the right boundary, we follow the same the curr is first checked whether it has right subnode before assigning it, the answer has to be reversed before it is being added to the final answer, so we use a temp vector,
for the leaf node function,we follow the inorder traversal, we traverse and if we get a leaf node, we add it to the answer,
*/
#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
    void addLeft(Node* root,vector<int>&ans){
        Node* curr=root->left;
        while(curr!=NULL){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left!=NULL) curr=curr->left;
            else curr=curr->right;
        }
    }
    void addRight(Node* root,vector<int>&ans){
        Node* curr=root->right;
        vector<int>temp;
        while(curr!=NULL){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right!=NULL) curr=curr->right;
            else curr=curr->left;
        }
        for(int i=temp.size()-1;i>=0;--i){
            ans.push_back(temp[i]);
        }
    }
    void addLeaves(Node* root,vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left!=NULL) addLeaves(root->left,ans);
        if(root->right!=NULL) addLeaves(root->right,ans);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeft(root,ans);
        addLeaves(root,ans);
        addRight(root,ans);
        return ans;
    }
};