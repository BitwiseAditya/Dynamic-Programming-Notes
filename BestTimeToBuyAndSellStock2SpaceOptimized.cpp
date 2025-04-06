/* Problem statement
You have been given stock values/prices for N number of days. Every i-th day signifies the price of a stock on that day. Your task is to find the maximum profit which you can make by buying and selling the stocks.

 Note :
You may make as many transactions as you want but can not have more than one transaction at a time i.e, if you have the stock, you need to sell it first, and then only you can buy it again.
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
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    long prices[n];
    for(int i=0; i<n; i++){
        prices[i] = *(values + i);
    }
    vector<long> ahead(2,-1), curr(2,-1);
    ahead[0] = 0;
    ahead[1] = -1e9;
    for(int index=n-1; index>=0; index--){
        for(int investment=0; investment<=1; investment++){
            if(investment != 0){
                long sell = prices[index] + ahead[0];
                long notsell = ahead[1];
                curr[investment] = max(sell,notsell);
            }
            else{
                 long pick = -prices[index] + ahead[1];
                 long notpick = ahead[0];
                 curr[investment] = max(pick,notpick);
            }
        }
        ahead = curr;
    }
    if(ahead[0] < 0) return 0;
    else return ahead[0];
}


