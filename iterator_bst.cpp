/*
Given a BST tree, we need to find what will be the next element to the iterator, or whether the next element exists for a given iterator,
Since the inorder traversal is sorted for the bst, 
we use the inorder approach using the stack approach,
the BST constructor is used the nodes to the left into the stack,
next function returns the next element pointed by the iterator,
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
class BSTIterator {
    private:
    stack<TreeNode*>s;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *node=s.top();
        s.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    private:
    void pushAll(TreeNode *node){
        while(node){
            s.push(node);
            node=node->left;
        }
    }
};
