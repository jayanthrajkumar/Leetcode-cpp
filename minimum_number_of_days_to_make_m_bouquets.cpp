#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int,int> maximumelement(vector<int>&arr){
	int maxi=INT_MIN;
	int mini=INT_MAX;
	for(int i=0;i<arr.size();i++){
		maxi=max(maxi,arr[i]);
		mini=min(mini,arr[i]);
	}
	return {mini,maxi};
}
bool calculate_rose_garden(vector<int>arr,int day,int k,int m){
	int count=0,no_of_bouquet=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]<=day){
			count++;
		}
		else{
			no_of_bouquet+=(count/k);
			count=0;
		}
	}
	no_of_bouquet+=(count/k);
	return no_of_bouquet>=m;
}
int minDays(vector<int> arr, int m, int k)
{
	long long val=k*1LL*m*1LL;
	if(arr.size()<val) return -1;
	pair<int,int>maximum=maximumelement(arr);
	int low=maximum.first;
	int high=maximum.second;
	while(low<=high){
		int mid=(low+high)/2;
		if(calculate_rose_garden(arr,mid,k,m))
		{
			high=mid-1;
		} 
		else low=mid+1;
	}
	return low;
}
};