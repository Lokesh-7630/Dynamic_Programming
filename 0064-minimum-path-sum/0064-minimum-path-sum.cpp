class Solution {
public:
    int fn(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
          if(i>m-1 || j>n-1) return 1e9;
          if(i==m-1 && j==n-1) return grid[i][j];
          if(dp[i][j] != -1){
            return dp[i][j];
          }
          
                int right=grid[i][j] + fn(i,j+1,m,n,grid,dp);
                int bottom=grid[i][j] + fn(i+1,j,m,n,grid,dp);
              return  dp[i][j]=min(right,bottom);
             
          
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn(0,0,m,n,grid,dp);
    }
};