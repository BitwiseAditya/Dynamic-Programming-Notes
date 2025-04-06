// Space Optimized Solution for the Distinct Subsequences Problem   

#include<bits/stdc++.h>
using namespace std;
int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	int n = str.length();
	int m = sub.length(); 
	vector<int> prev(m+1,0), curr(m+1,0);
	prev[0] = curr[0] = 1;
	for(int index1=1; index1<=n; index1++){
		for(int index2=1; index2<=m; index2++){
		   if(str[index1-1] == sub[index2-1]){
		      curr[index2] = (prev[index2-1] + prev[index2]) % ((int)1e9 + 7);
	       }
	       else{
	          curr[index2] = prev[index2] % ((int)1e9 + 7);
	       }
		}
		prev = curr;
	}
	return prev[m] % ((int)1e9+7);
}







