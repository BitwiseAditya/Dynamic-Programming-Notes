/* Problem statement
You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find the "Edit Distance" between the strings.

Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:

1. Delete a character
2. Replace a character with another one
3. Insert a character
Note:
Strings don't contain spaces in between.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= N <= 10 ^ 3
0 <= M <= 10 ^ 3

Time Limit : 1sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation For Sample Input 1 :
In 2 operations we can make the string T to look like string S. First, insert the character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of the string T with 'b' from the string S. This would make string T to "abc" which is also the string S. Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9 */


#include <bits/stdc++.h>
using namespace std;
int f(int index1, int index2, string & str1, string & str2, vector<vector<int>> & dp){
    if(index1 < 0){
        return index2 + 1;
    }
    if(index2 < 0){
        return index1 + 1;
    }
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }
    if(str1[index1] == str2[index2]){
       return dp[index1][index2] = f(index1-1, index2-1, str1, str2,dp);
    }
    else{
        int Delete = 1 + f(index1-1,index2,str1,str2,dp);
        int Replace = 1 + f(index1-1,index2-1,str1,str2,dp);
        int Insert = 1 + f(index1, index2 - 1, str1, str2,dp);
        return dp[index1][index2] = min(Delete, min(Replace, Insert));
    }
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return f(n-1,m-1,str1,str2,dp);
}




