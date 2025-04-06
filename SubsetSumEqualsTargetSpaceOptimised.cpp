// space optimised solution of the Subset sum equals target problem.


#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1,false);
    vector<bool> curr(k+1,false);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;
    for(int index=1; index<n; index++){
        for(int target=1; target<=k; target++){
             bool notpick = prev[target];
             bool pick = false;
             if(target >= arr[index]){
                 pick = prev[target-arr[index]];
             }
             curr[target] = notpick || pick;
        }
      prev = curr;  
    }
    return prev[k];
}


















