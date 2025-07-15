/*
maximum path calculates the maximum sum of teh path in a tree,
same technique of finding the depth of the tree is used,
but here a variable named maxi is used to store the maximum sum,
if from a subtree, the sum is in negative,it is made as zero instead of carrying it over,
sum of a path is nothing but the sum of the left subtree,right subtree and the value of the node.
*/
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        calculate_path_sum(root,maxi);
        return maxi;
    }
    int calculate_path_sum(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int lt=max(0,calculate_path_sum(root->left,maxi));
        int rt=max(0,calculate_path_sum(root->right,maxi));
        maxi=max(maxi,lt+rt+root->data);
        return max(lt,rt)+root->data;
    }