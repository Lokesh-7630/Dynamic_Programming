class Solution {
public:

void dfs(vector<vector<int>>& grid,int r,int c){
    int m=grid.size();
int n=grid[0].size();
    if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==1){
        return;
    }
    grid[r][c]=1;
    dfs(grid,r-1,c);
    dfs(grid,r,c+1);
    dfs(grid,r+1,c);
    dfs(grid,r,c-1);
}
    int closedIsland(vector<vector<int>>& grid) {
        int count=0;
  int m=grid.size();
int n=grid[0].size();
for(int i=0; i<n; i++){
    if(grid[0][i]==0) dfs(grid,0,i);
    if(grid[m-1][i]==0) dfs(grid,m-1,i);
}for(int j=0; j<m; j++){
    if(grid[j][0]==0) dfs(grid,j,0);
    if(grid[j][n-1]==0) dfs(grid,j,n-1);
}
for(int r=1; r<m-1; r++){
    for(int c=1; c<n-1; c++){
        if(grid[r][c]==0){
            count++;
            dfs(grid,r,c);
        }
    }
}
return count;
    }
};