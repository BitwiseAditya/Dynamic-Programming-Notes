/* Problem statement
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', 
with 'N' rows and 'M' columns. Each point in the grid has some cost
associated with it.



Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) 
which minimizes the sum of the cost of all the numbers along the path. You need to 
tell the minimum sum of that path.



Note:
You can only move down or right at any point in time. */


#include <bits/stdc++.h> 
using namespace std;
int f(int i, int j, int n, int m, vector<vector<int>> & grid, vector<vector<int>> & dp){
    if(i == (n-1) && j == (m-1)){
        return grid[i][j];
    }
    if(i > (n-1) || j > (m-1) || i < 0 || j < 0){
        return 1e9;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int down = grid[i][j] + f(i+1,j,n,m,grid,dp);
    int right = grid[i][j] + f(i,j+1,n,m,grid,dp);
    return dp[i][j] = min(down,right);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(0,0,n,m,grid,dp);
}


