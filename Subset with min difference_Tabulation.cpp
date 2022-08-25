#include<bits/stdc++.h>
int rec(int n,vector<int> &arr,int cur,int sum,int &mn,vector<vector<int>> &dp)
{
    mn=min(mn,abs(sum-cur));
    if(sum==0)
    {
        return 0;
    }
    if(n==0)
    {
        return arr[0];
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    int nottake=rec(n-1,arr,cur,sum,mn,dp);
    int take=rec(n-1,arr,cur+arr[n],sum-arr[n],mn,dp);
    return dp[n][sum]=mn;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=0;i<n;i++)
    {
        dp[i][arr[i]]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            bool take=false;
            bool nottake=dp[i-1][j];
            if(arr[i]<=j)
            {
                take=dp[i-1][j-arr[i]];
            }
            dp[i][j]=take | nottake;
        }
    }
    
    int mn=100001;
    for(int i=0;i<=sum;i++)
    {
        if(dp[n-1][i]==1)
        {
            mn=min(mn,abs(i-(sum-i)));
        }
    }
    return mn;
}
