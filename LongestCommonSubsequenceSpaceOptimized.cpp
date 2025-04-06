#include <bits/stdc++.h>
using namespace std;
int lcs(string s, string t)
{
	//Write your code here
	int n = s.length();
	int m = t.length();
	vector<int> prev(m+1, -1), curr(m+1, -1);
	for(int i=0; i<=n; i++){
		curr[i] = 0;
	}
	for(int i=0; i<=m; i++){
		prev[i] = 0;
	}
	for(int index1 = 1; index1 <= n; index1++){
		for(int index2 = 1; index2 <= m; index2++){
	    if(s[index1-1] == t[index2-1]) curr[index2] = 1 + prev[index2-1];
	    else curr[index2] = 0 + max(prev[index2], curr[index2 - 1]);
		}
		prev = curr;
	}
	return prev[m];
}

