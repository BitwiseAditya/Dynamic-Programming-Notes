/* Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers 
and an integer ‘K’. Your task is to check if there exists 
a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal 
to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets 
with sum = 4. These are {1,3} and {4}. Hence, return true. */

// using memoization:-

#include <bits/stdc++.h> 
using namespace std;    
bool f(int index, int target, vector<int> & arr,vector<vector<int>> & dp){
    if(target == 0) return true;
    if(index == 0) return arr[0] == target;
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    bool notpick = f(index-1,target,arr,dp);
    bool pick = false;
    if(target >= arr[index]){
        pick = f(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target] = notpick || pick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

// same concept for The Partition Equal Subset Sum problem .










