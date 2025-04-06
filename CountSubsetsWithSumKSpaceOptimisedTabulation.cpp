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
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<int> prev(k+1,0), curr(k+1,0);
	prev[0] = curr[0] = 1;
	if(arr[0] <= k) prev[arr[0]] = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<=k; j++){
			int notpick = prev[j];
			int pick = 0;
			if(arr[i] <= j) pick = prev[j-arr[i]];
			curr[j] = pick + notpick;
		}
		prev = curr;
	}
	return prev[k];
}







