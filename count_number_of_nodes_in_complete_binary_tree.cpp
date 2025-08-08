/*
Complete binary tree have the nodes filled at each subtree and also the nodes are complete as left as possible,
we use the concept of comparing the heights of the left subtree and the right subtree, if they match, we can say the tree is of eqaul height and then use the formula to calculate the height,
otherwise we indiviually compute the heights for left subtree and right subtree as they may differ,
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
    int countleftheight(TreeNode* node){
    int height=0;
    while(node){
        height++;
        node=node->left;
    }
    return height;
}
int countrightheight(TreeNode* node){
    int height=0;
    while(node){
        height++;
        node=node->right;
    }
    return height;
}
int countNodes(TreeNode* root)
{
    //    Write your code here.
    if(root==NULL) return 0;
    int left_height=countleftheight(root);
    int right_height=countrightheight(root);
    if(left_height==right_height) return (1<<left_height)-1;
    return 1+countNodes(root->left)+countNodes(root->right);

}