/* Problem statement
Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.

For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.

Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
adebc
dcadb
Sample Output 1 :
3
Explanation of the Sample Output 1 :
Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 
Sample Input 2 :
ab
defg
Sample Output 2 :
0
Explanation of the Sample Output 2 :
The only subsequence that is common to both the given strings is an empty string("") of length 0. */

#include <bits/stdc++.h>
using namespace std;
int f(int index1, int index2, string & s, string & t, vector<vector<int>> & dp){
	if(index1 < 0 || index2 < 0){
		return 0;
	}
	if(dp[index1][index2] != -1){
		return dp[index1][index2];
	}
	if(s[index1] == t[index2]){
		return dp[index1][index2] = 1 + f(index1-1, index2-1, s, t, dp);
	}
	else{
		return dp[index1][index2] = 0 + max(f(index1-1, index2, s, t, dp), f(index1, index2 - 1, s, t, dp));
	}
}
int lcs(string s, string t)
{
	//Write your code here
	int n = s.length();
	int m = t.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	return f(n-1, m-1, s, t, dp);
}





