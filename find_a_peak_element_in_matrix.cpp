#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int maximum_element(vector<vector<int> >&g,int n,int m,int col){
    int maxvalue=-1,index=-1;
    for(int i=0;i<n;i++){
        if(maxvalue<g[i][col]){
            maxvalue=g[i][col];
            index=i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int> >& g) {
        int n=g.size();
    int m=g[0].size();
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int index=maximum_element(g,n,m,mid);
        int left=mid-1>=0?g[index][mid-1]:-1;
        int right=mid+1<m?g[index][mid+1]:-1;
        if(g[index][mid]>left && g[index][mid]>right){
            return {index,mid};
        }
        else if(g[index][mid]<left){
            high=mid-1;
        }
        else low=mid+1;
    }
    return {-1,-1};
    }
};