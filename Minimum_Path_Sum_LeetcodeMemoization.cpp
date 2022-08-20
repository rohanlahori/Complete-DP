int rec(int n,int m,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    if(n<0 || m<0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(n==0)
    {
        return dp[n][m]=grid[n][m]+rec(n,m-1,grid,dp);
    }
    else if(m==0)
    {
        return dp[n][m]=grid[n][m]+rec(n-1,m,grid,dp);
    }
    return dp[n][m]=grid[n][m]+min(rec(n-1,m,grid,dp),rec(n,m-1,grid,dp));
}
int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return rec(n-1,m-1,grid,dp);
}
