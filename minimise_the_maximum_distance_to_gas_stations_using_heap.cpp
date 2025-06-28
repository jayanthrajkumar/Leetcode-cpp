#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	vector<int>howmany(n-1,0);
	priority_queue<pair<long double,int>>pq;
	for(int i=0;i<n-1;i++){
		pq.push({arr[i+1]-arr[i],i});
	}
	for(int gasStations=1;gasStations<=k;gasStations++){
		auto tp=pq.top();
		pq.pop();
		int secIndex=tp.second;
		howmany[secIndex]++;
		long double iniDiff=arr[secIndex+1]-arr[secIndex];
		long double ans=iniDiff/(long double)(howmany[secIndex]+1);
		pq.push({ans,secIndex});
	}
	return pq.top().first;
}
};