/* Problem statement
A palindrome string is one that reads the same backward as well as forward.

You are given a string 'str'.

Find the minimum number of characters needed to insert in 'str' to make it a palindromic string.

Example :
Input: 'str' = "abca"

Output: 1

Explanation:
If we insert the character ‘b’ after ‘c’, we get the string "abcba", which is a palindromic string. Please note that there are also other ways possible.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
abca


Sample Output 1:
1


Explanation for input 1:
If we insert the character ‘b’ after ‘c’, we get the string "abcba", which is a palindromic string. Please note that there are also other ways possible.


Sample Input 2:
abcdefg


Sample Output 2:
6


Sample Input 3:
aaaaa


Sample Output 3:
0


Expected time complexity :
The expected time complexity is O(|str| ^ 2).


Constraints:
1 <= |str| <= 1000

Where |str| represents the length of the string 'str'.

Time Limit: 1 sec. */

// Concept used :-
// Minimum no. of insertions/deletions to make a string palindrome = str.length() - Longest Palindromic Subsequence of str.

#include <bits/stdc++.h>
using namespace std;
int lcs(int index1, int index2, string & str1, string & str2, vector<vector<int>> & dp){
	if(index1 < 0 || index2 < 0){
		return 0;
	}
	if(dp[index1][index2] != -1){
		return dp[index1][index2];
	}
	if(str1[index1] == str2[index2]) return dp[index1][index2] = 1 + lcs(index1 - 1, index2 - 1, str1, str2, dp);
	else return dp[index1][index2] = 0 + max(lcs(index1 - 1, index2, str1, str2, dp), lcs(index1 , index2 - 1, str1, str2, dp));
}
int minimumInsertions(string &str)
{
	// Write your code here.
	int n = str.length();
	string org = str;
	reverse(str.begin(), str.end());
	vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
	int m = lcs(n-1, n-1, org, str, dp);
	return (n - m);
}





