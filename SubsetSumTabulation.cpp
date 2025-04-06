/* Subset Sum Problem
    Given an array of positive integers arr[] and a value sum,
    determine if there is a subset of arr[] with sum equal to given sum.

    Examples :

    Input : arr[] = [ 3, 34, 4, 12, 5, 2 ],sum = 9 Output : true
    Explanation : Here there exists a subset with target sum = 9, 4 + 3 + 2 = 9.
    Input : arr[] = [ 3, 34, 4, 12, 5, 2 ], sum = 30 Output : false
    Explanation : There is no subset with target sum 30.
    Input : arr[] = [ 1, 2, 3 ], sum = 6 Output : true
    Explanation : The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

    Constraints : 1 <= arr.size() <= 200 1 <= arr[i] <= 200 1 <= sum <= 104 */

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        for (int i = 0; i <= sum; i++)
        {
            if (i == 0)
                dp[n - 1][i] = true;
            else if (i - arr[n - 1] == 0)
                dp[n - 1][i] = true;
            else
                dp[n - 1][i] = false;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= sum; j++)
            {
                bool pick = false, notpick;
                if (j >= arr[i])
                {
                    pick = dp[i + 1][j - arr[i]];
                }
                notpick = dp[i + 1][j];
                dp[i][j] = pick || notpick;
            }
        }
        return dp[0][sum];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
