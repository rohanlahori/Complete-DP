 int rec(int n,int m,string &s,string &s1,vector<vector<int>> &dp)
{
    if(m==-1)
    {
        return n+1;
    }
    if(n==-1)
    {
        return m+1;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s[n]==s1[m])
    {
//     When both the character of the string matches we don't need to do any operation in that situation
        return dp[n][m]=rec(n-1,m-1,s,s1,dp);
    }
    else{

//          When both the character does not match, 
//          3 possible states insert, replace, delete:
        return dp[n][m]=1+min({rec(n,m-1,s,s1,dp),rec(n-1,m-1,s,s1,dp),rec(n-1,m,s,s1,dp)});
    }
}
int minDistance(string word1, string word2) {
    string s=word1;
    string s1=word2;
    int n=s.length();
    int m=s1.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return rec(n-1,m-1,s,s1,dp);
}
