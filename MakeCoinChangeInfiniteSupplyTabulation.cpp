/* Problem statement
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. Print 0, if a change isn't possible.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
1 2 3
4
Sample Output 1:
4
Explanation for Sample Output 1:
We can make a change for the value V = 4 in four ways.
1. (1,1,1,1), 
2. (1,1, 2), [One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1) and (1, 2, 1)]
3. (1, 3), and 
4. (2, 2)
Sample Input 2 :
3
5 3 2
1
Sample Output 2:
0 */

#include <bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<long> arr(n);
    for(int i=0; i<n; i++){
        arr[i] = *(denominations + i);
    }
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    for(int t=0; t<=value; t++){
        if(t % arr[0] == 0) dp[0][t] = 1;
        else dp[0][t] = 0;
    }
    for(long index=1; index<n; index++){
        for(long target=0; target<=value; target++){
             long notpick = dp[index-1][target];
             long pick = 0;
             if(arr[index] <= target) pick = dp[index][target - arr[index]];
             dp[index][target] = pick + notpick;
        }
    }
    return dp[n-1][value];
}






