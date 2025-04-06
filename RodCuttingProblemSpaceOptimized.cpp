#include<bits/stdc++.h>
using namespace std;
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> prev(n+1, 0), curr(n+1, 0);
	for(int len=0; len<=n; len++){
		if(len >= 1) prev[len] = (len/1)*price[0];
		else prev[len] = 0;
	}
	for(int ind=1; ind<n; ind++){
		for(int len=0; len<=n; len++){
			int notpick = 0 + prev[len];
	        int pick = INT_MIN;
	        if(len >= ind + 1) pick = price[ind] + curr[len - (ind + 1)];
	        curr[len] = max(pick, notpick);
		}
		prev = curr;
	}
	return prev[n];
}






