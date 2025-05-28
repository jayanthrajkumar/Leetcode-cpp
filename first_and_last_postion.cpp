#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int first_position(vector<int>&nums,int target){
    int n=nums.size();
    int low=0,high=n-1;
    int mid,ans=n;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int last_position(vector<int>&nums,int target){
    int n=nums.size();
    int low=0,high=n-1;
    int mid,ans=n;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int fp=first_position(nums,target);
        if(fp==n || nums[fp]!=target){
            return {-1,-1};
        }
        else{
            return {fp,last_position(nums,target)-1};
        }
    }
};