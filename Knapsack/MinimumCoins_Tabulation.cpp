#include<bits/stdc++.h>
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=x;i++)
    {
        dp[0][i]=1e9;
        if(i%num[0]==0)
        {
            dp[1][i]=i/num[0];
        }
        else{
            dp[1][i]=1e9;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            int nottake=dp[i-1][j];
            int take=1e9;
            int rep=1e9;
            if(num[i-1]<=j)
            {
                rep=1+dp[i][j-num[i-1]];
                take=1+dp[i-1][j-num[i-1]];
            }
            dp[i][j]=min({nottake,rep,take});
        }
    }
    if(dp[n][x]==1e9)
    {
        return -1;
    }
    return dp[n][x];
}
