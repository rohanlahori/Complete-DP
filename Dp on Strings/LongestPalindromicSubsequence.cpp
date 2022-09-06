int rec(string &s1,int l,int r,vector<vector<int>> &dp)
{
    if(l>r){
        return 0;
    }
    if(l==r){
        return 1;
    }
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    if(s1[l]==s1[r]){
        return dp[l][r]=2+rec(s1,l+1,r-1,dp);
    }
    else{
        return dp[l][r]=max(rec(s1,l+1,r,dp),rec(s1,l,r-1,dp));
    }
}
int longestPalindromeSubseq(string s) {
    int l=0;
    int r=s.length();
    int n=s.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return rec(s,l,r-1,dp);
}
