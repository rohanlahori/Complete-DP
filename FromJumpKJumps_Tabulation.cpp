int tabulate(int n,vector<int> &v,int k,vector<int> &dp)
{
    dp[0]=0;
    if(n>1)
    {
        dp[1]=abs(v[0]-v[1]);
    }
    int mn=INT_MAX;
    for(int i=2;i<n;i++)
    {
        int mn=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                mn=min(mn,abs(v[i]-v[i-j])+dp[i-j]);
            }
        }
        dp[i]=mn;
    }
    return dp[n-1];
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
    return tabulate(n,v,k,dp);
}
