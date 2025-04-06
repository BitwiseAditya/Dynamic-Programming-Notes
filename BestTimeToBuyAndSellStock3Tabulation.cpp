/* Stock Buy and Sell – Max 2 Transactions Allowed
   In daily share trading,
a trader buys shares and sells them on the same day.If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

                                                                                                                          You are given an array prices[] representing stock prices throughout the day.Note that the second transaction can only start after the first one is
                                                                                                                          complete(buy->sell->buy->sell)
                                                                                                                              .

                                                                                                                          Examples :

    Input : prices[] = [ 10, 22, 5, 75, 65, 80 ] Output : 87 Explanation : Trader will buy at 10 and sells at 22. Profit earned in 1st transaction = 22 - 10 = 12. Then he buys at 5 and sell at 80. Profit earned in 2nd transaction = 80 - 5 = 75. Total profit earned = 12 + 75 = 87. Input : prices[] = [ 2, 30, 15, 10, 8, 25, 80 ] Output : 100 Explanation : Trader will buy at 2 and sells at 30. Profit earned in 1st transaction = 30 - 2 = 28. Then he buys at 8 and sell at 80. Profit earned in 2nd transaction = 80 - 8 = 72. Total profit earned = 28 + 72 = 100. Constraints : 1 <= prices.size() <= 105 1 <= prices[i] <= 105
    */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(2, -1)));
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                if (i > 2)
                    dp[n][i][j] = -1e8;
                else
                    dp[n][i][j] = 0;
            }
        }
        for (int index = n - 1; index >= 0; index--)
        {
            for (int transaction = 0; transaction <= 3; transaction++)
            {
                for (int investment = 0; investment <= 1; investment++)
                {
                    if (investment != 0 && transaction < 3)
                    {
                        int sell = prices[index] + dp[index + 1][transaction + 1][0];
                        int notsell = dp[index + 1][transaction][1];
                        dp[index][transaction][investment] = max(sell, notsell);
                    }
                    else
                    {
                        int pick = INT_MIN, notpick;
                        if (transaction < 2)
                        {
                            pick = -prices[index] + dp[index + 1][transaction][1];
                        }
                        notpick = dp[index + 1][transaction][0];
                        dp[index][transaction][investment] = max(pick, notpick);
                    }
                }
            }
        }
        if (dp[0][0][0] < 0)
            return 0;
        else
            return dp[0][0][0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl
             << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends