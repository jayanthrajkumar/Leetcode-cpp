#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int maxelement(vector<int>&piles){
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
int calculatehourlybananas(vector<int>&piles,int hourly){
    int n=piles.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(piles[i]+hourly-1)/hourly;
    }
    return ans;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maxelement(piles);
        while(low<=high){
            int mid=(low+high)/2;
            int midk=calculatehourlybananas(piles,mid);
            if(midk<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};