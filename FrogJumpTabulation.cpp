
int tabulate(int n,vector<int> &v)
{
    vector<int>dp(1e5+1);
    dp[0]=0;
    if(n>1)
    {
        dp[1]=abs(v[1]-v[0]);
    }
    for(int i=2;i<n;i++)
    {
        dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i]-v[i-2]));
    }
    return dp[n-1];
}
int frogJump(int n, vector<int> &heights)
{
    return tabulate(n,heights);
}
