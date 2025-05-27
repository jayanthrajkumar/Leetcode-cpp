#include<bits/stdc++.h>
using namespace std;
int getfloor(vector<int>&a,int n,int x){
	int low=0;
	int high=n-1;
	int ans=-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]<=x){
			ans=a[mid];
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	if(ans>x)return -1;
	return ans;
}
int getceil(vector<int>&a,int n,int x){
	int low=0;
	int high=n-1;
	int ans=-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]>=x){
			ans=a[mid];
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	if(ans<x)return -1;
	return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	return {getfloor(a,n,x),getceil(a,n,x)};
}