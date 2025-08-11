/* 
Uique binary trees can be constructed only from inorder and preorder or from inorder and postorder,
Preorder vectors first element is the root and we can build the tree from that,
then we locate the root element in the inorder, and the elements to the left of the root are the left subtree and the elements to the right of the right subtree form the right subtree,
the tree can be build only recursively,
map is used to keep a recording of the inorder elements indices, 
we continue till the preorder starting index is greater than the preorder ending index or the inorder starting index is greater than the inorder ending index,
inroot is used to locate the index of the root in the inroder vector
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
TreeNode* buildTree(vector<int>&preorder,int prestart, int preend, vector<int>&inorder,int instart, int inend,map<int,int>&inorderIndex){
    if(prestart>preend || instart>inend){
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[prestart]);
    int inroot=inorderIndex[root->val];
    int numsleft=inroot-instart;
    root->left=buildTree(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,inorderIndex);
    root->right=buildTree(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,inorderIndex);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inorderIndex;
        for(int i=0;i<inorder.size();i++){
            inorderIndex[inorder[i]]=i;
        }
        TreeNode* ans=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inorderIndex);
        return ans;
    }