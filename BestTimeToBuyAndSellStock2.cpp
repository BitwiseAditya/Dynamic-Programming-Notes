/* Problem statement
You have been given stock values/prices for N number of days.
Every i-th day signifies the price of a stock on that day. 
Your task is to find the maximum profit which you can make by buying and selling the stocks.

 Note :
You may make as many transactions as you want but can not have 
more than one transaction at a time i.e, if you have the stock, 
you need to sell it first, and then only you can buy it again.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
7
1 2 3 4 5 6 7
Sample Output 1 :
6
Explanation :
We can make the maximum profit by buying the stock on the first day and selling it on the last day.
Sample Input 2 :
1
7
7 6 5 4 3 2 1
Sample Output 2 :
0
Explanation :
We can make the maximum profit by not buying the stock. */


#include <bits/stdc++.h>
using namespace std;
long f(int index, int investment, int n, long prices[],vector<vector<long>> & dp){
    if(index == n){
        if(investment != 0) return -1e9;
        else return 0;
    }
    if(dp[index][investment] != -1){
        return dp[index][investment];
    }
    if(investment != 0){
        long sell = prices[index] + f(index+1,0,n,prices,dp);
        long notsell = f(index+1,1,n,prices,dp);
        return dp[index][investment] = max(sell,notsell);
    }
    else{
        long pick = -prices[index] + f(index+1,1,n,prices,dp);
        long notpick = f(index+1,0,n,prices,dp);
        return dp[index][investment] = max(pick,notpick);
    }
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    long prices[n];
    for(int i=0; i<n; i++){
        prices[i] = *(values + i);
    }
    vector<vector<long>> dp(n+1,vector<long>(2,-1));
    long ans = f(0,0,n,prices,dp);
    if(ans < 0) return 0;
    else return ans;
}







