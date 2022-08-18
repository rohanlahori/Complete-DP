
int rec(int n,vector<int> &v,vector<int> &dp)
{
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return dp[n]=abs(v[1]-v[0])+rec(n-1,v,dp);
    }
    return dp[n]=min(abs(v[n]-v[n-1])+rec(n-1,v,dp),abs(v[n]-v[n-2])+rec(n-2,v,dp));
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(1e5+1,-1);
    return rec(n-1,heights,dp);
}
