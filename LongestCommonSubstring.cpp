/* Problem statement
You are given two strings, 'str1' and 'str2'. 
You have to find the length of the longest common substring.


A substring is a continuous segment of a string. 
For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not.


Example:
Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”.

Output: 3

Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”, of length 3.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
wasdijkl
wsdjkl
Sample Output 1:
 3
Explanation Of Sample Input 1 :
 The longest common substring is “jkl”, of length 3.
Sample Input 2:
tyfg
cvbnuty
Sample Output 2:
2
Explanation Of Sample Input 2 :
The longest common substring is “ty”, of length 2.
Expected time complexity:
The expected time complexity is O(n*m),
Where ‘n’ and ‘m’ are the lengths of ‘st1’ and ‘str2’ respectively.
Constraints:
1 <= str1.length <= 1000
1 <= str2.length <= 1000 */

#include <bits/stdc++.h>
using namespace std;
int lcs(string &str1, string &str2){
    // Write your code here.
	int n = str1.length();
	int m = str2.length();
    int ans = 0;
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	for(int i=0; i<=n; i++){
		dp[i][0] = 0;
	}
	for(int i=0; i<=m; i++){
		dp[0][i] = 0;
	}
	for(int index1 = 1; index1 <= n; index1++){
                for (int index2 = 1; index2 <= m; index2++) {
                  if (str1[index1 - 1] == str2[index2 - 1])
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                  else
                    dp[index1][index2] = 0;
                  ans = max(ans, dp[index1][index2]);
                }
        }
        return ans;
}

