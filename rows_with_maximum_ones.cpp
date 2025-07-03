#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>&matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int index=0,total_count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
        if(matrix[i][j]==1){
            sum++;
        }
    }
    if(sum>total_count){
        total_count=sum;
        index=i;
    }
    }
    return {index,total_count};
    }
};