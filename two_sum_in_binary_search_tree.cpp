/*
We use Iterator approach to traverse over the binary seacrh tree,
we boolean variable to see whether we traversing in inorder or in opposite of inorder,
for reverse traversal, we follow the  opposite approach of iterator,
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
class BSTIterator{
    stack<TreeNode*>s;
    bool reverse=true;
    public:
    BSTIterator(TreeNode* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !s.empty();
    }
    int next(){
        TreeNode* node=s.top();
        s.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    private:
    void pushAll(TreeNode* node){
        while(node){
            s.push(node);
            if(!reverse) node=node->left;
            else node=node->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};