#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& A, int key) {
        int n=A.size();
    int low=0,high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==key){
            return true;
        }
        if(A[low]==A[mid] && A[mid]==A[high]){
            low++;
            high--;
            continue;
        }
        if(A[low]<=A[mid]){
            if(A[low]<=key && key<=A[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(A[mid]<=key && key<=A[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
    }
};