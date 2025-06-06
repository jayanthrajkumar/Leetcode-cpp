#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int maximum_weight(vector<int>&weights){
    int maxi=INT_MIN;
    for(int i=0;i<weights.size();i++){
        maxi=max(maxi,weights[i]);
    }
    return maxi;
}
int finddays(vector<int>&weights,int capacity){
    int days=1,load=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+load>capacity){
            days++;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=maximum_weight(weights);
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int calculatedays=finddays(weights,mid);
            if(calculatedays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};