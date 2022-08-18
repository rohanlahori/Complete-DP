int tabulation(int n,vector<int> &nums)
    {
        int ans=-1;
        vector<int>dp(n+1,0);
        if(n==1)
        {
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            int mx=-1;
            for(int j=0;j<i-1;j++)
            {
                mx=max(mx,nums[i]+dp[j]);
            }
            dp[i]=mx;
        }
        for(int i=0;i<n;i++)
        {
           ans=max(ans,dp[i]);
        }
        return ans;
    }
