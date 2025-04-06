/* Problem statement
There is a frog on the '1st' step of an 'N' stairs long staircase. 
The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height 
of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the
energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair.
Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) 
and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20. */


#include <bits/stdc++.h> 
using namespace std;
int jump(int i, vector<int> & heights, vector<int> & dp){
    if(i == 0){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int plusOne = jump(i - 1, heights,dp) + abs(heights[i-1] - heights[i]);
    int plusTwo = INT_MAX;
    if(i-2 >= 0)
    plusTwo = jump(i-2, heights,dp) + abs(heights[i-2] - heights[i]);
    return dp[i] = min(plusOne,plusTwo);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+4,-1);
    return jump(n-1,heights,dp);
}








