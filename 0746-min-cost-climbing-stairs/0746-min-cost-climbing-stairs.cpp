class Solution {
public:
    int f(int i,vector<int>& cost,vector<int>&dp){
        if(i==0 || i==1) return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        int left=f(i-1,cost,dp)+cost[i-1];
        int right=INT_MAX;
        if(i>1) right=f(i-2,cost,dp)+cost[i-2];
        return dp[i]=min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
      
        return f(n,cost,dp);
    }
};