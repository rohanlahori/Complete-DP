int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int pref=0;
        for(int i=0;i<m;i++)
        {
            pref+=grid[0][i];
            dp[0][i]=pref;
        }
        pref=0;
        for(int i=0;i<n;i++)
        {
            pref+=grid[i][0];
            dp[i][0]=pref;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dp[n-1][m-1];}
