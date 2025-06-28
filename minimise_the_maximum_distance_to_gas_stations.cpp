#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int numberOfGasStationsRequired(long double dist,vector<int>&arr){
	int count=0;
	for(int i=1;i<arr.size();i++){
		int inBetween=((arr[i]-arr[i-1])/dist);
		if((arr[i]-arr[i-1])/dist==inBetween*dist){
			inBetween--;
		}
		count+=inBetween;
	}
	return count;
}
double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	long double low=0,high=0;
	for(int i=0;i<n-1;i++){
		high=max(high,(long double)(arr[i+1]-arr[i]));
	}
	long double diff=1e-6;
	while(high-low>diff){
		long double mid=(low+high)/(2.0);
		int cnt=numberOfGasStationsRequired(mid,arr);
		if(cnt>k){
			low=mid;
		}
		else{
			high=mid;
		}
	}
	return high;
}
};
