/* Problem statement
You are given an array 'arr' containing 'n' non-negative integers.

Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.

You just need to find the minimum absolute difference considering any valid division of the array elements.

Note:

1. Each array element should belong to exactly one of the subsets.

2. Subsets need not always be contiguous.
For example, for the array : [1, 2, 3], some of the possible divisions are 
   a) {1,2} and {3}
   b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset. 
Example:
Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].

Ouput: 1

Explanation: We can partition the given array into {3, 1, 5} and {2, 8}. 
This will give us the minimum possible absolute difference i.e. (10 - 9 = 1).
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
1 2 3 4
Sample Output 1:
0
Explanation for sample input 1:
We can partition the given array into {2,3} and {1,4}.
This will give us the minimum possible absolute difference i.e. (5 - 5 = 0) in this case.
Sample Input 2:
3
8 6 5
Sample Output 2:
3
Explanation for sample input 2:
We can partition the given array into {8} and {6,5}. 
This will give us the minimum possible absolute difference i.e. (11 - 8 = 3).
Expected time complexity:
The expected time complexity is O(n * 𝚺 'arr'[i]), where 𝚺 'arr'[i] denotes the sum of all elements in 'arr'.
Constraints:
1 <= 'n' <= 10^3
0 <= 'arr'[i] <= 10^3
0 <= 𝚺 'arr'[i] <= 10^4, 

where 𝚺 'arr'[i] denotes the sum of all elements in 'arr'.

Time Limit: 1sec */

#include<bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
	vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
	for(int i=0; i<n; i++){
		dp[i][0] = true;
	}
	if(arr[0] <= sum) dp[0][arr[0]] = true;
	for(int i=1; i<n; i++){
		for(int j=1; j<=sum; j++){
			bool notpick = dp[i-1][j];
			bool pick = false;
			if(j >= arr[i])
			  pick = dp[i-1][j-arr[i]];
			dp[i][j] = pick || notpick;
		}
	}
	int ans = 1e9;
	for(int i=0; i<=sum; i++){
		if(dp[n-1][i] == true){
            int s1 = i;
			int s2 = sum-i;
			ans = min(ans,abs(s1-s2));
		}
	}
	return ans;
}

