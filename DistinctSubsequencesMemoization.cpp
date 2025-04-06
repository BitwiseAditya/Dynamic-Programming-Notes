/*  Distinct Subsequences
Problem statement:-
A Subsequence of a string is the string that is obtained by deleting 0 or more letters from the string and keeping the rest of the letters in the same order.



We are given two strings, 'str' and 'sub'.



Find the number of subsequences of 'str' which are equal to 'sub'.



Since the answer can be very large, print it modulo 10 ^ 9 + 7.



Example :
Input: 'str' = “brootgroot” and 'sub' = “brt”

Output: 3

Explanation: The following subsequences formed by characters at given indices (0-based) of 'str' are equal to 'sub' :

str[0] = ‘b’, str[1] = ‘r’, str[4] = ‘t’

str[0] = ‘b’, str[1] = ‘r’, str[9] = ‘t’

str[0] = ‘b’, str[6] = ‘r’, str[9] = ‘t’
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
brootgroot
brt


Sample Output 1 :
3


Explanation For Sample Input 1 :
The following subsequences formed by characters at given indices (0-based) of 'str' are equal to 'sub' :

str[0] = ‘b’, str[1] = ‘r’, str[4] = ‘t’

str[0] = ‘b’, str[1] = ‘r’, str[9] = ‘t’

str[0] = ‘b’, str[6] = ‘r’, str[9] = ‘t’


Sample Input 2 :
dingdingdingding
ing


Sample Output 2 :
20


Sample Input 3:
aaaaa
a


Sample Output 3:
5


Expected time complexity :
The expected time complexity is O(|str| * |sub|).


Constraints:
1 <= |str| <= 1000
1 <= |sub| <= 1000

Where |str| represents the length of the string 'str', and |sub| represents the length of the string 'sub'.

Time Limit: 1 sec. */

#include<bits/stdc++.h>
using namespace std;
int f(int index1, int index2, string &str, string &sub, vector<vector<int>> & dp){
	if(index2 < 0) return 1;
	if(index1 < 0) return 0;
	if(dp[index1][index2] != -1){
		return dp[index1][index2];
	}
	if(str[index1] == sub[index2]){
		return dp[index1][index2] = (f(index1-1,index2-1,str,sub,dp) + f(index1-1,index2,str,sub,dp)) % ((int)1e9 + 7);
	}
	else{
		return dp[index1][index2] = (f(index1-1,index2,str,sub,dp)) % ((int)1e9 + 7);
	}
}
int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	int n = str.length();
	int m = sub.length(); 
	vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
	return (f(n-1,m-1,str,sub,dp)) % ((int)1e9 + 7);
}


