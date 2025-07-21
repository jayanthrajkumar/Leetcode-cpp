/*
it deals with the vertical order of the binary tree,
left most subnode is sorted in ascending order where the root comes with the vertical axis value of 0, left node as -1,right node as 1,etc.,
levels are assigned to keep track of the levels, with the root level as 0 and next level with value 1, ans so-on.,
we use a queue to keep track of the nodes, each node along with its vertical position and level position is added int the queue,
then we use a map to keep track of the order of the node, it uses a multiset data structure to sort the nodes having the same vertical position and the level position according to the node value,
first we push the root node along with its vp and lp into the queue,
if a leftnode exists, it is pushed into the queue with the vp being a value lesser than the node vp and lp being a value greater than the node lp,
then the node's value along with the vp and lp being inserted in the map,
then first we iterate throught the map,pushing the nodes value into the vector, if mutliple nodes having same vp and lp, then the sorted order is inserted into teh vector
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
struct TreeNode {
  int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* node=p.first;
            int x=p.second.first,y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};