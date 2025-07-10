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
/* We use two stacks for this one, 
Start with checking the root node to be null, then push the node into the stack1,
then take the top most node of the first stack, pop and push it into the second stack,
then whether the node has left child nodes, if yes push it into the stack1 and then look for the right child node, if so, do the same,
then again pop the topmost node of the stack1 and repeat the procedure,
poping the stack2 gives the post_order traversal of the binary tree*/
  vector<int> postOrder(TreeNode* node) {
        vector<int>ans;
        if(node==NULL) return ans;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(node);
        while(!st1.empty()){
            node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
}
};