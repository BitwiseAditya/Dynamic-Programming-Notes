/*  Distinct Subsequences
Problem statement
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
int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	int n = str.length();
	int m = sub.length(); 
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for(int i=0; i<=n; i++){
		dp[i][0] = 1;
	}
	for(int i=1; i<=m; i++){
		dp[0][i] = 0;
	}
	for(int index1=1; index1<=n; index1++){
		for(int index2=1; index2<=m; index2++){
		   if(str[index1-1] == sub[index2-1]){
		      dp[index1][index2] = (dp[index1-1][index2-1] + dp[index1-1][index2]) % ((int)1e9 + 7);
	       }
	       else{
		      dp[index1][index2] = dp[index1-1][index2] % ((int)1e9 + 7);
	       }
		}
	}
	return dp[n][m] % ((int)1e9+7);
}




