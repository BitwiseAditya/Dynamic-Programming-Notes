/* Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers 
and an integer ‘K’. Your task is to check if there exists 
a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal 
to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 
subsets with sum = 4. These are {1,3} and {4}. Hence, return true. */

#include <bits/stdc++.h> 
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int index=1; index<n; index++){
        for(int target=1; target<=k; target++){
             bool notpick = dp[index-1][target];
             bool pick = false;
             if(target >= arr[index]){
                 pick = dp[index-1][target-arr[index]];
             }
             dp[index][target] = notpick || pick;
        }
    }
    return dp[n-1][k];
}

// Can easily be space optimised using 1d array of size of target + 1.
// same concept used by the Partition Equal Subset Sum problem .




































