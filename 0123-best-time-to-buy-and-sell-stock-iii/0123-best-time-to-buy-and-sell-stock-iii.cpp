class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp size depend on no. of changing parameter
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // for(int i=0; i<n; i++){
        //     for(int buy=0; buy<=1; buy++){
        //         if(int cap==0){
        //             dp[i][buy][0]=0;
        //         }
        //     }
        // }
        // for(int buy=0; buy<=1; buy++){
        //     for(int cap=0; cap<=2; cap++){
        //         if(int i==n){
        //             dp[n][buy][cap]=0;
        //         }
        //     }
        // }
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy==1){
                         dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],
                                                 0+dp[i+1][1][cap]);
                    }else{
                         dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],
                                               0+dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};