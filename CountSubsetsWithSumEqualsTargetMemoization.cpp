/* Problem statement
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.



Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.



Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.



Example:
Input: 'arr' = [1, 1, 4, 5]

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently. */

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int countWaysMemo(int index, int current_sum, vector<int>& arr, vector<vector<int>>& memo) {
    if (index == 0) {
        if(current_sum == 0 && arr[0] == 0) return 2;
		if(current_sum == 0 || current_sum == arr[0]) return 1;
		return 0;
    }
    if (memo[index][current_sum] != -1) {
        return memo[index][current_sum];
    }  
    int include = 0;
    if(arr[index] <= current_sum) include = countWaysMemo(index - 1, current_sum - arr[index], arr, memo);
    int exclude = countWaysMemo(index - 1, current_sum, arr, memo);

    memo[index][current_sum] = (include + exclude) % MOD;
    return memo[index][current_sum];
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(k + 1, -1));
    return countWaysMemo(n-1, k, arr, memo);
}


