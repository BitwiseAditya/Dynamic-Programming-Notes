/* Problem statement
A thief is robbing a store and can carry a maximal weight 
of W into his knapsack. There are N items and the ith item 
weighs wi and is of value vi. Considering the constraints 
of the maximum weight that a knapsack can carry, you have to 
find and return the maximum value that a thief can generate by 
stealing items.

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
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
	for(int w=0; w<=maxWeight; w++){
	   if(w >= weight[0]) 	dp[0][w] = value[0];
	   else dp[0][w] = 0;
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<=maxWeight; j++){
			int notpick = dp[i-1][j];
	        int pick = INT_MIN;
                if (j >= weight[i]) {
                  pick = value[i] + dp[i - 1][j - weight[i]];
                }
             dp[i][j] = max(pick, notpick);
		}
	}
    return dp[n-1][maxWeight];
}

















