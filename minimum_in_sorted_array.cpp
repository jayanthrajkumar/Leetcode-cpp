#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
	int low=0,high=n-1;
	int mid,ans=INT_MAX;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[low]<=arr[high]){
			ans=min(arr[low],ans);
			break;
		}
		if(arr[low]<=arr[mid]){
			ans=min(arr[low],ans);
			low=mid+1;
		}
		else{
			ans=min(arr[mid],ans);
			high=mid-1;
		}

	}
	return ans;
    }
};