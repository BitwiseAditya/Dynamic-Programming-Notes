#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	// Write your code here
	vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
	for (int w = 0; w <= maxWeight; w++)
	{
		if (w >= weight[0])
			prev[w] = value[0];
		else
			prev[w] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= maxWeight; j++)
		{
			int notpick = prev[j];
			int pick = INT_MIN;
			if (j >= weight[i])
			{
				pick = value[i] + prev[j - weight[i]];
			}
			curr[j] = max(pick, notpick);
		}
		prev = curr;
	}
	return prev[maxWeight];
}
