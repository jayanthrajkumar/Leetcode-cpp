#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int count_split(vector<int>&nums,int max_sum){
    int split_subarrays_count=1;
    long long sum_count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]+sum_count<=max_sum){
            sum_count+=nums[i];
        }
        else{
            sum_count=nums[i];
            split_subarrays_count++;
        }
    }
    return split_subarrays_count;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int split_count=count_split(nums,mid);
            if(split_count>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};