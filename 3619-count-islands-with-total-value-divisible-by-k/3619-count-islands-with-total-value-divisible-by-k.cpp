class Solution {
public:
   long long dfs(int row,int col,vector<vector<int>>& grid,int m,int n){
           long long sum=grid[row][col];
              grid[row][col]=0;
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nr=row+drow[i];
                int nc=col+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>0){
                  
                    sum+=dfs(nr,nc,grid,m,n);
                }
            }
            return sum;
        }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size(); 
        int validIslandsCount = 0;
     
     for(int r=0; r<m; r++){
        for(int c=0; c<n; c++){
            if(grid[r][c]>0){
                long long islandTotalVal=dfs(r,c,grid,m,n);
                if(islandTotalVal%k==0){
                    validIslandsCount++;
                }
            }
        }
     }
     return validIslandsCount;
    }
};