
int rec(int n,vector<int> &weight,vector<int> &val,int k,vector<vector<int>> &dp)
{
    if(n==-1)
    {
        return 0;
    }
    if(dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    int nottake=rec(n-1,weight,val,k,dp);
    int take=0;
    if(weight[n]<=k)
    {
        take=val[n]+rec(n-1,weight,val,k-weight[n],dp);
    }
    return dp[n][k]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    int k=maxWeight;
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return rec(n-1,weight,value,k,dp);
}
