/* Problem statement
You are given 2 non-empty strings 's1' and 's2' consisting of lowercase English alphabets only.



In one operation you can do either of the following on 's1':

(1) Remove a character from any position in 's1'.

(2) Add a character to any position in 's1'.



Find the minimum number of operations required to convert string 's1' into 's2'.



Example:
Input: 's1' = "abcd", 's2' = "anc"

Output: 3

Explanation:
Here, 's1' = "abcd", 's2' = "anc".
In one operation remove 's1[3]', after this operation 's1' becomes "abc".    
In the second operation remove 's1[1]', after this operation 's1' becomes "ac".
In the third operation add 'n' in 's1[1]', after this operation 's1' becomes "anc".

Hence, the minimum operations required will be 3. It can be shown that there's no way to convert s1 into s2 in less than 3 moves.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
aaa
aa


Expected Answer :
1


Output on console :
1


Explanation For Sample Output 1:
For this test case,
's1' = "aaa", 's2' = "aa"

In one operation remove 's1[2]', after this operation 's1' becomes "aa".

Hence, the output will be 1.


Sample Input 2 :
edl 
xcqja
Expected Answer :
8


Output on console :
8


Expected Time Complexity :
Try to do this in O(n*m), where n is the length of string 's1' and 'm' is the length of string 's2'.


Constraints:
1 <= s1.length, s2.length <= 100

Time limit: 1 sec */

// Concept used :-
// Minimum No. Of Insertions Or Deletions to convert String A to String B = (Length of String A - LCS(A,B)) + (Length of String B - LCS(A,B))   where LCS(A,B) is the length of Longest Common Subsequence of String A and String B.    
 

#include<bits/stdc++.h>
using namespace std;
int lcsf(int index1, int index2, string & s1, string & s2, vector<vector<int>> & dp){
    if(index1 < 0 || index2 < 0){
        return 0;
    }
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }
    if(s1[index1] == s2[index2]) return dp[index1][index2] = 1 + lcsf( index1 - 1, index2 - 1, s1, s2, dp);
    else return dp[index1][index2] = 0 + max(lcsf( index1 - 1, index2, s1, s2, dp), lcsf( index1, index2 - 1, s1, s2, dp));
}
int canYouMake(string &s1, string &s2){
    // Write your code here.
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    int lcs = lcsf(n1 - 1, n2 - 1, s1, s2, dp);
    return (n1 - lcs + n2 - lcs);
}
