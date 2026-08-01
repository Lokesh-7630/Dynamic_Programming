class Solution {
public:
    int solve(int i,int j,vector<int>& nums, vector<vector<int>>&dp){
        if(i==j) return nums[i];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int takeleft=nums[i]-solve(i+1,j,nums,dp);
        int takeright=nums[j]-solve(i,j-1,nums,dp);
        dp[i][j]= max(takeleft,takeright);
        return dp[i][j];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=solve(0,n-1,nums,dp);
        if(ans>=0){
            return true;
        }else{
            return false;
        }
    }
};