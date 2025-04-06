/* Problem statement
    For a given array with N elements,
    you need to find the length of the longest subsequence from the array such that all the elements of the subsequence are sorted in strictly increasing order.

    Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.

    For example : [ 1, 2, 3, 4 ] is a strictly increasing array,
    while[2, 1, 4, 3] is not .Detailed explanation(Input / output format, Notes, Images)
Sample Input : 6 5 4 11 1 16 8 Sample Output 1 : 3 Explanation of Sample Input 1 : Length of longest subsequence is 3 i.e.[5, 11, 16] or [ 4, 11, 16 ].Sample Input 2 : 3 1 2 2 Sample Output 2 : 2
*/

#include <bits/stdc++.h>
using namespace std;
int LIS(int index, int prev_index, int arr[], int n, vector<vector<int>> &dp)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[index][prev_index + 1] != -1)
    {
        return dp[index][prev_index + 1];
    }
    int pick = INT_MIN, notpick = INT_MIN;
    notpick = 0 + LIS(index + 1, prev_index, arr, n, dp);
    if (prev_index == -1 || arr[index] > arr[prev_index])
    {
        pick = 1 + LIS(index + 1, index, arr, n, dp);
    }
    return dp[index][prev_index + 1] = max(pick, notpick);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return LIS(0, -1, arr, n, dp);
}
