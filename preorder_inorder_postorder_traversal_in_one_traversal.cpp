/* 
basically, we have a stack which stores the node and the value,
first root along with value as 1 is inserted into the stack,
three conditions are checked based upon the value,
if it is one, it is added into the preorder, value is incremented to two and if the node has a left, the left subnode is added into the stack with value 1,
if it is two,it is added into the inorder, value is incremented to three and if the node has a right, the right subnode is added into the stack with value 1,
if it is three,it is added into the postorder, the node is popped out of the stack.
*/
#include<bits/stdc++.h>
using namespace std;
class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>>answer;
    vector<int>pre;
    vector<int>ino;
    vector<int>post;
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL) st.push({it.first->left,1});
        }
        else if(it.second==2){
            ino.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL) st.push({it.first->right,1});
        }
        else{
            post.push_back(it.first->data);
        }
    }
    answer.push_back(ino);
    answer.push_back(pre);
    
    answer.push_back(post);
    return answer;
}