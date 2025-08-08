/*
this problem involves finding out the the nodes at a distance k from a given node,
we use bfs to kepp track of the parent node of each node, since if we traverse from a node, we can traverse int three directions,
left subnode, then to right subnode and then upwards which cannot be done unless we know about the parent node of each node,
we use a map data structure to keep track of the parent node and the child node,
and we use a map to keep tack of all the visited nodes such that no two nodes are traversed twice which are at the same distance from the target,
and with each step we increase teh distance varaible until we reach the number of steps specified and return the number of nodes.
*/#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
void bfs_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mpp,TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr->left!=NULL){
                mpp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                mpp[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>mpp;
        bfs_parent(root,mpp,target);

        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);

        vis[target]=true;
        int curr_level =0; 

        while(!q.empty()){
            int size= q.size();
            if(curr_level==k){
                break;
                
            }
            curr_level++;
            for(int i =0; i<size; i++){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left!=NULL && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right!=NULL && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(mpp[curr]!=NULL && !vis[mpp[curr]]){
                    q.push(mpp[curr]);
                    vis[mpp[curr]]=true;
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;

    }