int tabulation(int n,vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1, vector<int>(4,0));
    for(int i=0;i<3;i++)
    {
        dp[0][i]=points[0][i];
    }
    vector<int>dx{1,-1,-2};
    vector<int>dy{2,1,-1};
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            int day=j;
            int pts=points[i][day];
            int day1=day+dx[day];
            int day2=day+dy[day];
            dp[i][j]+=max(points[i][j]+dp[i-1][day1],points[i][j]+dp[i-1][day2]);
        }
    }
    return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return tabulation(n,points);
}
