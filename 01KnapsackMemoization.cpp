/* Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and the ith item weighs wi and is of value vi. Considering the
 constraints of the maximum weight that a knapsack can carry, you have to find and 
 return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second */

#include <bits/stdc++.h> 
using namespace std;
int f(int index, int W, vector<int> & weight, vector<int> & value, vector<vector<int>> & dp){
	if(index == 0){
		if(W >= weight[0]) return value[0];
		else return 0;
	} 
	if(dp[index][W] != -1){
		return dp[index][W];
	}
	int notpick = f(index-1, W, weight, value,dp);
	int pick = INT_MIN;
	if(W >= weight[index]) pick = value[index] + f(index-1, W-weight[index], weight, value, dp);
	return dp[index][W] = max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return f(n-1,maxWeight, weight, value, dp);
}





