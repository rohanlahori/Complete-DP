int rec(int n,vector<int> &v,int k,vector<int> &dp)
{
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    if(n==0)
    {
        return 0;
    }
    int mn=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
            dp[n]=mn=min(mn,abs(v[n-i]-v[n])+rec(n-i,v,k,dp));
        }
    }
    return mn;
}
int kick()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n+1);
    f(i,0,n)
    {
        cin>>v[i];
    }
    vector<int>dp(n+1,-1);
    return rec(n-1,v,k,dp);
}
