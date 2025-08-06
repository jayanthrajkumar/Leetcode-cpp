/*
width can only be between two nodes in the same level,
since the width can be seen only at the levels, we use level order traversal,
we use queue structure where both the index as well as the node are added into the queue,
tricky part is where indexs are hard to keep track as they may move out of the integer range, so we use a special techique of segmentation to assign indexes to the nodes while isnerting into the queue,
we need to kepp track of the node's index as the width needs to be calculated by subtracting the first index from the last index,
in each level we check the width and update the width accordingly 
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            int s=q.size();
            long long mmin=q.front().second;
            long long first,last;
            for(int i=0;i<s;i++){
                long long sec=(q.front().second)-mmin;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=sec;
                if(i==s-1) last=sec;
                if(node->left) q.push({node->left,sec*2+1});
                if(node->right) q.push({node->right,sec*2+2});

            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }