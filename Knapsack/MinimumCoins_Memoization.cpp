#include<bits/stdc++.h>
int rec(int n,vector<int> &nums,int x,vector<vector<int>> &dp)
{
    if(x==0)
    {
        return 0;
    }
    if(n==-1)
    {
        return 1e9;
    }
    if(dp[n][x]!=-1)
    {
        return dp[n][x];
    }
    int nottake=rec(n-1,nums,x,dp);
    int rep=1e9,take=1e9;
    if(nums[n]<=x)
    {
        rep=1+rec(n,nums,x-nums[n],dp);
        take=1+rec(n-1,nums,x-nums[n],dp);
    }
    return dp[n][x]=min({rep,take,nottake});
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    int ans= rec(n-1,num,x,dp);
    if(ans==1e9)
    {
        ans=-1;
    }
    return ans;
}
