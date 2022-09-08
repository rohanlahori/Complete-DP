int rec(int l,int r,string &s,vector<vector<int>> &dp)
{
    if(l>r){
        return 0;
    }
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    if(s[l]==s[r]){
        return dp[l][r]=rec(l+1,r-1,s,dp);
    }
    else{
        int pr=rec(l+1,r,s,dp);
        int su=rec(l,r-1,s,dp);
        return dp[l][r]=min(1+su,1+pr);
    }
}
int minInsertions(string s) {
    int n=s.length();
    vector<vector<int>>dp(n+500,vector<int>(n+500,-1));
    return rec(0,n-1,s,dp);
}
