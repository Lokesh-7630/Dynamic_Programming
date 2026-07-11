class Solution {
public:
int fn(int ind,int buy,vector<int>& prices,int n, vector<vector<int>>&dp){
    if(ind==n)return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    long profit=0;
    if(buy){
       profit=max(-prices[ind]+fn(ind+1,0,prices,n,dp),0+fn(ind+1,1,prices,n,dp));
    }else{
        profit=max(prices[ind]+fn(ind+1,1,prices,n,dp),0+fn(ind+1,0,prices,n,dp));
    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
       
        int n=prices.size();
         vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(0,1,prices,n,dp);
    }
};