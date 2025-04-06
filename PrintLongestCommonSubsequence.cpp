// Given two strings s1 and s2, print the LCS (longest common subsequence) between them.

#include <bits/stdc++.h>
using namespace std;
string lcs(string s, string t)
{
    // Write your code here
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= m; index2++)
        {
            if (s[index1 - 1] == t[index2 - 1])
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            else
                dp[index1][index2] = 0 + max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
        }
    }

    string temp;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            temp += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
