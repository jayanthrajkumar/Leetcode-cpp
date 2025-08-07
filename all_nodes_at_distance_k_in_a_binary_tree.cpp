#include<bits/stdc++.h>
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