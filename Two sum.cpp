#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>prefixsum;
        for(int i=0;i<n;i++){
            int a=nums[i];
            int more=target-a;
            if(prefixsum.find(more)!=prefixsum.end()){
                return {prefixsum[more],i};
            }
            prefixsum[a]=i;
        }
        return {-1,-1};
    }
}; 