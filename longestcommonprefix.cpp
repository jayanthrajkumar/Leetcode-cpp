#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCommonPrefix(vector<string>& strs, int len){
        string str1 = strs[0].substr(0, len);
        //check str1 is the prefix of all strs[1] to strs[n-1]
        for(int i = 1; i < strs.size(); i++){
            //str1.rfind(str2, 0) == 0: str1.startswith(str2)
            if(strs[i].rfind(str1, 0) != 0) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int _min = INT_MAX;
        for(string str : strs) _min = min(_min, (int)str.size());
        //use binary search to find 
        int low = 1, high = _min;
        while(low <= high){
            int middle = (low+high)/2;
            if(isCommonPrefix(strs, middle)){
                low = middle + 1;
            }else{
                high = middle - 1;
            }
        }
        //same result:
        // return strs[0].substr(0, (low+high)/2);
        return strs[0].substr(0, high);
    }
};