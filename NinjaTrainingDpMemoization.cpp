#include<bits/stdc++.h>
int rec(int n,vector<vector<int>> &points,int day,vector<vector<int>> &dp)
{
    if(n==0){
        return points[n][day];
    }
    if(dp[n][day]!=-1)
    {
        return dp[n][day];
    }
    vector<int>dx{1,-1,-2};
    vector<int>dy{2,1,-1};
    int pts=points[n][day];
    int day1=day+dx[day];
    int day2=day+dy[day];    
    int ps=pts+rec(n-1,points,day1,dp);
    int ps1=pts+rec(n-1,points,day2,dp);
    return dp[n][day]=max(ps,ps1);
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1, vector<int>(4,-1));
    return max({rec(n-1,points,0,dp),rec(n-1,points,1,dp),rec(n-1,points,2,dp)});
}
