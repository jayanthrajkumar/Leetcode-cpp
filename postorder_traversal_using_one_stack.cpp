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
/* First we use curr to store the root node,
the ultimate condition is to continue till either the stack is empty or the curr is null,
one condition is if the curr is not null, curr is made to point to left child node and the previous curr is inserted into the stack,
otherwise if the curr is null,temp is used to store the right child node,
one more condition is checked, if the temp is null, stack topmost element is popped and stored in the answer,
then we keep on repeating the same steps until the stack becomes empty.
*/
vector<int> postorderTraversal(TreeNode* node) {
    vector<int>ans;
    TreeNode* curr=node;
    stack<TreeNode*>st;
    while(!st.empty() || curr!=NULL){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            TreeNode* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return ans;      
}
};