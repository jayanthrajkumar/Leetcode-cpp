/*
A binary tree has to be serialized into a string, so that it can be deserialized again from the string to recreate the original binary tree again,
For traversing the tree, we use level order traversal, first the root is traversed, and inserted into the string,
all the nodes are seperated by a comma, instead of the usual level order traversal, we push also the null values into the queue,
if we encounter a null value from the queue, a # character is inserted into the string to keep note of the null values,
For deserialization, we make use of stringstream and getline to access each character one by one,
then we first recreate the root of the tree, then push it ito the queue,
then the next character is the left node, if the value is # , we make the leftnode as null and move on to the right node,
otherwise it is made as the left node and added into the queue,
then we repeat the same set of steps for the next node to be as the right node as well.
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 string serialize(TreeNode* root) {
        string s="";
        if(root==NULL) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it==NULL) s.append("#,");
            else s.append(to_string(it->val)+",");
            if(it!=NULL){
                q.push(it->left);
                q.push(it->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                node->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                node->right=rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }