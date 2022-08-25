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
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    int mn=100001;
    return rec(n-1,arr,0,sum,mn,dp);
}
