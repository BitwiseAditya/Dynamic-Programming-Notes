/* Problem statement
Given a text and a wildcard pattern of size N and M respectively, 
implement a wildcard pattern matching algorithm that finds if the 
wildcard pattern is matched with the text. The matching should cover 
the entire text not partial text.

The wildcard pattern can include the characters ‘?’ and ‘*’

 ‘?’ – matches any single character 
 ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= 200

Where 'N' denotes the length of 'TEXT' and 'M' denotes the length of 'PATTERN'.

'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain special characters ‘*’ and ‘?’

Time Limit: 1sec
Sample Input 1:
3
?ay
ray
ab*cd
abdefcd
ab?d
abcc
Sample Output 1:
True
True
False
Explanation of the Sample Input1:
Test Case 1:
The pattern is “?ay” and the text is ray.
‘?’ can match a character so it matches with a character ‘r’ of the text and rest of the text matches with the pattern so we print True.

Test Case 2:
“ab” of text matches with “ab” of pattern and then ‘*’ of pattern matches with “def” of the text and “cd” of text matches with “cd” of the pattern. Whole text matches with the pattern so we print True.

Test Case 3:
“ab” of pattern matches with “ab” of text. ‘?’ of pattern matches with ‘c’ of the text but ‘d’ of the pattern do not match with ‘c’ of the text so we print False.
Sample Input 1:
1
ba*a?
baaabab
Sample Output 1:
True */

#include <bits/stdc++.h>
using namespace std;
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n = pattern.length();
   int m = text.length();
   vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
   dp[0][0] = true;
   for(int i=1; i<=m; i++){
      dp[0][i] = false;
   }
   for(int i=1; i<=n; i++){
      bool flag = true;
      for (int j = i; j >= 1; j--) {
        if (pattern[j-1] != '*'){
            flag = false;
            break;
        }
      }
    dp[i][0] = flag;
   }
   for(int index1=1; index1<=n; index1++){
      for(int index2=1; index2<=m; index2++){
          if(pattern[index1-1] == text[index2-1] || pattern[index1-1] == '?'){
             dp[index1][index2] =  dp[index1 - 1][index2 - 1];
          }
          else if(pattern[index1-1] == '*'){
             dp[index1][index2] = dp[index1 - 1][index2] || dp[index1][index2 - 1];
          }
          else dp[index1][index2] = false;
      }
   }
   return dp[n][m];
}









