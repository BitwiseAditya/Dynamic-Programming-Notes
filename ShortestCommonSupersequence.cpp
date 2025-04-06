/* Problem statement
Given two strings, ‘A’ and ‘B’. Return the shortest supersequence string ‘S’, containing both ‘A’ and ‘B’ as its subsequences. If there are multiple answers, return any of them.

Note: A string 's' is a subsequence of string 't' if deleting some number of characters from 't' (possibly 0) results in the string 's'.

For example:
Suppose ‘A’ = “brute”, and ‘B’ = “groot”

The shortest supersequence will be “bgruoote”. As shown below, it contains both ‘A’ and ‘B’ as subsequences.

A   A A     A A
b g r u o o t e
  B B   B B B  

It can be proved that the length of supersequence for this input cannot be less than 8. So the output will be bgruoote.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
brute
groot
bleed
blue
Sample Output 1 :
bgruoote
bleued
Explanation For Sample Input 1 :
For First Case - Same as explained in above example.

For the second case - 

‘A’ = “bleed”, and ‘B’ = “blue”

The shortest supersequence will be “bleued”. As shown below, it contains both ‘A’ and ‘B’ as subsequences.

A A A   A A
b l e u e d
B B   B B

It can be proved that the length of supersequence for this input cannot be less than 6. So the output will be bleued.
Sample Input 2 :
2
coding
ninjas
blinding
lights
Sample Output 2 :
codningjas
blindinghts */

#include <bits/stdc++.h>
using namespace std;
string lcs(string & s1, string & s2){
	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	for(int i=0; i<=n; i++){
		dp[i][0] = 0;
	}
	for(int j=0; j<=m; j++){
		dp[0][j] = 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
             if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i - 1][j-1];
             else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string temp;
	int i = n, j = m;
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]){
			temp += s1[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			temp += s1[i-1];
			i--;
		}
		else{
			temp += s2[j-1];
			j--;
		}
	}
	while(i > 0){
		temp += s1[i-1];
		i--;
	}
	while(j > 0){
		temp += s2[j-1];
		j--;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
string shortestSupersequence(string a, string b)
{
	// Write your code here.
	return lcs(a,b);
}











