bool rec(int n,int m,string &s,string &s1,vector<vector<int>> &dp)
{
    if(n==-1 && m==-1)
    {
        return 1;
    }
    if(n==-1)
    {
        for(int i=0;i<=m;i++)
        {
            if(s1[i]!='*')
            {
                return 0;
            }
        }
        return 1;
    }
    if(m==-1)
    {
        return 0;
    }

    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s[n]==s1[m])
    {
        return dp[n][m]=rec(n-1,m-1,s,s1,dp);
    }
    else{
        if(s[n]!=s1[m])
        {
            if(s1[m]=='?')
            {
                return dp[n][m]=rec(n-1,m-1,s,s1,dp);
            }
            else if(s1[m]=='*')
            {
                bool val=0;
                for(int i=0;i<=n+1;i++)
                {
                    val= val | rec(n-i,m-1,s,s1,dp);
                }
                return dp[n][m]=val;
            }
            else{
                return 0;
            }
        }
    }
    return 0;
}
bool isMatch(string s, string p) {
    int n=s.length();
    int m=p.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return rec(n-1,m-1,s,p,dp);
}
